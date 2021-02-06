#include <Event.h>
#include <Timer.h>


// ==========================================================================
//
//        Repeater software for ARDUINO UNO
//       Magic Valley Amateur Radio Club Twin Falls Idaho
//       version 4.2 dated April 10, 2015 tested and debugged dwe
//        version 4.4 dated Apr 16, 2016  totally tested and debugged.  dwe
//         version 4.41 dated Sep 12, 2012 improved notes and comments.  dwe
//===========================================================================
// "Repeater logic" by Daniel Forsstrom - SM4XAS- www.forsstrommusic.se
// NOTE: I used only Daniel's Morse Code encoder functions - The repeater logic in mine. Dean, KI7CC
// ==========================================================================
//===========================================================================
/*  DEAN ETHERINGTON Notes:
 1.The COS "receiver squelch" is the main control trigger input signal.   When the COS has not been active
 for 15 or more seconds, and then goes ACTIVE,  the controller will "key up" PTT, and send the Call Sign.
 2. After COS ACTIVE, the cwid timer starts timing for "CWID TIM" seconds. After CWID timeout, the repeater will send your
 Call Sign,  and reset the CWID Timer.
 3. If  the COS signal remains active  for more than the "T_out" seconds, a timeout will occour that will shut
 down the PTT signnal and termininate transmissions until after the COS signal goes inactive again. Any CWID event during a "Timeout"
 event will transmit your Call Sign (800 HZ tone) and also  "TIME OUT" in Morse Code(1000 HZ tone).
 4. Aditional external audio circuits must be added to mix the CWID Morse Code out of PIN 5,
 and the receiver's audio,  before passing the audio to the transmitter.
 5. The PTT out signal should have a transister buffer to protect the microprocessor output  pin.
 If the PTT drives a relay - you also need a protection diode for reverse emf voltages.
 The  PTT signal into the transmitter is usually active LOW.  Here I would use a transistor (or FET)
 to pull the PTT line LOW.
 6.  If your radio's output signals for COS and TPL are greater than 5 VDC, use diodes to protect the Arduino inputs.
 Connect the negative end of a diode to the Radio's output signal, and the positive end of the diode to the
 Arduino input pin.  The Radio's output signals will then pull the Arduino inputs "LOW" (when the signal is  "low")
 to interface with the controller.
 The diodes will limit the input signals to the 5 VDC "input pull up" value of the arduino input pin.

 NOTEs:
 1.   If your receiver does not decode TonePL (CTCSS sub audible tone), leave pin D6 unconnected and leave int TPLactive = 1.
 1a.  Some receivers combine COS and TPL into one signal.
      Connect the combined COS/TPL signal to the "COSin" pin. The correct CTCSS (TPL) settings must be programmed into your receiver.
      Do a Google Search for "CTCSS" to obtain a defination. CTCSS stands for "Continuous Tone Coded Squelch System".
 2.   Connect the UNO digital pin 2 to the MT8870D's Pin 15 ("StD").   This is the INTERRUPT Input Signal for the DTMF functions.
 3.   Use a 1 ampere MOSFET to dirve the fan output (OPEN DRAIN) from pin 12.
 4.   Enter your repeater's user variables below, starting with MorseWPM   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 5.   The DTMF Commands (RPTR on/off & TPLR on/off) are stored in the EEPROM, and read out at each power up, or Arduino RESET, during the SetUp function.
      a.Operaror_code+00 turns off the repeater (i.e.19000 until you  change the Operator_Code.)
      b.Operaror_code+01 turns on the repeater (i.e.19001 until you  change the Operator_Code.)
      c.Operatorode+02 turns Off the TPL (CTCSS) - Tone not required for access to the Repeater.(i.e.19002 until you  change the Operator_Code.)
      d.Operatorode+03 turns ON the TPL (CTCSS) Required- Tone is required for access to the Repeater.(i.e.19003 until you  change the Operator_Code.)
 6.  Importing the Libraries:  "iimer.h" search Arduino for "Master-Timer library",  "EEPROMex.h" search for EEPROMex library.   The Arduino I.D.E. help files will istruct you about importing libraries.
    //                        https://github.com/JChristensen/Timer                  // http://github.com/thijse/Arduino-Libraries/tree/master/EEPROMEx
 7.  The "Serial.print();" commands are included in the sketch for debugging use.
 //================================================================================================================================================================
//!!!!!!!!!!!!!!!!!!!!!! you MUST connect the UNO digital pin 2 (interrupt input) to the MT8870D PIN 15 "StD"  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//================================================================================================================================================================

 */


// Setup and configurational data..
// ----------------------------------------------------------------------------------------
#include "Timer.h"
#include <EEPROMex.h> //allows reading and writing nearly all types of variables to/from EEPROM.

Timer t;                //the main timer. also see onesec().

//Place YOUR User's applicable variables here!**************************************************
//**********************************************************************************************
int MorseWPM = 20;                   // The CWID Code Speed setting - Change from 20 to your desired WPM.
String MorseString = "DE NOCALL/R";    //Place your Call Sign here. (i.e. "DE WA7WNY/R")
int COSactive = 1;                   // Is your COS active High or Low? (1=High, 0=LOW)?
int TPLactive = 1;                   // Is your TPL active High or Low? (1=High, 0=LOW)? if your receiver has no CTCSS Decode, leave TPLactive = 1.
int T_out = 180;//Seconds            //timeout timer 180 Seconds - USA 180 seconds Maximum!. Change to suit your needs. To protect from "STUCK MIKE" conditions.
int CWID_TIM = 540;//Seconds         //cwid timer - 600 Seconds(10 Minutes) Maximum  - Change to suit your needs.
int FANtime = 120;//seconds          //The FAN run time variable - the time that you want to hold the fan turned on, after a transmission ends.
unsigned int Operator_Code = 190;    //The first three (3) digits of the DTMF Command codes.
//                                     For SECURITY, select your own. (i.e. your telephone prefix or anouther number that you remember).
//                                     The first digit can NOT be a ZERO!!!
//                                     only 0 thru 9 may be used, all the other characters will equate to 0(zero).
//                                     DTMF Control CODES (before changing OPERATOR_Code):   19000=Rptr OFF: 19001=Rptr ON; 19002=TPL(CTCSS) OFF; 19003=TPL(CTCSS) ON
//END of variables that the user must set**************************************************
//*****************************************************************************************


int COSin = 3;// "Key Up" signal input for the repeater ("squelch" Activity --on the repeater receiver's COS signal).
int TPLin = 6;// The PL input from receiver with TPL decode capability.  ( "CTCSS decoded" by the receiver)
int outPTT = 4;         // PTT triggering for the transmitter.
int MorseLEDPin = 13;   // flash the "MorseCOCDE CAll Sign" on a LED.
int MorseTonePin = 5;// Call Sign output in Morse Code -- 800 hz tone -- 1000 hz for "Time Out".
int fanpin = 12;
int FANgate = 0;//the fan timer gating signl.
int MorseMode = 2;
int BeaconMode = 0;
int timeout;
int fantime;
int fan = 0;
int aux = 7;
int aux1 = 8;
int cwidtimer;
int cwidTest = 9;//Ground to send test cwid.

unsigned long cmdcode = 0; //unsigned int does not work!!

unsigned int dtmf1;
int dtmftim;//dtmf entry timeout timer count.
int digit = 0;
int DIGIT = 0;//digit counter --set with dtmf interupt, reset with timer or completed action
unsigned long CMD = 0;    //unsigned int does not work!!
// ----------------------------------------------------------------------------------------


// Declare variables...
// ----------------------------------------------------------------------------------------
int RepeaterDebug = 1;          // Debug mode. 1=on, 0=off. Printing some data on Serial Monitor.
int MorseDebug = RepeaterDebug;
int COS;
int togate;    //timeout timer's gate signal.
int cwgate;    //cwid timer.s gate signal.

int cwdel;   //A delay timer to assure no call sign transmission unless the repeater was inactive before keyup.(COS inactive for 10 seconds).
int RPTR;//rptr ON.
int TPLR;//Tone Required
int TPL;//decision var for active hi/lo CTCSS.

void setup() {  // SETUP to run ONCE
  Serial.begin(9600);
  attachInterrupt(0, readDTMF, FALLING);
  DDRC = 00; // initialize the ANALOG Pins as digital pin inputs.
  Serial.println("Repeater Controller V 04.41 ");

  // Define inputs, see variable declaration for explanations.
  pinMode(COSin, INPUT_PULLUP);
  pinMode(TPLin, INPUT_PULLUP);
  pinMode(cwidTest, INPUT_PULLUP);
  pinMode(outPTT, OUTPUT);
  pinMode(MorseLEDPin, OUTPUT);
  pinMode(MorseTonePin, OUTPUT);
  pinMode(A0, INPUT);// this is declaring port c lower 4 bits as inputs for the DTMF receiver bcd code input. uno only.  *************************************
  pinMode(A1, INPUT);//                                                 port C is on different pins on the MEGA board!!
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(fanpin, OUTPUT);
  togate == 0;
  cwgate == 0;
  cwdel == 0;
  // RPTR = 1;
  // TPLR = 1;
  RPTR = EEPROM.readInt(0);//read form EEPRON at setup.
  if (RPTR < 0) {//only used if no value previously written to the EEPROM.
    RPTR = 1;
  }
  EEPROM.updateInt(0, RPTR); //initial default = 1.
  Serial.print("RPTR = "); Serial.println(RPTR);
  TPLR = EEPROM.readInt(4);//read form EEPRON at setup.
  if (TPLR < 0) {//only used if no value previously written to the EEPROM.
    TPLR = 1;
  }
  EEPROM.updateInt(4, TPLR); //initial default = 1.
  Serial.print("TPLR = "); Serial.println(TPLR);

  //================================================================================================================================================================
  //!!!!!!!!!!!!!!!!!!!!!!MUST connect the Arduino digital pin 2 ("interrupt input") to the MT8870D PIN 15 ("StD")  ""Yes pin 2  on the Uno or Mega!!!!!!!!
  //================================================================================================================================================================

  t.every(1000, onesec);    //sets the timer to pulse every 1 second. Then calls the "onesec() function".
}


// Define morse alphabet in array
char* MorseCodeAlphabet[] = {
  "A", ".-",
  "B", "-...",
  "C", "-.-.",
  "D", "-..",
  "E", ".",
  "F", "..-.",
  "G", "--.",
  "H", "....",
  "I", "..",
  "J", ".---",
  "K", "-.-",
  "L", ".-..",
  "M", "--",
  "N", "-.",
  "O", "---",
  "P", ".--.",
  "Q", "--.-",
  "R", ".-.",
  "S", "...",
  "T", "-",
  "U", "..-",
  "V", "...-",
  "W", ".--",
  "X", "-..-",
  "Y", "-.--",
  "Z", "--..",
  "0", "-----",
  "1", ".----",
  "2", "..---",
  "3", "...--",
  "4", "....-",
  "5", ".....",
  "6", "-....",
  "7", "--...",
  "8", "---..",
  "9", "----.",
  ",", "--..--",
  ".", ".-.-.-",
  "-", "-....-",
  "=", "..--..",
  "/", "-..-.",
  " ", " "
};

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
// Function to transmit morse code
// ----------------------------------------------------------------------------------------
// This program sends a text string as morse code.
//
// Syntax:
//                TransmitMorse(Mode, Message, Speed, LEDPin, TonePin, ToneFrequency, Beacon)
// Modes:
//                1 - only LED
//                2 - Both LED and Tone
//                3 - only Tone
// Message:
//                String allowed chars: A-Z 0-9 . , /! - = (space)
// Speed:
//                in WPM (words per minute, where one WORD is defined as 50 dots).
// LedPin:
//                Pin number where i.e. a LED is connected. Digital HIGH or LOW.
// TonePin:
//                Pin where a square wave tone is generated.
// ToneFrequency:
//                Frequeny of the tone generated. In Hz.
// Beacon:
//                0 - Beacon mode off.
//                1 - Beacon mode on.
//                    Transmits a long tone after message is sent.
//                    Good for radio beacons.
//
// Example:
//                TransmitMorse(2, "THIS IS A RADIO BEACON", 16, 13, 5, 800, 1);
// ----------------------------------------------------------------------------------------

void TransmitMorse(int MorseMode, String MorseString, int MorseWPM, int MorseLEDPin, int MorseTonePin, int MorseToneFreq, int BeaconMode) {



  // Calculate lengths of dash (.) and dot (-)
  int CWdot = 1200 / MorseWPM;
  int CWdash = (1200 / MorseWPM) * 3;
  // Loop once for each character in string "MorseString"
  int istr;
  for (istr = 0; istr < MorseString.length(); istr++) {
    // Get one character from MorseString at position istr
    String currentchar = MorseString.substring(istr, istr + 1);
    // Start morse encoding loop. Loop is going through all morse alphabet to compare to current character...
    int ichar = 0;
    while (ichar < sizeof(MorseCodeAlphabet)) {
      // Read current character fro(i)m morse alphabet and compare
      String currentletter = MorseCodeAlphabet[ichar];   // letter
      String currentcode = MorseCodeAlphabet[ichar + 1]; // corresponding morse code

      // Compare if current letter from morse alphabet is the one we are looking for...
      if (currentletter.equalsIgnoreCase(currentchar)) {

        // Start loop to send dashs (-) and dots (.)
        int icp = 0;
        for (icp = 0; icp < currentcode.length(); icp++) {
          // Transmit dot ?
          if (currentcode.substring(icp, icp + 1).equalsIgnoreCase(".")) {
            // Depending om Mode, what to transmit?
            if (MorseMode <= 2) {
              digitalWrite(MorseLEDPin, HIGH);
            }
            if (MorseMode >= 2) {
              tone(MorseTonePin, MorseToneFreq);
            }
            delay(CWdot);
            if (MorseMode <= 2) {
              digitalWrite(MorseLEDPin, LOW);
            }
            if (MorseMode >= 2) {
              noTone(MorseTonePin);
            }
            delay(CWdot);
          }
          // Transmit dash ?
          else if (currentcode.substring(icp, icp + 1).equalsIgnoreCase("-")) {
            // Depending om Mode, what to transmit?
            if (MorseMode <= 2) {
              digitalWrite(MorseLEDPin, HIGH);
            }
            if (MorseMode >= 2) {
              tone(MorseTonePin, MorseToneFreq);
            }
            delay(CWdash);
            if (MorseMode <= 2) {
              digitalWrite(MorseLEDPin, LOW);
            }
            if (MorseMode >= 2) {
              noTone(MorseTonePin);
            }
            delay(CWdot);
          }
          // Transmit empty space?
          else if (currentcode.substring(icp, icp + 1).equalsIgnoreCase(" ")) {

            delay(CWdot * 4);
          }
        }
      }
      ichar = ichar + 2; // Increase by two (every characters has one index for character and one for the code).
    }
    delay(CWdot * 3); // Delay after each character is transmitted
  }
  // Delay after message is sent (in case another is sent)
  delay(CWdot * 7);
  // Beacon mode? Then send long tone.



}



void cwid() {     //transmit the call sign......................................................................................
  //-----------------------------------------------------------------------------------------------------------
  togate = 1;   //delay timer to preclude double CWIDs ================================================
  digitalWrite(outPTT, HIGH);
  delay(200);
  TransmitMorse(2, MorseString, MorseWPM, MorseLEDPin, 5, 800, 0);   //send call sign---------- see TransmitMorse function varables above .................................
  cwidtimer = 0;
  cwgate = 0;
  if (timeout >= T_out) {
    Time_Out();//if in a timeout state, call Time_Out() to transmit "TIME OUT" in morse code, 1000 hz tone.
  }
}

void onesec() { //this is the main timer function.  The timers wii count up each second, when their respective gate is open.
  if (DIGIT >= 1) {
    dtmftim = dtmftim + 1;
  }
  if (dtmftim >= 7) { //7 seconds is max code input enter time!
    dtmftim = 0;//Reset the dtmf entry timeout timer.
    DIGIT = 0;//Reset the command code digit counter.
    cmdcode = 0;
    digit = 0;
  }
  if (togate == 1) {
    timeout = timeout + 1;
  }
  if (cwgate == 1) {
    cwidtimer = cwidtimer + 1;
  }
  if (COS == 0) {
    cwdel = cwdel + 1;
  }
  if (FANgate == 1) {
    fantime = fantime + 1;
  }
}

void Update_cmd() {
  digit = DIGIT;
  cmdcode = cmdcode + dtmf1;

  if (DIGIT < 5) {
    cmdcode = cmdcode * 10, DEC;
  }
  if (DIGIT >= 5) {
    DIGIT = 0;
    CMD = cmdcode - (Operator_Code * 100);
    Serial.print("Command = ");
    Serial.println(CMD, DEC);
    Serial.println("CMD_update");
    if (CMD == 00) {
      RPTR = 0;//repeater off
      Serial.println("Repeater OFF");
      EEPROM.updateInt(0, 0);
    }
    if (CMD == 01) {
      RPTR = 1; //repeater on
      Serial.println("Repeater ON");
      EEPROM.updateInt(0, 1);
    }
    if (CMD == 02) {
      TPLR = 0; //TPL not required
      Serial.println("TPLR OFF, PL tone not required.");
      EEPROM.updateInt(4, 0);
    }
    if (CMD == 03) {
      TPLR = 1;//on - TPL Required
      Serial.println("TPLR ON, PL tone required.");
      EEPROM.updateInt(4, 1);
    }
    cmdcode = 00;
    digit = 0;
    DIGIT = 0;
    dtmftim = 0;
    Serial.print("  CMD "); Serial.print(CMD);
    Serial.print("  RPTR "); Serial.print(RPTR);
    Serial.print("  TPLR= "); Serial.println(TPLR);
    CMD = 0;
  }
}
void readDTMF() {  //"interrupt service routine".
  dtmf1 = PINC & 0x0F;    //Get 4 l.s. bits port c from dtmf receiver.  port C; C0=A0,C1=A1,C2=A2, & C3= A3 (UNO Board only)....
  if (dtmf1 > 9) {
    dtmf1 = 0; // NOTE:    ALL keys input 0,A,B,C,D,E,F,#, and * will equate to = "0".  This is NECESSARY for the Update_cmd() function to work.
    //A CMD must not start with a "0"!!

  }
  DIGIT = DIGIT + 1;
}






// ----------------------------------------------------------------------------------------
// Main program LOOP
// ----------------------------------------------------------------------------------------

void loop() {
  if (DIGIT > digit) {
    Update_cmd();
  }
  t.update();
  if (cwidtimer >= CWID_TIM) {
    cwid();
  }
  if (digitalRead(cwidTest) ==  LOW) {//Ground to send test cwid.
    cwid();
  }

  //************************************************************************************************************

  //logic to combine COSin  and Active hi/low to COS logic
  if (((digitalRead(COSin) == HIGH) && COSactive == 1)  || ((digitalRead(COSin) == LOW) && COSactive == 0)) {
    COS = 1;

  }
  else {
    COS = 0;
  }

  //logic to combine TPLin and Active hi/low to TPL
  if (((digitalRead(TPLin) == HIGH) && TPLactive == 1)  || ((digitalRead(TPLin) == LOW) && TPLactive == 0)) {
    TPL = 1;
  }
  else {
    TPL = 0;
  }

  if (COS == 0) {
    timeout = 0;
  }
  if ((COS == 1) && (timeout < T_out)) {
    if ((((RPTR == 1) && (TPL == 1) && TPLR == 1)) || ((RPTR == 1) && (TPLR == 0))) {
      digitalWrite(outPTT, HIGH);

      FANgate = 0;
      cwgate = 1;
      togate = 1;
      if (timeout >= 5) {
        digitalWrite(fanpin, HIGH);
        fantime = 0;
        FANgate = 0;
      }
    }
    else {
      digitalWrite(outPTT, LOW);
      FANgate = 1;
      togate = 0;

    }




    if (timeout >= 10) {
      digitalWrite(fanpin, HIGH);
      fantime = 0;
      FANgate = 0;
    }



    if (DIGIT > digit) {
      Update_cmd();
    }

  }
  else {
    delay(200);
    digitalWrite(outPTT, LOW);
    FANgate = 1;
    togate = 0;
  }
  if (fantime >= FANtime) {
    FANgate = 0;
    fantime = 0;
    digitalWrite(fanpin, LOW);
  }
  //path for first CWID  ---delays 1st CWID until 15 secs repeater idle- prevents 2nd kerchunk CWID========
  if (cwdel >= 15 && timeout >= 1) {
    timeout = timeout + 5;
    cwdel = 0;
    cwid();
  }
  if (timeout >= T_out) {
    togate = 0;
    digitalWrite(outPTT, LOW);
    Serial.println("TIME OUT");

  }
}

void Time_Out() {     //transmit the call sign......................................................................................
  //-----------------------------------------------------------------------------------------------------------
  //delay timer to preclude double CWIDs ================================================
  digitalWrite(outPTT, HIGH);
  delay(200);
  TransmitMorse(2, "TIME OUT", MorseWPM, MorseLEDPin, 5, 1000, 0); // see TransmitMorse function varables above. The timeout message tone is 1000 HZ.

}
