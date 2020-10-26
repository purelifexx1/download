EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L custom:bluepill B1
U 1 1 5F872A09
P 8150 3300
F 0 "B1" H 8125 3475 50  0000 C CNN
F 1 "bluepill" H 8125 3384 50  0000 C CNN
F 2 "custom:BLUEPILL" H 8150 3350 50  0001 C CNN
F 3 "" H 8150 3350 50  0001 C CNN
	1    8150 3300
	1    0    0    -1  
$EndComp
$Comp
L custom:LORA L2
U 1 1 5F87699F
P 5700 2200
F 0 "L2" H 6378 2001 50  0000 L CNN
F 1 "LORA" H 6378 1910 50  0000 L CNN
F 2 "custom:LORA" H 6250 2550 50  0001 C CNN
F 3 "" H 6250 2550 50  0001 C CNN
	1    5700 2200
	1    0    0    -1  
$EndComp
$Comp
L custom:RS485 R1
U 1 1 5F879355
P 5350 1600
F 0 "R1" H 5375 1975 50  0000 C CNN
F 1 "RS485" H 5375 1884 50  0000 C CNN
F 2 "custom:RS485" H 5350 1850 50  0001 C CNN
F 3 "" H 5350 1850 50  0001 C CNN
	1    5350 1600
	1    0    0    -1  
$EndComp
$Comp
L Connector:RJ45 J4
U 1 1 5F88426D
P 6900 1650
F 0 "J4" H 6957 2317 50  0000 C CNN
F 1 "RJ45" H 6957 2226 50  0000 C CNN
F 2 "Connector_RJ:RJ45_Ninigi_GE" V 6900 1675 50  0001 C CNN
F 3 "~" V 6900 1675 50  0001 C CNN
	1    6900 1650
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J6
U 1 1 5F8A008B
P 7800 1350
F 0 "J6" H 7908 1631 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7908 1540 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7800 1350 50  0001 C CNN
F 3 "~" H 7800 1350 50  0001 C CNN
	1    7800 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J7
U 1 1 5F8A439B
P 7800 1800
F 0 "J7" H 7908 2081 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7908 1990 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7800 1800 50  0001 C CNN
F 3 "~" H 7800 1800 50  0001 C CNN
	1    7800 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x06 SW1
U 1 1 5F88E134
P 8950 1750
F 0 "SW1" H 8950 2317 50  0000 C CNN
F 1 "SW_DIP_x06" H 8950 2226 50  0000 C CNN
F 2 "Package_DIP:DIP-12_W7.62mm" H 8950 1750 50  0001 C CNN
F 3 "~" H 8950 1750 50  0001 C CNN
	1    8950 1750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8650 1550 8650 1650
Wire Wire Line
	6500 1250 6500 1350
Wire Wire Line
	6500 1450 6500 1550
Wire Wire Line
	6500 1650 6500 1750
Wire Wire Line
	6500 1850 6500 1950
$Comp
L Device:R R3
U 1 1 5F8B1CF2
P 9100 5000
F 0 "R3" H 9170 5046 50  0000 L CNN
F 1 "R" H 9170 4955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 9030 5000 50  0001 C CNN
F 3 "~" H 9100 5000 50  0001 C CNN
	1    9100 5000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5F8B32B5
P 9300 4750
F 0 "J5" H 9272 4632 50  0000 R CNN
F 1 "Conn_01x02_Male" H 9272 4723 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9300 4750 50  0001 C CNN
F 3 "~" H 9300 4750 50  0001 C CNN
	1    9300 4750
	-1   0    0    1   
$EndComp
Wire Wire Line
	9100 4750 9100 4850
Wire Wire Line
	9100 5150 8650 5150
Wire Wire Line
	9100 4650 9100 4550
Text GLabel 7600 5050 0    50   Input ~ 0
VCCI
Text GLabel 7600 5150 0    50   Input ~ 0
GND1
Text GLabel 8650 4650 2    50   Input ~ 0
LRXI
Text GLabel 8650 4550 2    50   Input ~ 0
LTXI
Text GLabel 8650 1450 0    50   Input ~ 0
VCCO
Text GLabel 8650 1550 0    50   Input ~ 0
3V3
Text GLabel 8650 1750 0    50   Input ~ 0
RLD
Text GLabel 8650 1950 0    50   Input ~ 0
LTXD
Text GLabel 8650 1850 0    50   Input ~ 0
LRXD
Text GLabel 9250 1450 2    50   Input ~ 0
VCCI
Text GLabel 9250 1550 2    50   Input ~ 0
MODE
Text GLabel 9250 1650 2    50   Input ~ 0
MANUAL
Text GLabel 9250 1750 2    50   Input ~ 0
RLI
Text GLabel 9250 1950 2    50   Input ~ 0
LTXI
Text GLabel 9250 1850 2    50   Input ~ 0
LRXI
Text GLabel 5200 2150 0    50   Input ~ 0
M0
Text GLabel 5200 2250 0    50   Input ~ 0
M1
Text GLabel 5200 2550 0    50   Input ~ 0
AUX
Text GLabel 9100 4550 1    50   Input ~ 0
3V3
Text GLabel 8650 3350 2    50   Input ~ 0
GND2
Text GLabel 8650 3550 2    50   Input ~ 0
3V3
Text GLabel 8650 3750 2    50   Input ~ 0
RRXD
Text GLabel 8650 3850 2    50   Input ~ 0
RTXD
Text GLabel 4750 1450 0    50   Input ~ 0
VCCI
Text GLabel 4750 1550 0    50   Input ~ 0
RTXD
Text GLabel 4750 1650 0    50   Input ~ 0
RRXD
Text GLabel 4750 1750 0    50   Input ~ 0
GND1
Text GLabel 6000 1600 2    50   Input ~ 0
B
Text GLabel 6000 1700 2    50   Input ~ 0
A
Text GLabel 6500 1550 0    50   Input ~ 0
B
Text GLabel 6500 1750 0    50   Input ~ 0
A
Text GLabel 8000 1250 2    50   Input ~ 0
VCCI
Text GLabel 8000 1350 2    50   Input ~ 0
M0
Text GLabel 8000 1450 2    50   Input ~ 0
GND1
Text GLabel 8000 1700 2    50   Input ~ 0
VCCI
Text GLabel 8000 1800 2    50   Input ~ 0
M1
Text GLabel 8000 1900 2    50   Input ~ 0
GND1
Text GLabel 6500 1350 0    50   Input ~ 0
GND1
Text GLabel 8650 3350 1    50   Input ~ 0
GND1
Text GLabel 8650 4450 2    50   Input ~ 0
RLI
Text GLabel 8650 4350 2    50   Input ~ 0
MANUAL
Text GLabel 8650 4250 2    50   Input ~ 0
MODE
Text GLabel 8650 4150 2    50   Input ~ 0
AUX
Text GLabel 7600 5250 0    50   Input ~ 0
3V3
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5F8D920A
P 7800 2150
F 0 "J8" H 7908 2331 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7908 2240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7800 2150 50  0001 C CNN
F 3 "~" H 7800 2150 50  0001 C CNN
	1    7800 2150
	1    0    0    -1  
$EndComp
Text GLabel 8000 2150 2    50   Input ~ 0
LRXD
Text GLabel 8000 2250 2    50   Input ~ 0
LTXD
Wire Notes Line
	4350 950  7350 950 
Wire Notes Line
	7550 2350 7550 950 
Wire Notes Line
	7300 5400 7300 3000
Wire Notes Line
	9650 950  9650 2350
Wire Notes Line
	7550 950  9650 950 
Wire Notes Line
	7550 2350 9650 2350
Text Label 5000 950  0    197  ~ 0
Communication
Text Label 4250 3300 0    197  ~ 0
Power
Wire Notes Line
	3150 4400 3150 3300
Wire Notes Line
	6850 4400 3150 4400
Wire Notes Line
	6850 3300 6850 4400
Wire Notes Line
	3150 3300 6850 3300
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5F8B54D4
P 3450 4100
F 0 "J1" H 3558 4281 50  0000 C CNN
F 1 "Conn_01x02_Male" H 3558 4190 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3450 4100 50  0001 C CNN
F 3 "~" H 3450 4100 50  0001 C CNN
	1    3450 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4100 4000 4100
Wire Wire Line
	4450 4200 3650 4200
Text GLabel 6050 3900 2    50   Input ~ 0
GND2
Text GLabel 6050 3500 2    50   Input ~ 0
VCCO
Text GLabel 6550 4000 2    50   Input ~ 0
RLD
Text GLabel 5200 2750 0    50   Input ~ 0
GND2
Text GLabel 5200 2650 0    50   Input ~ 0
VCCI
Text GLabel 5200 2450 0    50   Input ~ 0
LTXD
Text GLabel 5200 2350 0    50   Input ~ 0
LRXD
Wire Wire Line
	6550 4100 6550 4150
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5F8AD900
P 6350 4000
F 0 "J3" H 6458 4281 50  0000 C CNN
F 1 "Conn_01x03_Male" H 6458 4190 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 6350 4000 50  0001 C CNN
F 3 "~" H 6350 4000 50  0001 C CNN
	1    6350 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3900 4450 4200
Wire Wire Line
	4450 3700 4450 3800
Wire Wire Line
	4000 3700 4450 3700
Wire Wire Line
	4000 4100 4000 3800
Connection ~ 6050 3900
Wire Wire Line
	6050 4150 6050 3900
Wire Wire Line
	6550 4150 6050 4150
Wire Wire Line
	6550 3800 6550 3900
Connection ~ 6050 3500
Wire Wire Line
	6050 3500 6550 3500
$Comp
L Device:R R2
U 1 1 5F8AE845
P 6550 3650
F 0 "R2" H 6620 3696 50  0000 L CNN
F 1 "R" H 6620 3605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6480 3650 50  0001 C CNN
F 3 "~" H 6550 3650 50  0001 C CNN
	1    6550 3650
	1    0    0    -1  
$EndComp
Connection ~ 5700 3500
Wire Wire Line
	5350 3500 5700 3500
Wire Wire Line
	5350 3800 5350 3500
Wire Wire Line
	6050 3500 5700 3500
Wire Wire Line
	6050 3600 6050 3500
Wire Wire Line
	5700 3500 5700 3600
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5F8A9A07
P 3800 3700
F 0 "J2" H 3908 3881 50  0000 C CNN
F 1 "Conn_01x02_Male" H 3908 3790 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3800 3700 50  0001 C CNN
F 3 "~" H 3800 3700 50  0001 C CNN
	1    3800 3700
	1    0    0    -1  
$EndComp
Connection ~ 5700 3900
Wire Wire Line
	6050 3900 5700 3900
Wire Wire Line
	5350 3900 5700 3900
$Comp
L Device:CP C2
U 1 1 5F88C241
P 6050 3750
F 0 "C2" H 6168 3796 50  0000 L CNN
F 1 "CP" H 6168 3705 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 6088 3600 50  0001 C CNN
F 3 "~" H 6050 3750 50  0001 C CNN
	1    6050 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5F88A420
P 5700 3750
F 0 "C1" H 5815 3796 50  0000 L CNN
F 1 "C" H 5815 3705 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 5738 3600 50  0001 C CNN
F 3 "~" H 5700 3750 50  0001 C CNN
	1    5700 3750
	1    0    0    -1  
$EndComp
$Comp
L custom:LM2596 L1
U 1 1 5F87A2D9
P 4850 3850
F 0 "L1" H 4900 4125 50  0000 C CNN
F 1 "LM2596" H 4900 4034 50  0000 C CNN
F 2 "custom:LM2596" H 4900 4000 50  0001 C CNN
F 3 "" H 4900 4000 50  0001 C CNN
	1    4850 3850
	1    0    0    -1  
$EndComp
Wire Notes Line
	7350 2850 4350 2850
Wire Notes Line
	7350 950  7350 2850
Wire Notes Line
	4350 950  4350 2850
Wire Notes Line
	7300 3000 10000 3000
Wire Notes Line
	10000 3000 10000 5400
Wire Notes Line
	10000 5400 7300 5400
Text Label 9000 2350 0    197  ~ 0
Interface
Text Label 8100 3000 0    197  ~ 0
Processing
$EndSCHEMATC
