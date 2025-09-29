/*
  Minimal driver for the Microchip MCP23017 16-bit I²C GPIO expander.

  Features
  - Per-pin direction: pinMode(GPA0..GPB7, INPUT/OUTPUT)
  - Digital I/O: digitalWrite(), digitalRead(), togglePin()
  - Pull-ups & polarity: pullUp(), setPolarity()
  - Interrupts: enableInterrupt(), disableInterrupt(), getInterrupt(), clearInterrupt()
  - Flexible I²C bus: pass any TwoWire*; user-defined SDA/SCL in begin()

  Usage (quick start)
    #include <Wire.h>
    #include "mcp23017.h"
    MCP23017 mcp(0x20, &Wire);          // address = 0x20..0x27
    // Optional custom pins/frequency (platform-dependent):
    // mcp.begin(SDA_pin, SCL_pin, 100000);
    // Defaults: begin(A4, A5, 10000) for AVR; on ESP/STM32, pins are ignored if not supported.

  Notes
  - Register naming: This header uses INTEA/INTEB (a.k.a. GPINTENA/GPINTENB in some docs).
  - Interrupt flags clear by reading INTCAPx (or GPIOx), not by writing to INTFx.
  - Bit ops on uint8_t: cast shifts, e.g. (uint8_t)(1U << n), to avoid C++ promotion warnings.
  - I²C pull-ups (4.7k–10k) are required on SDA/SCL if your board does not include them.

  Address Pins
  - I²C address = 0x20 | (A2<<2 | A1<<1 | A0), where A2..A0 are MCP23017 hardware straps.
*/
#ifndef MCP23017_H_
#define MCP23017_H_

#include <Arduino.h>
#include <Wire.h>

// MCP23017 Register Addresses
#define IODIRA 0x00
#define IODIRB 0x01
#define IPOLA 0x02
#define IPOLB 0x03
#define INTEA 0x04
#define INTEB 0x05
#define DEFVALA 0x06
#define DEFVALB 0x07
#define INTCONA 0x08
#define INTCONB 0x09
#define INTCAPA 0x10
#define INTCAPB 0x11
#define GPIOA 0x12
#define GPIOB 0x13
#define OLATA 0x14
#define OLATB 0x15
#define IOCON 0x0A
#define GPPUA 0x0C
#define GPPUB 0x0D
#define INTFA 0x0E
#define INTFB 0x0F


#define STATE_CHANGE 0
#define STATE_SET 1

enum pins {
  GPA0 = 0,
  GPA1,
  GPA2,
  GPA3,
  GPA4,
  GPA5,
  GPA6,
  GPA7,
  GPB0,
  GPB1,
  GPB2,
  GPB3,
  GPB4,
  GPB5,
  GPB6,
  GPB7
};

class MCP23017 {
public:

  MCP23017(uint8_t address = 0x20, TwoWire* i2c = &Wire);
  bool begin(int sda = A4, int scl = A5, uint32_t freq = 10000);
  void pinMode(enum pins pin, uint8_t mode);
  void digitalWrite(enum pins pin, bool value);
  uint8_t digitalRead(enum pins pin);
  void togglePin(enum pins pin);

  void pullUp(enum pins pin, bool enable);
  void setPolarity(enum pins pin, bool invert);

  void enableInterrupt(enum pins pin, bool compareToDefval, bool defval);
  void disableInterrupt(enum pins pin);
  void clearInterrupt();
  uint8_t getInterrupt(enum pins pin);
  uint8_t readReg(uint8_t reg);
  bool writeReg(uint8_t reg, uint8_t value);
private:
  uint8_t _address;
  TwoWire* _i2c;
  void writePin(enum pins pin, uint8_t value);
  uint8_t readPin(enum pins pin);
};

#endif