#ifndef MAIN_H_
#define MAIN_H_

/* Function patamerters */
#define txtail_s 10       // Kuyruk suresi (saniye)
#define squelch_in_pin 3 // Squelch Giris Pini D3
#define ptt_pin 8       // TX tarafinin PTT baglantisi B0

#define SQL_OPEN_LEVEL 0


/* Pin Definition */
#define dtmf_pinSTD 2
#define dtmf_pinQ1 4
#define dtmf_pinQ2 5
#define dtmf_pinQ3 6
#define dtmf_pinQ4 7

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

typedef struct 
{
    Repeater_state_t    state;
    uint16_t            tx_tail_s;
    uint8_t             user_password[4];
    uint8_t             admin_password[4];
    char                call_sign[6];
    Beaconmode_t        beaconmode;

} Repeater_configutarion_t;

typedef struct 
{
    float               aku_voltaj;
    uint8_t             fan_durum;

} Beacon_meassage_t;






#endif /* MAIN_H_ */