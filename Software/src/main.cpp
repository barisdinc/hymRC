#include <Arduino.h>
#include <EEPROMex.h>
#include "main.h"

/*
 DTMF Commands start with # and end with *
 After the # command all codes should be send within command_timeout_s seconds
 The maximum delay between digits can be maximum dtmf_timout_s seconds
 Every presence of # restarts the command sequence

 Command Structure is as follows (PPPP is required user/admin password)
 #PPPPCC*        Execute CC command 
 #PPPPSSVV*      Set SS variable value to VV 

 #PPPP71pppp*    Set user password to ppp
 #PPPP72pppp*    Set admin password to ppp
*/


volatile int interrupts;

uint8_t dtmf_cnt;
char dtmf_command[20];

Repeater_configutarion_t repeater_configuration;

unsigned long timer_stop_tx;  
unsigned long timer_command_timeout;
unsigned long timer_dtmf_timeout;
 
bool execute_cmd = false;
bool tx_state = false;


void setup() {
    noInterrupts();

    init_configuration(&repeater_configuration);

    //TCCR1A = 0; 
    //TCCR1B = 0;
    //TCNT1 = 15624; // 1Hz = 16.000.000 / (1024 * 1) - 1
    //TCCR1B |= (1 << CS12); //256 prescaler
    //TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt

    attachInterrupt(0, dtmf_interrupt, FALLING); //Interrupt0 is Pin D2, FAILING edge shows dtmf read is done
    attachInterrupt(1, squelch_interrupt, CHANGE); //Interrupt1 is Pin D3, CHANGE triggers state change
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(squelch_in_pin, INPUT_PULLUP);
    pinMode(ptt_pin, OUTPUT);

    pinMode(dtmf_pinSTD, INPUT);
    pinMode(dtmf_pinQ1, INPUT);
    pinMode(dtmf_pinQ2, INPUT);
    pinMode(dtmf_pinQ3, INPUT);
    pinMode(dtmf_pinQ4, INPUT);

    pinMode(digital_out_1, OUTPUT);

    
    Serial.begin(9600);
    Serial.println("hymRC Repeater Contoller (TA7W/OH2UDS-2021)");
    interrupts();

}

void loop() {

  unsigned long current_time = millis();

  if (( current_time >= timer_stop_tx ) && ( tx_state == true )) 
  {
    Serial.println("wait RX Tail"); 
    change_ptt_state(false);
    tx_state = false;
  }

  if (execute_cmd == true)
  {
    if (check_password() == true)
    {
      Serial.println("Password OK");
      exec_command();
    }
    else
    {
      Serial.println("Wrong password");
    }
  execute_cmd = false;
  }


}


/*
 * Initialize repeater configuration woth default paramaters if no data in EEPROM,
 * If data in EEPROM then use that information for initialization
 * input: 
 * configuration : pointer to repeater configuration to be updated
 * 
 * output: 
 * -
 */
void init_configuration(Repeater_configutarion_t* config)
{
  // TODO: read default values from EEPROM
  config->state = REPEATER_ON; 
  config->beaconmode = BEACON_NONE;
  config->tx_tail_s = txtail_ms;
  config->user_password = 0x1461;
  config->admin_password = 0x0666;
  
}


/*
 * DTMF Read on STD FAILING Edge Interrupt Function
 * D2 port is the interrupt pin connected to StD output of MT3170/8870 which goes high/low after a DTMF reception
 * D4 is MT3170/8870 Q1
 * D5 is MT3170/8870 Q2
 * D6 is MT3170/8870 Q3
 * D7 is MT3170/8870 Q4
 */
void dtmf_interrupt() {
  uint8_t dtmf_digit = (PIND & 0x00F0) >> 4;
  if ((dtmf_digit != 12) && (dtmf_cnt == 0)) return;
  if ( dtmf_digit == 12) dtmf_cnt = 0; //# digit restarts the sequence
  if ((dtmf_digit == 11) && (dtmf_cnt >= 7)) execute_cmd = true;
  dtmf_command[dtmf_cnt] = dtmf_digit;
  dtmf_cnt++;
  //Serial.println(millis());
  timer_command_timeout = millis() + command_timeout_ms;
  timer_dtmf_timeout = millis() + dtmf_timeout_ms;
}


/*
 * Squelch State Change Interrupt Function
 */
void squelch_interrupt() {
  uint8_t sql_state = digitalRead(squelch_in_pin);
  //Serial.println(sql_state);
  if (sql_state == SQL_OPEN_LEVEL)
  {
    Serial.println("SQL ON");
    change_ptt_state(true);
    timer_stop_tx = millis() + txtimemout_timer_ms;
    tx_state = true;
  }
  else
  {
    timer_stop_tx = millis() + txtail_ms;
    //noInterrupts();
    //TCNT1 = 15624;   // preload timer
    //TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt
    //interrupts();
  }
  
}


/*
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
	//TCNT1 = 15624;   // preload timer
  
	interrupts++;
	if ((interrupts >= repeater_configuration.tx_tail_s) && digitalRead(squelch_in_pin))
  {
    digitalWrite(ptt_pin, LOW);
    TIMSK1 &= ~(1 << TOIE1);
    interrupts = 0;
  }
}

*/


/*
 * Check the password that is in dtmf_command[1][2][3][4] bytes
 * and compare with repeater configuration user or admin password
 * return:
 * true if passwords match
 */

bool check_password()
{
  uint16_t passwd = (dtmf_command[1] << 12) + (dtmf_command[2] << 8) + (dtmf_command[3] << 4) + dtmf_command[4];
  if ((passwd == repeater_configuration.admin_password) || (passwd == repeater_configuration.user_password)) return true;
  return false;
}


/*
 * Executes the command stored if dtmf_command[5][6]
 */

void exec_command()
{
  uint8_t repeater_command  = (dtmf_command[5] << 4) + dtmf_command[6];
  bool cmd_valid = true;
  switch(repeater_command)
  {
    case COMMAND_REPEATER_ON:
      repeater_configuration.state = REPEATER_ON;
      Serial.println("REPEATER ON");
      break;
    case COMMAND_REPEATER_OFF:
      repeater_configuration.state = REPEATER_OFF;
      Serial.println("REPEATER OFF");
      break;
    case COMMAND_BEACON_ON:
     Serial.println("BEACON ON");
      repeater_configuration.beaconmode = BEACON_MORSE;
      break;
    case COMMAND_BEACON_OFF:
      Serial.println("BEACON OFF");
      repeater_configuration.beaconmode = BEACON_NONE;
      break;
    case COMMAND_DIGITAL1_ON:
      Serial.println("FAN ON");
      digitalWrite(digital_out_1, HIGH);
      break;
    case COMMAND_DIGITAL1_OFF:
      Serial.println("FAN OFF");
      digitalWrite(digital_out_1, LOW);
      break;

    default:
      //Invalid Command
      cmd_valid = false;
  }

  if (cmd_valid)
  {
      //TODO : respond with no_error tone
  }
  else
  {
      //TODO : respond with error tone
  }
}



/*
 * Changes PTT pin state using the ON/OFF hig/low level definitions and port definitions
 * Also checks repeater state for triggering PTT_ON
 */

void change_ptt_state(bool state)
{
if (state)
{
  if (repeater_configuration.state == REPEATER_ON)
  {
    digitalWrite(ptt_pin, HIGH);
    Serial.println("PTT On");
  }
  else
  {
    Serial.println("REPEATER is off... no TX");
  }
}
else
{
  digitalWrite(ptt_pin, LOW);
  Serial.println("PTT Off");
}
}