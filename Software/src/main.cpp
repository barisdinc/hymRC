#include <Arduino.h>
#include <EEPROMex.h>
#include "main.h"

volatile int interrupts;

uint8_t dtmf;
uint8_t dtmf_cnt;

Repeater_configutarion_t repeater_configuration;




void dtmf_interrupt();
void squelch_interrupt();
void init_configuration(Repeater_configutarion_t* config);


void setup() {
    noInterrupts();

    init_configuration(&repeater_configuration);

    TCCR1A = 0; 
    TCCR1B = 0;
    TCNT1 = 15624; // 1Hz = 16.000.000 / (1024 * 1) - 1
    TCCR1B |= (1 << CS12); //256 prescaler
    TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt

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

    


    Serial.begin(9600);
    Serial.println("hymRC Repeater Contoller (TA7W/OH2UDS-2021)");
    interrupts();

}

void loop() {



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
  config->tx_tail_s = txtail_s;
  config->user_password[0] = 1;
  config->user_password[1] = 4;
  config->user_password[2] = 6;
  config->user_password[3] = 1;
  config->admin_password[0] = 0;
  config->admin_password[1] = 6;
  config->admin_password[2] = 6;
  config->admin_password[3] = 6;
  
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
  dtmf = (PIND & 0x00F0) >> 4;
  dtmf_cnt++;
  Serial.println(dtmf);
}


/*
 * Squelch State Change Interrupt Function
 */
void squelch_interrupt() {
  uint8_t sql_state = digitalRead(squelch_in_pin);
  Serial.print("SQUELCH state changed to : ");
  Serial.println(sql_state);

  if (sql_state == SQL_OPEN_LEVEL)
  {
    digitalWrite(ptt_pin, HIGH);
  }
  else
  {
    Serial.println("reseetting");
    noInterrupts();
    TCNT1 = 15624;   // preload timer
    TIMSK1 |= (1 << TOIE1); //Enable Timer Overflow Interrupt
    interrupts();
  }
  
}



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