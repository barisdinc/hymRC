EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "hymRC Repeater Controller"
Date "2021-02-21"
Rev "1.0"
Comp "Baris DINC (TA7W / OH2UDS)"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L hymRC_components:KT8870 U1
U 1 1 6031E0A6
P 2100 2000
F 0 "U1" H 2100 2881 50  0000 C CNN
F 1 "KT8870" H 2100 2790 50  0000 C CNN
F 2 "Package_SO:SOIC-18W_7.5x11.6mm_P1.27mm" H 2100 1350 50  0001 C CNN
F 3 "http://www.holtek.com/documents/10179/116711/9170v111.pdf" H 2000 2700 50  0001 C CNN
	1    2100 2000
	1    0    0    -1  
$EndComp
$Comp
L Interface_Expansion:MCP23017_SP U2
U 1 1 6031EF7A
P 6200 2100
F 0 "U2" H 5750 3050 50  0000 C CNN
F 1 "MCP23017_SP" H 6500 3100 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 6400 1100 50  0001 L CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20001952C.pdf" H 6400 1000 50  0001 L CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y1
U 1 1 6032A317
P 1350 2500
F 0 "Y1" H 1350 2300 50  0000 C CNN
F 1 "3.5795M" H 1350 2650 50  0000 C CNN
F 2 "" H 1350 2500 50  0001 C CNN
F 3 "~" H 1350 2500 50  0001 C CNN
	1    1350 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1600 2400 1200 2400
Wire Wire Line
	1200 2400 1200 2500
Wire Wire Line
	1500 2500 1600 2500
$Comp
L Device:R R2
U 1 1 6032E735
P 1350 1700
F 0 "R2" V 1450 1700 50  0000 C CNN
F 1 "69K" V 1350 1700 50  0000 C CNN
F 2 "" V 1280 1700 50  0001 C CNN
F 3 "~" H 1350 1700 50  0001 C CNN
	1    1350 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 6032F325
P 1200 1400
F 0 "R1" V 1300 1350 50  0000 L CNN
F 1 "100K" V 1200 1300 50  0000 L CNN
F 2 "" V 1130 1400 50  0001 C CNN
F 3 "~" H 1200 1400 50  0001 C CNN
	1    1200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 6032F91F
P 2800 1600
F 0 "R3" V 2900 1600 50  0000 C CNN
F 1 "390K" V 2800 1600 50  0000 C CNN
F 2 "" V 2730 1600 50  0001 C CNN
F 3 "~" H 2800 1600 50  0001 C CNN
	1    2800 1600
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C2
U 1 1 603302B5
P 2950 1400
F 0 "C2" H 3042 1446 50  0000 L CNN
F 1 "100n" H 3042 1355 50  0000 L CNN
F 2 "" H 2950 1400 50  0001 C CNN
F 3 "~" H 2950 1400 50  0001 C CNN
	1    2950 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 60330AEC
P 1050 1200
F 0 "C1" V 1150 1200 50  0000 C CNN
F 1 "100n" V 912 1200 50  0000 C CNN
F 2 "" H 1050 1200 50  0001 C CNN
F 3 "~" H 1050 1200 50  0001 C CNN
	1    1050 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	1550 1900 1600 1900
Wire Wire Line
	1600 1500 1550 1500
Wire Wire Line
	1550 1500 1550 1900
Wire Wire Line
	1600 1600 1200 1600
Wire Wire Line
	1200 1600 1200 1700
Connection ~ 1200 1600
Wire Wire Line
	1200 1550 1200 1600
Wire Wire Line
	1150 1200 1200 1200
Wire Wire Line
	1200 1200 1200 1250
Text GLabel 950  1200 0    50   Input ~ 0
DTMF_In
Wire Wire Line
	1600 1700 1500 1700
Wire Wire Line
	2600 1600 2650 1600
Wire Wire Line
	2950 1600 2950 1500
Wire Wire Line
	2950 1500 2600 1500
Connection ~ 2950 1500
Wire Wire Line
	2100 1300 2100 950 
Wire Wire Line
	2100 950  2500 950 
Wire Wire Line
	2950 950  2950 1300
Wire Wire Line
	2500 950  2500 850 
Connection ~ 2500 950 
Wire Wire Line
	2500 950  2950 950 
$Comp
L power:GND #PWR0101
U 1 1 60343229
P 2100 2800
F 0 "#PWR0101" H 2100 2550 50  0001 C CNN
F 1 "GND" H 2105 2627 50  0000 C CNN
F 2 "" H 2100 2800 50  0001 C CNN
F 3 "" H 2100 2800 50  0001 C CNN
	1    2100 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2700 2100 2800
$Comp
L power:+5V #PWR0102
U 1 1 603441AE
P 2500 850
F 0 "#PWR0102" H 2500 700 50  0001 C CNN
F 1 "+5V" H 2515 1023 50  0000 C CNN
F 2 "" H 2500 850 50  0001 C CNN
F 3 "" H 2500 850 50  0001 C CNN
	1    2500 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 60345E1D
P 1400 2150
F 0 "#PWR0103" H 1400 2000 50  0001 C CNN
F 1 "+5V" H 1415 2323 50  0000 C CNN
F 2 "" H 1400 2150 50  0001 C CNN
F 3 "" H 1400 2150 50  0001 C CNN
	1    1400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2200 1400 2200
Wire Wire Line
	1400 2200 1400 2150
Wire Notes Line
	3300 550  3300 3300
Wire Notes Line
	3300 3300 550  3300
Wire Notes Line
	550  3300 550  550 
Wire Notes Line
	550  550  3300 550 
Text Notes 1800 3250 0    50   ~ 0
DTMF DECODER
Text Label 2600 2200 0    50   ~ 0
Q1
Text Label 2600 2100 0    50   ~ 0
Q2
Text Label 2600 2000 0    50   ~ 0
Q3
Text Label 2600 1900 0    50   ~ 0
Q4
Text Label 2600 1800 0    50   ~ 0
StD
Text Label 5500 1900 2    50   ~ 0
INTA
Text Label 5500 2000 2    50   ~ 0
INTB
$Comp
L power:+5V #PWR018
U 1 1 6034ECEB
P 5250 2100
F 0 "#PWR018" H 5250 1950 50  0001 C CNN
F 1 "+5V" H 5265 2273 50  0000 C CNN
F 2 "" H 5250 2100 50  0001 C CNN
F 3 "" H 5250 2100 50  0001 C CNN
	1    5250 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2200 5250 2200
Wire Wire Line
	5250 2200 5250 2100
$Comp
L power:+5V #PWR021
U 1 1 60350A96
P 6200 900
F 0 "#PWR021" H 6200 750 50  0001 C CNN
F 1 "+5V" H 6215 1073 50  0000 C CNN
F 2 "" H 6200 900 50  0001 C CNN
F 3 "" H 6200 900 50  0001 C CNN
	1    6200 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 900  6200 1000
$Comp
L power:GND #PWR022
U 1 1 60351DF8
P 6200 3300
F 0 "#PWR022" H 6200 3050 50  0001 C CNN
F 1 "GND" H 6205 3127 50  0000 C CNN
F 2 "" H 6200 3300 50  0001 C CNN
F 3 "" H 6200 3300 50  0001 C CNN
	1    6200 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3200 6200 3300
Wire Wire Line
	5500 2700 5400 2700
Wire Wire Line
	5400 2700 5400 2800
Wire Wire Line
	5400 2900 5500 2900
Wire Wire Line
	5500 2800 5400 2800
Connection ~ 5400 2800
Wire Wire Line
	5400 2800 5400 2900
$Comp
L power:GND #PWR020
U 1 1 603546FB
P 5400 3000
F 0 "#PWR020" H 5400 2750 50  0001 C CNN
F 1 "GND" H 5405 2827 50  0000 C CNN
F 2 "" H 5400 3000 50  0001 C CNN
F 3 "" H 5400 3000 50  0001 C CNN
	1    5400 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2900 5400 3000
Connection ~ 5400 2900
Text Label 9200 1550 2    50   ~ 0
INTA
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 6031B06F
P 9700 1950
F 0 "A1" H 9350 2900 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 10200 1000 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 9700 1950 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 9700 1950 50  0001 C CNN
	1    9700 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR028
U 1 1 6035703F
P 9700 3000
F 0 "#PWR028" H 9700 2750 50  0001 C CNN
F 1 "GND" H 9705 2827 50  0000 C CNN
F 2 "" H 9700 3000 50  0001 C CNN
F 3 "" H 9700 3000 50  0001 C CNN
	1    9700 3000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR029
U 1 1 60357976
P 9800 3000
F 0 "#PWR029" H 9800 2750 50  0001 C CNN
F 1 "GND" H 9805 2827 50  0000 C CNN
F 2 "" H 9800 3000 50  0001 C CNN
F 3 "" H 9800 3000 50  0001 C CNN
	1    9800 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2950 9700 3000
Wire Wire Line
	9800 2950 9800 3000
$Comp
L power:+5V #PWR030
U 1 1 6035A1D1
P 9900 850
F 0 "#PWR030" H 9900 700 50  0001 C CNN
F 1 "+5V" H 9915 1023 50  0000 C CNN
F 2 "" H 9900 850 50  0001 C CNN
F 3 "" H 9900 850 50  0001 C CNN
	1    9900 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 950  9900 850 
NoConn ~ 9800 950 
Wire Wire Line
	9600 950  9600 750 
Text GLabel 9600 750  1    50   Input ~ 0
Vin
NoConn ~ 10200 1350
NoConn ~ 10200 1450
Text Label 6900 1300 0    50   ~ 0
Q1
Text Label 6900 1400 0    50   ~ 0
Q2
Text Label 6900 1500 0    50   ~ 0
Q3
Text Label 6900 1600 0    50   ~ 0
Q4
Text Label 6900 1700 0    50   ~ 0
StD
$Comp
L Device:R R19
U 1 1 6036EDA3
P 5400 1100
F 0 "R19" V 5500 1050 50  0000 L CNN
F 1 "10K" V 5400 1000 50  0000 L CNN
F 2 "" V 5330 1100 50  0001 C CNN
F 3 "~" H 5400 1100 50  0001 C CNN
	1    5400 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R18
U 1 1 6036F858
P 5200 1100
F 0 "R18" V 5300 1050 50  0000 L CNN
F 1 "10K" V 5200 1000 50  0000 L CNN
F 2 "" V 5130 1100 50  0001 C CNN
F 3 "~" H 5200 1100 50  0001 C CNN
	1    5200 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1300 5400 1300
Wire Wire Line
	5400 1300 5400 1250
Wire Wire Line
	5200 1400 5200 1250
Wire Wire Line
	5200 1400 5400 1400
Wire Wire Line
	5200 950  5200 900 
Wire Wire Line
	5400 950  5400 900 
$Comp
L power:+5V #PWR017
U 1 1 60372C71
P 5200 900
F 0 "#PWR017" H 5200 750 50  0001 C CNN
F 1 "+5V" H 5215 1073 50  0000 C CNN
F 2 "" H 5200 900 50  0001 C CNN
F 3 "" H 5200 900 50  0001 C CNN
	1    5200 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 6037309A
P 5400 900
F 0 "#PWR019" H 5400 750 50  0001 C CNN
F 1 "+5V" H 5415 1073 50  0000 C CNN
F 2 "" H 5400 900 50  0001 C CNN
F 3 "" H 5400 900 50  0001 C CNN
	1    5400 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 1300 5350 1300
Connection ~ 5400 1300
Wire Wire Line
	5200 1400 5150 1400
Connection ~ 5200 1400
Text Label 5350 1300 2    50   ~ 0
SDA
Text Label 5150 1400 2    50   ~ 0
SCL
Text Label 10200 2350 0    50   ~ 0
SDA
Text Label 10200 2450 0    50   ~ 0
SCL
Text GLabel 9200 1350 0    50   Input ~ 0
UART_RX
Text GLabel 9200 1450 0    50   Input ~ 0
UART_TX
Text GLabel 9200 1650 0    50   Input ~ 0
SQUELCH
$Comp
L Device:R R6
U 1 1 6038A86F
P 1400 6650
F 0 "R6" V 1500 6600 50  0000 L CNN
F 1 "47K" V 1400 6550 50  0000 L CNN
F 2 "" V 1330 6650 50  0001 C CNN
F 3 "~" H 1400 6650 50  0001 C CNN
	1    1400 6650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 6038BD1F
P 1400 7050
F 0 "R7" V 1500 7000 50  0000 L CNN
F 1 "10K" V 1400 6950 50  0000 L CNN
F 2 "" V 1330 7050 50  0001 C CNN
F 3 "~" H 1400 7050 50  0001 C CNN
	1    1400 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 6800 1400 6850
$Comp
L power:GND #PWR02
U 1 1 6038D22D
P 1400 7200
F 0 "#PWR02" H 1400 6950 50  0001 C CNN
F 1 "GND" H 1405 7027 50  0000 C CNN
F 2 "" H 1400 7200 50  0001 C CNN
F 3 "" H 1400 7200 50  0001 C CNN
	1    1400 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 6500 1400 6400
Wire Wire Line
	1400 6400 1100 6400
Text GLabel 1100 6400 0    50   Input ~ 0
Aku_12V
Wire Wire Line
	1400 6850 1650 6850
Connection ~ 1400 6850
Wire Wire Line
	1400 6850 1400 6900
Text Label 1650 6850 0    50   ~ 0
Analog0
$Comp
L Device:R R10
U 1 1 6039007B
P 2850 6650
F 0 "R10" V 2950 6600 50  0000 L CNN
F 1 "47K" V 2850 6550 50  0000 L CNN
F 2 "" V 2780 6650 50  0001 C CNN
F 3 "~" H 2850 6650 50  0001 C CNN
	1    2850 6650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 60390119
P 2850 7050
F 0 "R11" V 2950 7000 50  0000 L CNN
F 1 "10K" V 2850 6950 50  0000 L CNN
F 2 "" V 2780 7050 50  0001 C CNN
F 3 "~" H 2850 7050 50  0001 C CNN
	1    2850 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 6800 2850 6850
$Comp
L power:GND #PWR06
U 1 1 60390124
P 2850 7200
F 0 "#PWR06" H 2850 6950 50  0001 C CNN
F 1 "GND" H 2855 7027 50  0000 C CNN
F 2 "" H 2850 7200 50  0001 C CNN
F 3 "" H 2850 7200 50  0001 C CNN
	1    2850 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 6500 2850 6400
Wire Wire Line
	2850 6400 2550 6400
Text GLabel 2550 6400 0    50   Input ~ 0
Analog_Sensor1
Wire Wire Line
	2850 6850 3100 6850
Connection ~ 2850 6850
Wire Wire Line
	2850 6850 2850 6900
Text Label 3100 6850 0    50   ~ 0
Analog1
$Comp
L Device:R R14
U 1 1 603924AA
P 4300 6700
F 0 "R14" V 4400 6650 50  0000 L CNN
F 1 "47K" V 4300 6600 50  0000 L CNN
F 2 "" V 4230 6700 50  0001 C CNN
F 3 "~" H 4300 6700 50  0001 C CNN
	1    4300 6700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 60392574
P 4300 7100
F 0 "R15" V 4400 7050 50  0000 L CNN
F 1 "10K" V 4300 7000 50  0000 L CNN
F 2 "" V 4230 7100 50  0001 C CNN
F 3 "~" H 4300 7100 50  0001 C CNN
	1    4300 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 6850 4300 6900
$Comp
L power:GND #PWR013
U 1 1 6039257F
P 4300 7250
F 0 "#PWR013" H 4300 7000 50  0001 C CNN
F 1 "GND" H 4305 7077 50  0000 C CNN
F 2 "" H 4300 7250 50  0001 C CNN
F 3 "" H 4300 7250 50  0001 C CNN
	1    4300 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 6550 4300 6450
Wire Wire Line
	4300 6450 4000 6450
Text GLabel 4000 6450 0    50   Input ~ 0
Analog_Sensor2
Wire Wire Line
	4300 6900 4550 6900
Connection ~ 4300 6900
Wire Wire Line
	4300 6900 4300 6950
Text Label 4550 6900 0    50   ~ 0
Analog2
Wire Notes Line
	5000 6200 5000 7700
Wire Notes Line
	5000 7700 550  7700
Wire Notes Line
	550  7700 550  6200
Wire Notes Line
	550  6200 5000 6200
Text Notes 2200 7650 0    50   ~ 0
ANALOG SENSOR & BATTERY READING
Text Label 10200 1950 0    50   ~ 0
Analog0
Text Label 10200 2050 0    50   ~ 0
Analog1
Text Label 10200 2150 0    50   ~ 0
Analog2
Text Label 9200 2150 2    50   ~ 0
PTT
Text GLabel 9200 2350 0    50   Input ~ 0
SPI_SS
Text GLabel 9200 2450 0    50   Input ~ 0
SPI_MOSI
Text GLabel 9200 2550 0    50   Input ~ 0
SPI_MISO
Text GLabel 9200 2650 0    50   Input ~ 0
SPI_SCK
Text GLabel 6900 2900 2    50   Input ~ 0
Digital_Sensor_CS1
Text GLabel 6900 2800 2    50   Input ~ 0
Digital_Sensor_CS2
Text GLabel 6900 2700 2    50   Input ~ 0
Digital_Sensor_CS3
$Comp
L Connector:Conn_01x09_Female J2
U 1 1 603AA9BD
P 10700 4150
F 0 "J2" H 10550 4700 50  0000 L CNN
F 1 "Digital Sensor Connector" H 9800 3500 50  0000 L CNN
F 2 "" H 10700 4150 50  0001 C CNN
F 3 "~" H 10700 4150 50  0001 C CNN
	1    10700 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR031
U 1 1 603ADCF5
P 10400 3700
F 0 "#PWR031" H 10400 3550 50  0001 C CNN
F 1 "+5V" H 10415 3873 50  0000 C CNN
F 2 "" H 10400 3700 50  0001 C CNN
F 3 "" H 10400 3700 50  0001 C CNN
	1    10400 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR032
U 1 1 603AF688
P 10400 4600
F 0 "#PWR032" H 10400 4350 50  0001 C CNN
F 1 "GND" H 10250 4550 50  0000 C CNN
F 2 "" H 10400 4600 50  0001 C CNN
F 3 "" H 10400 4600 50  0001 C CNN
	1    10400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 4550 10400 4550
Wire Wire Line
	10400 4550 10400 4600
Wire Wire Line
	10500 3750 10400 3750
Wire Wire Line
	10400 3750 10400 3700
Wire Wire Line
	10500 3850 10400 3850
Wire Wire Line
	10500 3950 10400 3950
Wire Wire Line
	10500 4050 10400 4050
Wire Wire Line
	10500 4150 10400 4150
Wire Wire Line
	10500 4250 10400 4250
Wire Wire Line
	10500 4350 10400 4350
Wire Wire Line
	10500 4450 10400 4450
Text GLabel 10400 3850 0    50   Input ~ 0
SPI_SS
Text GLabel 10400 3950 0    50   Input ~ 0
SPI_MOSI
Text GLabel 10400 4050 0    50   Input ~ 0
SPI_MISO
Text GLabel 10400 4150 0    50   Input ~ 0
SPI_SCK
Text GLabel 10400 4250 0    50   Input ~ 0
Digital_Sensor_CS1
Text GLabel 10400 4350 0    50   Input ~ 0
Digital_Sensor_CS2
Text GLabel 10400 4450 0    50   Input ~ 0
Digital_Sensor_CS3
Wire Notes Line
	10900 4850 9550 4850
Wire Notes Line
	9550 4850 9550 3400
Wire Notes Line
	9550 3400 10900 3400
Wire Notes Line
	10900 3400 10900 4850
Text Label 6900 2200 0    50   ~ 0
CONTROL_OUTPUT_0
Text Label 6900 2300 0    50   ~ 0
CONTROL_OUTPUT_1
Text Label 6900 2400 0    50   ~ 0
CONTROL_OUTPUT_2
Text Label 6900 2500 0    50   ~ 0
CONTROL_OUTPUT_3
Text Label 6900 1800 0    50   ~ 0
CONTROL_INPUT_0
Text Label 6900 1900 0    50   ~ 0
CONTROL_INPUT_1
Text Label 6900 2000 0    50   ~ 0
CONTROL_INPUT_2
Wire Notes Line
	7950 550  7950 3650
Wire Notes Line
	7950 3650 4550 3650
Wire Notes Line
	4550 3650 4550 550 
Wire Notes Line
	4550 550  7950 550 
Text Notes 6900 3550 0    50   ~ 0
GPIO PORT EXTENDER
Text Notes 10650 3200 0    50   ~ 0
MCU
$Comp
L Connector:Conn_01x09_Female J3
U 1 1 60400B87
P 10700 5700
F 0 "J3" H 10550 6250 50  0000 L CNN
F 1 "Analog Sensor Connector" H 9800 5050 50  0000 L CNN
F 2 "" H 10700 5700 50  0001 C CNN
F 3 "~" H 10700 5700 50  0001 C CNN
	1    10700 5700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR033
U 1 1 60400CB9
P 10400 5250
F 0 "#PWR033" H 10400 5100 50  0001 C CNN
F 1 "+5V" H 10415 5423 50  0000 C CNN
F 2 "" H 10400 5250 50  0001 C CNN
F 3 "" H 10400 5250 50  0001 C CNN
	1    10400 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR034
U 1 1 60400CC3
P 10400 6150
F 0 "#PWR034" H 10400 5900 50  0001 C CNN
F 1 "GND" H 10250 6100 50  0000 C CNN
F 2 "" H 10400 6150 50  0001 C CNN
F 3 "" H 10400 6150 50  0001 C CNN
	1    10400 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 6100 10400 6100
Wire Wire Line
	10400 6100 10400 6150
Wire Wire Line
	10500 5300 10400 5300
Wire Wire Line
	10400 5300 10400 5250
Wire Wire Line
	10500 5400 10400 5400
Wire Wire Line
	10500 5500 10400 5500
Wire Wire Line
	10500 5600 10400 5600
Wire Wire Line
	10500 5700 10400 5700
Wire Wire Line
	10500 5800 10400 5800
Wire Wire Line
	10500 5900 10400 5900
Wire Wire Line
	10500 6000 10400 6000
Wire Notes Line
	10900 6400 9550 6400
Wire Notes Line
	9550 6400 9550 4950
Wire Notes Line
	9550 4950 10900 4950
Wire Notes Line
	10900 4950 10900 6400
Wire Notes Line
	10900 550  8100 550 
Wire Notes Line
	8100 550  8100 3250
Wire Notes Line
	8100 3250 10900 3250
Wire Notes Line
	10900 3250 10900 550 
Text GLabel 10400 5400 0    50   Input ~ 0
Analog_Sensor1
Text GLabel 10400 5500 0    50   Input ~ 0
Analog_Sensor2
Wire Notes Line
	6900 6200 6900 7700
Wire Notes Line
	6900 7700 5100 7700
Wire Notes Line
	5100 7700 5100 6200
Wire Notes Line
	5100 6200 6900 6200
Text Notes 5850 7650 0    50   ~ 0
5V Regulator
Wire Notes Line
	550  3750 550  6050
$Comp
L Device:Q_NPN_EBC Q1
U 1 1 6046C7E5
P 1350 5350
F 0 "Q1" H 1541 5396 50  0000 L CNN
F 1 "NPN" H 1541 5305 50  0000 L CNN
F 2 "" H 1550 5450 50  0001 C CNN
F 3 "~" H 1350 5350 50  0001 C CNN
	1    1350 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 60470F5D
P 1100 5550
F 0 "R5" V 1200 5500 50  0000 L CNN
F 1 "10K" V 1100 5450 50  0000 L CNN
F 2 "" V 1030 5550 50  0001 C CNN
F 3 "~" H 1100 5550 50  0001 C CNN
	1    1100 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 60475BD0
P 900 5350
F 0 "R4" V 1000 5300 50  0000 L CNN
F 1 "1K" V 900 5250 50  0000 L CNN
F 2 "" V 830 5350 50  0001 C CNN
F 3 "~" H 900 5350 50  0001 C CNN
	1    900  5350
	0    1    1    0   
$EndComp
$Comp
L Device:D D1
U 1 1 60476AEA
P 1100 4650
F 0 "D1" V 1050 4450 50  0000 L CNN
F 1 "1N4001" V 1150 4300 50  0000 L CNN
F 2 "" H 1100 4650 50  0001 C CNN
F 3 "~" H 1100 4650 50  0001 C CNN
	1    1100 4650
	0    1    1    0   
$EndComp
$Comp
L Relay:DIPxx-1Cxx-51x K1
U 1 1 60477DC9
P 1650 4650
F 0 "K1" H 2080 4696 50  0000 L CNN
F 1 "Role" H 2080 4605 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 2100 4600 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 1650 4650 50  0001 C CNN
	1    1650 4650
	1    0    0    -1  
$EndComp
$Comp
L Relay:AZ850P1-x K4
U 1 1 60478D93
P 7000 4600
F 0 "K4" H 7630 4646 50  0000 L CNN
F 1 "Role" H 7630 4555 50  0000 L CNN
F 2 "Relay_THT:Relay_DPDT_FRT5" H 7550 4650 50  0001 C CNN
F 3 "http://www.azettler.com/pdfs/az850.pdf" H 7000 4600 50  0001 C CNN
	1    7000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5350 1100 5350
Wire Wire Line
	1100 5400 1100 5350
Connection ~ 1100 5350
Wire Wire Line
	1100 5350 1150 5350
$Comp
L power:GND #PWR01
U 1 1 60484B64
P 1100 5750
F 0 "#PWR01" H 1100 5500 50  0001 C CNN
F 1 "GND" H 1105 5577 50  0000 C CNN
F 2 "" H 1100 5750 50  0001 C CNN
F 3 "" H 1100 5750 50  0001 C CNN
	1    1100 5750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 60485671
P 1450 5750
F 0 "#PWR04" H 1450 5500 50  0001 C CNN
F 1 "GND" H 1455 5577 50  0000 C CNN
F 2 "" H 1450 5750 50  0001 C CNN
F 3 "" H 1450 5750 50  0001 C CNN
	1    1450 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 5550 1450 5750
Wire Wire Line
	1100 5700 1100 5750
Wire Wire Line
	1450 4950 1450 5050
Wire Wire Line
	1100 4800 1100 5050
Wire Wire Line
	1100 5050 1450 5050
Connection ~ 1450 5050
Wire Wire Line
	1450 5050 1450 5150
Wire Wire Line
	1450 4350 1450 4300
Wire Wire Line
	1100 4500 1100 4300
Wire Wire Line
	1100 4300 1450 4300
Connection ~ 1450 4300
$Comp
L power:+12V #PWR03
U 1 1 6049A40E
P 1450 4100
F 0 "#PWR03" H 1450 3950 50  0001 C CNN
F 1 "+12V" H 1465 4273 50  0000 C CNN
F 2 "" H 1450 4100 50  0001 C CNN
F 3 "" H 1450 4100 50  0001 C CNN
	1    1450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4100 1450 4300
Text Label 650  5250 1    50   ~ 0
CONTROL_OUTPUT_0
Wire Wire Line
	650  5350 650  5250
Wire Wire Line
	650  5350 750  5350
Text GLabel 1850 4950 3    50   Input ~ 0
R0_COM
Text GLabel 1750 4350 1    50   Input ~ 0
R0_NC
Text GLabel 1950 4350 1    50   Input ~ 0
RO_NO
$Comp
L Device:Q_NPN_EBC Q2
U 1 1 604D776B
P 3100 5300
F 0 "Q2" H 3291 5346 50  0000 L CNN
F 1 "NPN" H 3291 5255 50  0000 L CNN
F 2 "" H 3300 5400 50  0001 C CNN
F 3 "~" H 3100 5300 50  0001 C CNN
	1    3100 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 604D7A2B
P 2850 5500
F 0 "R9" V 2950 5450 50  0000 L CNN
F 1 "10K" V 2850 5400 50  0000 L CNN
F 2 "" V 2780 5500 50  0001 C CNN
F 3 "~" H 2850 5500 50  0001 C CNN
	1    2850 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 604D7A35
P 2650 5300
F 0 "R8" V 2750 5250 50  0000 L CNN
F 1 "1K" V 2650 5200 50  0000 L CNN
F 2 "" V 2580 5300 50  0001 C CNN
F 3 "~" H 2650 5300 50  0001 C CNN
	1    2650 5300
	0    1    1    0   
$EndComp
$Comp
L Device:D D2
U 1 1 604D7A3F
P 2850 4600
F 0 "D2" V 2800 4400 50  0000 L CNN
F 1 "1N4001" V 2900 4250 50  0000 L CNN
F 2 "" H 2850 4600 50  0001 C CNN
F 3 "~" H 2850 4600 50  0001 C CNN
	1    2850 4600
	0    1    1    0   
$EndComp
$Comp
L Relay:DIPxx-1Cxx-51x K2
U 1 1 604D7A49
P 3400 4600
F 0 "K2" H 3830 4646 50  0000 L CNN
F 1 "Role" H 3830 4555 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 3850 4550 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 3400 4600 50  0001 C CNN
	1    3400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 5300 2850 5300
Wire Wire Line
	2850 5350 2850 5300
Connection ~ 2850 5300
Wire Wire Line
	2850 5300 2900 5300
$Comp
L power:GND #PWR05
U 1 1 604D7A57
P 2850 5700
F 0 "#PWR05" H 2850 5450 50  0001 C CNN
F 1 "GND" H 2855 5527 50  0000 C CNN
F 2 "" H 2850 5700 50  0001 C CNN
F 3 "" H 2850 5700 50  0001 C CNN
	1    2850 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 604D7A61
P 3200 5700
F 0 "#PWR09" H 3200 5450 50  0001 C CNN
F 1 "GND" H 3205 5527 50  0000 C CNN
F 2 "" H 3200 5700 50  0001 C CNN
F 3 "" H 3200 5700 50  0001 C CNN
	1    3200 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 5500 3200 5700
Wire Wire Line
	2850 5650 2850 5700
Wire Wire Line
	3200 4900 3200 5000
Wire Wire Line
	2850 4750 2850 5000
Wire Wire Line
	2850 5000 3200 5000
Connection ~ 3200 5000
Wire Wire Line
	3200 5000 3200 5100
Wire Wire Line
	3200 4300 3200 4250
Wire Wire Line
	2850 4450 2850 4250
Wire Wire Line
	2850 4250 3200 4250
Connection ~ 3200 4250
$Comp
L power:+12V #PWR08
U 1 1 604D7A76
P 3200 4050
F 0 "#PWR08" H 3200 3900 50  0001 C CNN
F 1 "+12V" H 3215 4223 50  0000 C CNN
F 2 "" H 3200 4050 50  0001 C CNN
F 3 "" H 3200 4050 50  0001 C CNN
	1    3200 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 4050 3200 4250
Text Label 2400 5200 1    50   ~ 0
CONTROL_OUTPUT_1
Wire Wire Line
	2400 5300 2400 5200
Wire Wire Line
	2400 5300 2500 5300
Text GLabel 3600 4900 3    50   Input ~ 0
R1_COM
Text GLabel 3500 4300 1    50   Input ~ 0
R1_NC
Text GLabel 3700 4300 1    50   Input ~ 0
R1_NO
$Comp
L Device:Q_NPN_EBC Q3
U 1 1 6050A84A
P 4800 5300
F 0 "Q3" H 4991 5346 50  0000 L CNN
F 1 "NPN" H 4991 5255 50  0000 L CNN
F 2 "" H 5000 5400 50  0001 C CNN
F 3 "~" H 4800 5300 50  0001 C CNN
	1    4800 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R17
U 1 1 6050AAEE
P 4550 5500
F 0 "R17" V 4650 5450 50  0000 L CNN
F 1 "10K" V 4550 5400 50  0000 L CNN
F 2 "" V 4480 5500 50  0001 C CNN
F 3 "~" H 4550 5500 50  0001 C CNN
	1    4550 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 6050AAF8
P 4350 5300
F 0 "R16" V 4450 5250 50  0000 L CNN
F 1 "1K" V 4350 5200 50  0000 L CNN
F 2 "" V 4280 5300 50  0001 C CNN
F 3 "~" H 4350 5300 50  0001 C CNN
	1    4350 5300
	0    1    1    0   
$EndComp
$Comp
L Device:D D3
U 1 1 6050AB02
P 4550 4600
F 0 "D3" V 4500 4400 50  0000 L CNN
F 1 "1N4001" V 4600 4250 50  0000 L CNN
F 2 "" H 4550 4600 50  0001 C CNN
F 3 "~" H 4550 4600 50  0001 C CNN
	1    4550 4600
	0    1    1    0   
$EndComp
$Comp
L Relay:DIPxx-1Cxx-51x K3
U 1 1 6050AB0C
P 5100 4600
F 0 "K3" H 5530 4646 50  0000 L CNN
F 1 "Role" H 5530 4555 50  0000 L CNN
F 2 "Relay_THT:Relay_StandexMeder_DIP_LowProfile" H 5550 4550 50  0001 L CNN
F 3 "https://standexelectronics.com/wp-content/uploads/datasheet_reed_relay_DIP.pdf" H 5100 4600 50  0001 C CNN
	1    5100 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 5300 4550 5300
Wire Wire Line
	4550 5350 4550 5300
Connection ~ 4550 5300
Wire Wire Line
	4550 5300 4600 5300
$Comp
L power:GND #PWR014
U 1 1 6050AB1A
P 4550 5700
F 0 "#PWR014" H 4550 5450 50  0001 C CNN
F 1 "GND" H 4555 5527 50  0000 C CNN
F 2 "" H 4550 5700 50  0001 C CNN
F 3 "" H 4550 5700 50  0001 C CNN
	1    4550 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 6050AB24
P 4900 5700
F 0 "#PWR016" H 4900 5450 50  0001 C CNN
F 1 "GND" H 4905 5527 50  0000 C CNN
F 2 "" H 4900 5700 50  0001 C CNN
F 3 "" H 4900 5700 50  0001 C CNN
	1    4900 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5500 4900 5700
Wire Wire Line
	4550 5650 4550 5700
Wire Wire Line
	4900 4900 4900 5000
Wire Wire Line
	4550 4750 4550 5000
Wire Wire Line
	4550 5000 4900 5000
Connection ~ 4900 5000
Wire Wire Line
	4900 5000 4900 5100
Wire Wire Line
	4900 4300 4900 4250
Wire Wire Line
	4550 4450 4550 4250
Wire Wire Line
	4550 4250 4900 4250
Connection ~ 4900 4250
$Comp
L power:+12V #PWR015
U 1 1 6050AB39
P 4900 4050
F 0 "#PWR015" H 4900 3900 50  0001 C CNN
F 1 "+12V" H 4915 4223 50  0000 C CNN
F 2 "" H 4900 4050 50  0001 C CNN
F 3 "" H 4900 4050 50  0001 C CNN
	1    4900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4050 4900 4250
Text Label 4100 5200 1    50   ~ 0
CONTROL_OUTPUT_2
Wire Wire Line
	4100 5300 4100 5200
Wire Wire Line
	4100 5300 4200 5300
Text GLabel 5300 4900 3    50   Input ~ 0
R2_COM
Text GLabel 5200 4300 1    50   Input ~ 0
R2_NC
Text GLabel 5400 4300 1    50   Input ~ 0
R2_NO
Text Notes 6750 6000 0    50   ~ 0
OUTPUT RELAY CONTROL UNIT
$Comp
L Device:Q_NPN_EBC Q4
U 1 1 60521B76
P 6500 5300
F 0 "Q4" H 6691 5346 50  0000 L CNN
F 1 "NPN" H 6691 5255 50  0000 L CNN
F 2 "" H 6700 5400 50  0001 C CNN
F 3 "~" H 6500 5300 50  0001 C CNN
	1    6500 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R21
U 1 1 60521B80
P 6250 5500
F 0 "R21" V 6350 5450 50  0000 L CNN
F 1 "10K" V 6250 5400 50  0000 L CNN
F 2 "" V 6180 5500 50  0001 C CNN
F 3 "~" H 6250 5500 50  0001 C CNN
	1    6250 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R20
U 1 1 60521B8A
P 6050 5300
F 0 "R20" V 6150 5250 50  0000 L CNN
F 1 "1K" V 6050 5200 50  0000 L CNN
F 2 "" V 5980 5300 50  0001 C CNN
F 3 "~" H 6050 5300 50  0001 C CNN
	1    6050 5300
	0    1    1    0   
$EndComp
$Comp
L Device:D D4
U 1 1 60521B94
P 6250 4600
F 0 "D4" V 6200 4400 50  0000 L CNN
F 1 "1N4001" V 6300 4250 50  0000 L CNN
F 2 "" H 6250 4600 50  0001 C CNN
F 3 "~" H 6250 4600 50  0001 C CNN
	1    6250 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 5300 6250 5300
Wire Wire Line
	6250 5350 6250 5300
Connection ~ 6250 5300
Wire Wire Line
	6250 5300 6300 5300
$Comp
L power:GND #PWR023
U 1 1 60521BAC
P 6250 5700
F 0 "#PWR023" H 6250 5450 50  0001 C CNN
F 1 "GND" H 6255 5527 50  0000 C CNN
F 2 "" H 6250 5700 50  0001 C CNN
F 3 "" H 6250 5700 50  0001 C CNN
	1    6250 5700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 60521BB6
P 6600 5700
F 0 "#PWR025" H 6600 5450 50  0001 C CNN
F 1 "GND" H 6605 5527 50  0000 C CNN
F 2 "" H 6600 5700 50  0001 C CNN
F 3 "" H 6600 5700 50  0001 C CNN
	1    6600 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5500 6600 5700
Wire Wire Line
	6250 5650 6250 5700
Wire Wire Line
	6600 4900 6600 5000
Wire Wire Line
	6250 4750 6250 5000
Wire Wire Line
	6250 5000 6600 5000
Connection ~ 6600 5000
Wire Wire Line
	6600 5000 6600 5100
Wire Wire Line
	6600 4300 6600 4250
Wire Wire Line
	6250 4450 6250 4250
Wire Wire Line
	6250 4250 6600 4250
Connection ~ 6600 4250
$Comp
L power:+12V #PWR024
U 1 1 60521BCB
P 6600 4050
F 0 "#PWR024" H 6600 3900 50  0001 C CNN
F 1 "+12V" H 6615 4223 50  0000 C CNN
F 2 "" H 6600 4050 50  0001 C CNN
F 3 "" H 6600 4050 50  0001 C CNN
	1    6600 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4050 6600 4250
Text Label 5800 5200 1    50   ~ 0
CONTROL_OUTPUT_3
Wire Wire Line
	5800 5300 5800 5200
Wire Wire Line
	5800 5300 5900 5300
Text GLabel 7000 4900 3    50   Input ~ 0
R3_COM1
Text GLabel 6900 4300 1    50   Input ~ 0
R3_NC1
Text GLabel 7100 4300 1    50   Input ~ 0
R3_NO1
Text GLabel 7400 4900 3    50   Input ~ 0
R3_COM2
Text GLabel 7300 4300 1    50   Input ~ 0
R3_NC2
Text GLabel 7500 4300 1    50   Input ~ 0
R3_NO2
Wire Notes Line
	7850 3750 7850 6050
Wire Notes Line
	550  6050 7850 6050
Wire Notes Line
	550  3750 7850 3750
Wire Notes Line
	9450 3400 9450 6450
Wire Notes Line
	9450 6450 8050 6450
Wire Notes Line
	8050 6450 8050 3400
Wire Notes Line
	8050 3400 9450 3400
Wire Notes Line
	3350 550  4500 550 
Wire Notes Line
	4500 550  4500 3650
Wire Notes Line
	4500 3650 3350 3650
Wire Notes Line
	3350 3650 3350 550 
Text Notes 3350 3650 0    50   ~ 0
DIGITAL INPUT OPTOCOUPLERS
Text Notes 8150 6400 0    50   ~ 0
DIGITAL INPUT OUTPUT TERMINAL
$Comp
L power:GND #PWR027
U 1 1 60579D5C
P 9050 5500
F 0 "#PWR027" H 9050 5250 50  0001 C CNN
F 1 "GND" H 8900 5450 50  0000 C CNN
F 2 "" H 9050 5500 50  0001 C CNN
F 3 "" H 9050 5500 50  0001 C CNN
	1    9050 5500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x20 J1
U 1 1 60587C28
P 9300 4450
F 0 "J1" H 9250 5450 50  0000 L CNN
F 1 "Terminal" H 9100 3250 50  0000 L CNN
F 2 "" H 9300 4450 50  0001 C CNN
F 3 "~" H 9300 4450 50  0001 C CNN
	1    9300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5450 9050 5450
Wire Wire Line
	9050 5450 9050 5500
Text GLabel 9100 3550 0    50   Input ~ 0
R0_COM
Text GLabel 9100 3650 0    50   Input ~ 0
R0_NC
Text GLabel 9100 3750 0    50   Input ~ 0
RO_NO
Text GLabel 9100 3850 0    50   Input ~ 0
R1_COM
Text GLabel 9100 3950 0    50   Input ~ 0
R1_NC
Text GLabel 9100 4050 0    50   Input ~ 0
R1_NO
Text GLabel 9100 4150 0    50   Input ~ 0
R2_COM
Text GLabel 9100 4250 0    50   Input ~ 0
R2_NC
Text GLabel 9100 4350 0    50   Input ~ 0
R2_NO
Text GLabel 9100 4450 0    50   Input ~ 0
R3_COM1
Text GLabel 9100 4550 0    50   Input ~ 0
R3_NC1
Text GLabel 9100 4650 0    50   Input ~ 0
R3_NO1
Text GLabel 9100 4750 0    50   Input ~ 0
R3_COM2
Text GLabel 9100 4850 0    50   Input ~ 0
R3_NC2
Text GLabel 9100 4950 0    50   Input ~ 0
R3_NO2
Wire Wire Line
	9100 5350 8350 5350
$Comp
L power:+12V #PWR026
U 1 1 605E557F
P 8350 5300
F 0 "#PWR026" H 8350 5150 50  0001 C CNN
F 1 "+12V" H 8365 5473 50  0000 C CNN
F 2 "" H 8350 5300 50  0001 C CNN
F 3 "" H 8350 5300 50  0001 C CNN
	1    8350 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 5300 8350 5350
Text GLabel 9100 5050 0    50   Input ~ 0
Digital_IN0
Text GLabel 9100 5150 0    50   Input ~ 0
Digital_IN1
Text GLabel 9100 5250 0    50   Input ~ 0
Digital_IN2
$Comp
L Isolator:SFH617A-1X007T U3
U 1 1 605F5941
P 3900 950
F 0 "U3" H 3900 1275 50  0000 C CNN
F 1 "OptoCoupler" H 3900 1184 50  0000 C CNN
F 2 "Package_DIP:SMDIP-4_W9.53mm_Clearance8mm" H 3900 600 50  0001 C CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 3900 900 50  0001 L CNN
	1    3900 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 606027B4
P 4250 1100
F 0 "#PWR011" H 4250 850 50  0001 C CNN
F 1 "GND" H 4255 927 50  0000 C CNN
F 2 "" H 4250 1100 50  0001 C CNN
F 3 "" H 4250 1100 50  0001 C CNN
	1    4250 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1050 4250 1050
Wire Wire Line
	4250 1050 4250 1100
Wire Wire Line
	4200 850  4250 850 
Text Label 4250 850  0    50   ~ 0
CONTROL_INPUT_0
$Comp
L power:GND2 #PWR010
U 1 1 60616113
P 3550 1100
F 0 "#PWR010" H 3550 850 50  0001 C CNN
F 1 "GND2" H 3555 927 50  0000 C CNN
F 2 "" H 3550 1100 50  0001 C CNN
F 3 "" H 3550 1100 50  0001 C CNN
	1    3550 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1050 3550 1050
Wire Wire Line
	3550 1050 3550 1100
Wire Wire Line
	3600 850  3550 850 
$Comp
L Device:R R12
U 1 1 60624CDA
P 3400 850
F 0 "R12" V 3500 850 50  0000 C CNN
F 1 "1K" V 3400 850 50  0000 C CNN
F 2 "" V 3330 850 50  0001 C CNN
F 3 "~" H 3400 850 50  0001 C CNN
	1    3400 850 
	0    1    1    0   
$EndComp
Text GLabel 3250 850  0    50   Input ~ 0
Digital_IN0
Text Notes 11900 1000 0    50   ~ 0
- SQELCH BILGISI Optocoupler'dan gecirilecek\n- DTMF girisi icin LM358 kullanilacak (huda)\n- Mors vb baglantisi yapilacak LM358 uzerinden\n- digital input 2 adet high 2 adet low trigger olacak\n- 1 role kanali daha eklenecek (2 kontak)\n- 5V icin LDO regulator ekle\n- Led uclari\n- link cihazindan gelen COR bilgisi alinirsa TX olacak, kuyruk olmayacak (lm358 i genislet)\n- link aktif ise bizim cihaz TX de iken link de akltoif olacak (ses baglantisini unutma)\n- \n
$Comp
L Amplifier_Operational:LM358 U5
U 1 1 604D5553
P 3900 2300
F 0 "U5" H 3900 2667 50  0000 C CNN
F 1 "LM358" H 3900 2576 50  0000 C CNN
F 2 "" H 3900 2300 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2904-n.pdf" H 3900 2300 50  0001 C CNN
	1    3900 2300
	1    0    0    -1  
$EndComp
$Comp
L Isolator:SFH617A-1X007T U4
U 1 1 604EBB0B
P 3900 1600
F 0 "U4" H 3900 1925 50  0000 C CNN
F 1 "OptoCoupler" H 3900 1834 50  0000 C CNN
F 2 "Package_DIP:SMDIP-4_W9.53mm_Clearance8mm" H 3900 1250 50  0001 C CIN
F 3 "http://www.vishay.com/docs/83740/sfh617a.pdf" H 3900 1550 50  0001 L CNN
	1    3900 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 604EC0CF
P 4250 1750
F 0 "#PWR012" H 4250 1500 50  0001 C CNN
F 1 "GND" H 4255 1577 50  0000 C CNN
F 2 "" H 4250 1750 50  0001 C CNN
F 3 "" H 4250 1750 50  0001 C CNN
	1    4250 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1700 4250 1700
Wire Wire Line
	4250 1700 4250 1750
Wire Wire Line
	4200 1500 4250 1500
Text Label 4250 1500 0    50   ~ 0
CONTROL_INPUT_1
Text GLabel 3500 1700 0    50   Input ~ 0
Digital_IN0
$Comp
L Device:R R13
U 1 1 604FB65C
P 3400 1500
F 0 "R13" V 3500 1500 50  0000 C CNN
F 1 "1K" V 3400 1500 50  0000 C CNN
F 2 "" V 3330 1500 50  0001 C CNN
F 3 "~" H 3400 1500 50  0001 C CNN
	1    3400 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 1500 3600 1500
Wire Wire Line
	3500 1700 3600 1700
$Comp
L power:+5V #PWR07
U 1 1 6050A0AD
P 3200 1500
F 0 "#PWR07" H 3200 1350 50  0001 C CNN
F 1 "+5V" H 3215 1673 50  0000 C CNN
F 2 "" H 3200 1500 50  0001 C CNN
F 3 "" H 3200 1500 50  0001 C CNN
	1    3200 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 1500 3250 1500
$Comp
L 4xxx:4001 U6
U 1 1 6056594F
P 3871 2963
F 0 "U6" H 3871 3288 50  0000 C CNN
F 1 "4001" H 3871 3197 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W16.51mm_SMDSocket_LongPads" H 3871 2963 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4000bms-01bms-02bms-25bms.pdf" H 3871 2963 50  0001 C CNN
	1    3871 2963
	1    0    0    -1  
$EndComp
$EndSCHEMATC
