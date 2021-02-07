#ifndef MAIN_H_
#define MAIN_H_

/* Function patamerters */
#define txtail_ms 1000       // Kuyruk suresi (milisaniye)
#define txtimemout_timer_ms 12000  // TOT Timeout Timer 120 saniye (2 dakika)
#define command_timeout_ms 10000 // Toplam komut gonderme suresi (milisaniye)
#define dtmf_timeout_ms 3000     // DTMF kodlari arasindaki maksimum sure (milisaniye)

#define SQL_OPEN_LEVEL 0


/* Pin Definition */
#define dtmf_pinSTD    2
#define squelch_in_pin 3 // Squelch Giris Pini D3
#define dtmf_pinQ1     4
#define dtmf_pinQ2     5
#define dtmf_pinQ3     6
#define dtmf_pinQ4     7
#define ptt_pin        8 // TX tarafinin PTT baglantisi B0
#define digital_out_1  9 // FAN Kontrolu vb.

/* Type Definitions */
typedef enum
{
    REPEATER_OFF = 0x00,
    REPEATER_ON  = 0x01
} Repeater_state_t;

typedef enum
{
    BEACON_NONE  = 0x00,
    BEACON_MORSE = 0x01,
    BEACON_AX25  = 0x02,
    BEACON_BOTH  = 0x03
} Beaconmode_t;

typedef enum
{
    COMMAND_REPEATER_ON         = 0x11,
    COMMAND_REPEATER_OFF        = 0x12,
    COMMAND_DIGITAL1_ON         = 0x21,
    COMMAND_DIGITAL1_OFF        = 0x22,
    COMMAND_DIGITAL2_ON         = 0x23,
    COMMAND_DIGITAL2_OFF        = 0x24,
    COMMAND_DIGITAL3_ON         = 0x25,
    COMMAND_DIGITAL3_OFF        = 0x26,
    COMMAND_BEACON_ON           = 0x31,
    COMMAND_BEACON_OFF          = 0x32,
    COMMAND_INITIALIZE          = 0x44,
    COMMAND_REPORT_STATUS       = 0x50,
    COMMAND_GET_READ_BATTERY    = 0x51,
    COMMAND_GET_TEMPERATURE     = 0x52,
    COMMAND_GET_ANALOG          = 0x53,
    COMMAND_SET_TAIL_TIME       = 0x70,
    COMMAND_SET_USER_PASS       = 0x71,
    COMMAND_SET_ADMIN_PASS      = 0x72
} Dtmf_commands_t;


typedef struct 
{
    Repeater_state_t    state;
    uint16_t            tx_tail_s;
    uint16_t             user_password;
    uint16_t             admin_password;
    char                call_sign[6];
    uint8_t             inhibit_tx;
    Beaconmode_t        beaconmode;

} Repeater_configutarion_t;

typedef struct 
{
    float               aku_voltaj;
    uint8_t             fan_durum;

} Beacon_meassage_t;


void dtmf_interrupt();
void squelch_interrupt();
void init_configuration(Repeater_configutarion_t* config);
bool check_password();
void exec_command();
void change_ptt_state(bool state);


#endif /* MAIN_H_ */