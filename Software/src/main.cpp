#include <Arduino.h>
//#include <EEPROM.h>
#include <Wire.h>
#include <mcp23017.h>
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

MCP23017 mcp(/*addr =*/MCP23017_ADDR);//constructor, change the Level of A2, A1, A0 for I2C address within 0x20~0x27
bool intFlag = false;//INTA and/or INTB interrupt sign

/*Interrupt service function, prototype void func(int index), index represents the pin which is interrupted*/
void gpaCB(int index){
  /*pinDescription function is used to convert a pin into string description
  Parameter pin, the available parameter is shown below:
  eGPA0  eGPA1  eGPA2  eGPA3  eGPA4  eGPA5  eGPA6  eGPA7  eGPA
   0       1      2      3      4      5      6      7
  eGPB0  eGPB1  eGPB2  eGPB3  eGPB4  eGPB5  eGPB6  eGPB7  eGPB
   8       9      10     11     12     13     14     15
  */
  // String description = mcp.pinDescription(index);
  // Serial.print(description);
  Serial.println(" Interruption occurs!");
}

void gpbCB(int index){
  // String description = mcp.pinDescription(index);
  // Serial.print(description);
  Serial.println(" Interruption occurs!");
}

void notifyINT(){
  intFlag = true;
  Serial.println("I");
}


void setup() {
    // noInterrupts();

    // init_configuration(&repeater_configuration);

    //TCCR1A = 0; 
    //TCCR1B = 0;
    //TCNT1 = 15624; // 1Hz = 16.000.000 / (1024 * 1) - 1
    //TCCR1B |= (1 << CS12); //256 prescaler
    //TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt

    // attachInterrupt(0, dtmf_interrupt, FALLING); //Interrupt0 is Pin D2, FAILING edge shows dtmf read is done
    // attachInterrupt(1, squelch_interrupt, CHANGE); //Interrupt1 is Pin D3, CHANGE triggers state change
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(squelch_in_pin, INPUT_PULLUP);
    pinMode(ptt_pin, OUTPUT);

    pinMode(mcp_intpin, INPUT); //interrupt0

    pinMode(dtmf_pinQ1, INPUT);
    pinMode(dtmf_pinQ2, INPUT);
    pinMode(dtmf_pinQ3, INPUT);
    pinMode(dtmf_pinQ4, INPUT);

    pinMode(digital_out_1, OUTPUT);

    

    Wire.begin();
    // configure_mcp23017(); // IO Extender configuration

    Serial.begin(9600);
    Serial.println("hymRC Repeater Contoller (TA7W/OH2UDS-2021)");

    /*wait for the chip to be initialized completely, and then exit*/
    if (!mcp.begin())
      Serial.println("MCP23017 init failed!");
    Serial.println("MCP23017 Initialized");

    /*pinModeInterrupt function is used to set pin to interrupt mode, and the pin will be automatically set to input mode.
    Parameter pin, the available parameter is showm below:
    eGPA0  eGPA1  eGPA2  eGPA3  eGPA4  eGPA5  eGPA6  eGPA7  eGPA
    0       1      2      3      4      5      6      7
    eGPB0  eGPB1  eGPB2  eGPB3  eGPB4  eGPB5  eGPB6  eGPB7  eGPB
    8       9      10     11     12     13     14     15
    Parameter mode, the available parameter is shown below:
    eLowLevel              eHighLevel              eRising                eFalling                  eChangeLevel
    Low-level interrupt    High-level interrupt    Rising edge interrupt  Falling edge interrupt    Double edge interrupts 
    Parameter cb interrupt service function(with parameter)
    Prototype void func(int)
    */

    mcp.pinMode(GPB5, INPUT);
    mcp.pullUp(GPB5, true);  // Enable pull-up
    mcp.pinMode(GPB6, INPUT);
    mcp.pullUp(GPB6, true);  // Enable pull-up
    mcp.pinMode(GPB7, INPUT);
    mcp.pullUp(GPB7, true);  // Enable pull-up

    mcp.pinMode(/*pin = */GPA0, /*mode = */OUTPUT);
    mcp.digitalWrite(GPA0, LOW);
    mcp.pinMode(/*pin = */GPA1, /*mode = */OUTPUT);
    mcp.digitalWrite(GPA1, LOW);
    mcp.pinMode(/*pin = */GPA2, /*mode = */OUTPUT);
    mcp.digitalWrite(GPA2, LOW);
    mcp.pinMode(/*pin = */GPA3, /*mode = */OUTPUT);
    mcp.digitalWrite(GPA3, LOW);
    mcp.pinMode(/*pin = */GPA4, /*mode = */OUTPUT);
    mcp.digitalWrite(GPA4, LOW);

    // mcp.pinMode(/*pin = */mcp.eGPB3, /*mode = */OUTPUT);
    // mcp.pinMode(/*pin = */mcp.eGPB4, /*mode = */OUTPUT);
    // mcp.pinMode(/*pin = */mcp.eGPB5, /*mode = */OUTPUT);
    // mcp.pinMode(/*pin = */mcp.eGPB6, /*mode = */OUTPUT);
    // mcp.pinMode(/*pin = */mcp.eGPB7, /*mode = */OUTPUT);

    // Enable interrupt on change for GPB5,6,7
    mcp.enableInterrupt(GPB5, STATE_CHANGE, LOW);  // Interrupt if pin state  change
    mcp.enableInterrupt(GPB6, STATE_CHANGE, LOW);  // Interrupt if pin state  change
    mcp.enableInterrupt(GPB7, STATE_CHANGE, LOW);  // Interrupt if pin state  change
    // mcp.enableInterrupt(GPB0, STATE_CHANGE, LOW);  // Interrupt if pin state not matched

    attachInterrupt(/*Interrupt NO*/0,notifyINT,RISING);//Enable external interrupt 0, connect INTA to the main-controller's digital pin: UNO(2)
    // attachInterrupt(/*Interrupt NO*/1,notifyB,RISING);//Enable external interrupt 1, connect INTB to the main-controller's digital pin: UNO(3)

    // interrupts();

}


void loop() {

  // unsigned long current_time = millis();

  // Serial.println("HymRC started");

bool clearFlag = false;

  while (1)
  {


  // Check if button triggered interrupt
    if (mcp.getInterrupt(GPB5)) {
      Serial.println("Interrupt Detected on Button5!");
      clearFlag = true;
    }
    if (mcp.getInterrupt(GPB6)) {
      Serial.println("Interrupt Detected on Button6!");
      clearFlag = true;
    }
    if (mcp.getInterrupt(GPB7)) {
      Serial.println("Interrupt Detected on Button7!");
      clearFlag = true;      
    }

    if (clearFlag == true) mcp.clearInterrupt();  // Clear interrupt flags


  // delay(1000);

      if(intFlag){
        intFlag = false;
        /*pollInterrupts function is used to poll if an interrupt occurs on a port group 
        parameter group, the available parameter is shown below: (default value: eGPIOALL)：
        eGPIOA        eGPIOB         eGPIOALL
        Port groupA  Port groupB   Port groupA+B
        */
        mcp.togglePin(GPA0);
        mcp.togglePin(GPA1);
        mcp.togglePin(GPA2);
        mcp.togglePin(GPA3);
        mcp.togglePin(GPA4);
    }

      // mcp.digitalWrite(/*pin = */mcp.eGPA0, /*level = */HIGH);
      // mcp.digitalWrite(/*pin = */mcp.eGPA1, /*level = */HIGH);
      // mcp.digitalWrite(/*pin = */mcp.eGPA2, /*level = */HIGH);
      // mcp.digitalWrite(/*pin = */mcp.eGPA3, /*level = */HIGH);
      // mcp.digitalWrite(/*pin = */mcp.eGPA4, /*level = */HIGH);
      // digitalWrite(LED_BUILTIN, HIGH);

      // delay(1500);
  
      // mcp.digitalWrite(/*pin = */mcp.eGPA0, /*level = */LOW);
      // mcp.digitalWrite(/*pin = */mcp.eGPA1, /*level = */LOW);
      // mcp.digitalWrite(/*pin = */mcp.eGPA2, /*level = */LOW);
      // mcp.digitalWrite(/*pin = */mcp.eGPA3, /*level = */LOW);
      // mcp.digitalWrite(/*pin = */mcp.eGPA4, /*level = */LOW);      
      // digitalWrite(LED_BUILTIN, LOW);

      // delay(1500);
      // Serial.print(".");

    // uint8_t currentB;

    // currentB = mcp.readPort(MCP23017Port::B);


  }

  // if (( current_time >= timer_stop_tx ) && ( tx_state == true )) 
  // {
  //   Serial.println("wait RX Tail"); 
  //   change_ptt_state(false);
  //   tx_state = false;
  // }

  // if (execute_cmd == true)
  // {
  //   if (check_password() == true)
  //   {
  //     Serial.println("Password OK");
  //     exec_command();
  //   }
  //   else
  //   {
  //     Serial.println("Wrong password");
  //   }
  // execute_cmd = false;
  // }


}


// /*
//  * Initialize repeater configuration woth default paramaters if no data in EEPROM,
//  * If data in EEPROM then use that information for initialization
//  * input: 
//  * configuration : pointer to repeater configuration to be updated
//  * 
//  * output: 
//  * -
//  */
// void init_configuration(Repeater_configutarion_t* config)
// {
//   // TODO: read default values from EEPROM
//   config->state = REPEATER_ON; 
//   config->beaconmode = BEACON_NONE;
//   config->tx_tail_s = txtail_ms;
//   config->user_password = 0x1461;
//   config->admin_password = 0x0666;
  
// }

//   digitalWrite(LED_BUILTIN, LOW);
// /*
//  * DTMF Read on STD FAILING Edge Interrupt Function
//  * D2 port is the interrupt pin connected to StD output of MT3170/8870 which goes high/low after a DTMF reception
//  * D4 is MT3170/8870 Q1
//  * D5 is MT3170/8870 Q2
//  * D6 is MT3170/8870 Q3
//  * D7 is MT3170/8870 Q4
//  */
// void dtmf_interrupt() {
//   uint8_t dtmf_digit = (PIND & 0x00F0) >> 4;
//   if ((dtmf_digit != 12) && (dtmf_cnt == 0)) return;
//   if ( dtmf_digit == 12) dtmf_cnt = 0; //# digit restarts the sequence
//   if ((dtmf_digit == 11) && (dtmf_cnt >= 7)) execute_cmd = true;
//   dtmf_command[dtmf_cnt] = dtmf_digit;
//   dtmf_cnt++;
//   //Serial.println(millis());
//   timer_command_timeout = millis() + command_timeout_ms;
//   timer_dtmf_timeout = millis() + dtmf_timeout_ms;
// }


// /*
//  * Squelch State Change Interrupt Function
//  */
// void squelch_interrupt() {
//   uint8_t sql_state = digitalRead(squelch_in_pin);
//   //Serial.println(sql_state);
//   if (sql_state == SQL_OPEN_LEVEL)
//   {
//     Serial.println("SQL ON");
//     change_ptt_state(true);
//     timer_stop_tx = millis() + txtimemout_timer_ms;
//     tx_state = true;
//   }
//   else
//   {
//     timer_stop_tx = millis() + txtail_ms;
//     //noInterrupts();
//     //TCNT1 = 15624;   // preload timer
//     //TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt
//     //interrupts();
//   }
  
// }


// /*
// ISR(TIMER1_OVF_vect)        // interrupt service routine 
// {
// 	//TCNT1 = 15624;   // preload timer
  
// 	interrupts++;
// 	if ((interrupts >= repeater_configuration.tx_tail_s) && digitalRead(squelch_in_pin))
//   {
//     digitalWrite(ptt_pin, LOW);
//     TIMSK1 &= ~(1 << TOIE1);
//     interrupts = 0;
//   }
// }

// */


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


/*
 * register_write(register, value) is used for writing value to
 * a register using I2C wire bus
 * 
 */

void register_write(uint8_t register_address, uint8_t register_value )
{
  Wire.beginTransmission(MCP23017_ADDR);
  Wire.write(register_address);
  Wire.write(register_value);
  Wire.endTransmission();
}

/*
 * Initial configuration of MCP23017 16 Bit I/O Extender
 * I2C communication address is set in header as 0x20 MCP23017_ADDR
 * 
 * A0
 * A1
 * A2
 * A3
 * A4
 * A5
 * A6
 * A7
 * A8
 * 
 * B0 MT8870 Q1       (input) Interrupt On Pin
 * B1 MT8870 Q2       (input) Interrupt On Pin
 * B2 MT8870 Q3       (input) Interrupt On Pin
 * B3 MT8870 Q4       (input) Interrupt On Pin
 * B4 MT8870 StD      (input) Interrupt On Change 
 * B5 General Purpose (input) No Interrupt
 * B6 General Purpose (input) No Interrupt
 * B7 General Purpose (input) No Interrupt
 * 
 * INTA -> Pin 2 of MCU (INT0)
 * INTB -> Pin 3 of MCU (INT1)
 * 
 */

void configure_mcp23017()
{
                                    // Configure Port_A
                                    // (Register 0x00 : IODIRA)   Direction Configuration
  register_write(0x00,0x00);//FF);        //                            set all of port A to inputs
                                    // (Register 0x02 : IPOLA)    Input Polarity
  register_write(0x02,0x00);        //                            All pins reflect the same logic state (0)
                                    // (Register 0x04 : GPINTENA) Interrupt On Change Control
  register_write(0x04,0b00000000);//1000);  //                            Only StD pin of MT8870 will have on-change int
                                    // (Register 0x06 : DEFVALA)  Default Compare Interrupt
  register_write(0x06,0b00000000);//0b11110000);  //                            Q1-Q4 pins of MT8870 will have default-state of 1
                                    // (Register 0x06 : INTCONA)  Default Compare Interrupt
  register_write(0x08,0b00000000);//11110000);  //                            Q1-Q4 pins of MT8870 will have default-compare int
                                    // (Register 0x0A : IOCONA)   Configuration Register 
  register_write(0x0A,0b10100110);//010);  // bit-7 (1) BANK:   The registers associated with each port are separated into different banks.
                                    // bit-6 (0) MIRROR: The INT pins are not connected. INTA is PORTA and INTB is associated with PORTB
                                    // bit-5 (1) SEQOP:  Sequential operation disabled, address pointer does not increment.
                                    // bit-4 (0) DISSLW: Slew rate enabled
                                    // bit-3 (0) HAEN:   Disables the MCP23S17 address pins.
                                    // bit-2 (0) ODR:    Active driver output (INTPOL bit sets the polarity.)
                                    // bit-1 (1) INTPOL: Active-high
                                    // bit-0 (0) -

                                    // Configure Port_B
                                    // (Register 0x01 : IODIRB)   Direction Configuration
  register_write(0x01,0xFF);//00);        //                            set all of port B to outputs
                                    // (Register 0x03 : IPOLB)    Input Polarity
  register_write(0x03,0x00);        //                            All pins reflect the same logic state (0)
                                    // (Register 0x05 : GPINTENB) Interrupt On Change Control
  register_write(0x05,0b00001000);  //                            No pin will have on-change int
                                    // (Register 0x07 : DEFVALB)  Default Compare Interrupt
  register_write(0x07,0b00000000);  //                            All pins will have default-state of 0 (output pins)
                                    // (Register 0x09 : INTCONB)  Default Compare Interrupt
  register_write(0x09,0b00000000);  //                            No pins will have default-compare int (output pins)
                                    // (Register 0x0B : IOCONB)   Configuration Register 
  register_write(0x0B,0b10100010);  // bit-7 (1) BANK:   The registers associated with each port are separated into different banks.
                                    // bit-6 (0) MIRROR: The INT pins are not connected. INTA is PORTA and INTB is associated with PORTB
                                    // bit-5 (1) SEQOP:  Sequential operation disabled, address pointer does not increment.
                                    // bit-4 (0) DISSLW: Slew rate enabled
                                    // bit-3 (0) HAEN:   Disables the MCP23S17 address pins.
                                    // bit-2 (0) ODR:    Active driver output (INTPOL bit sets the polarity.)
                                    // bit-1 (1) INTPOL: Active-high
                                    // bit-0 (0) -
}
