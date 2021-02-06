#include <Arduino.h>
#include <EEPROMex.h>
#include "main.h"


uint8_t dtmf;
uint8_t dtmf_;

Repeater_configutarion_t repeater_configuration;




void dtmf_interrupt();
void init_configuration(Repeater_configutarion_t* config);


void setup() {
    attachInterrupt(0, dtmf_interrupt, FALLING);
    pinMode(LED_BUILTIN, OUTPUT);

    pinMode(dtmf_pinSTD, INPUT);
    pinMode(dtmf_pinQ1, INPUT);
    pinMode(dtmf_pinQ2, INPUT);
    pinMode(dtmf_pinQ3, INPUT);
    pinMode(dtmf_pinQ4, INPUT);

    init_configuration(&repeater_configuration);


    Serial.begin(9600);
    Serial.println("hymRC Repeater Contoller (TA7W/OH2UDS-2021)");

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
  config->tx_tail_ms = txtail_ms;
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
 * Port Change Interrupt Function
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
