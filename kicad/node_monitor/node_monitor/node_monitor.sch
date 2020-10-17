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
P 5750 2800
F 0 "B1" H 5725 2975 50  0000 C CNN
F 1 "bluepill" H 5725 2884 50  0000 C CNN
F 2 "custom:BLUEPILL" H 5750 2850 50  0001 C CNN
F 3 "" H 5750 2850 50  0001 C CNN
	1    5750 2800
	1    0    0    -1  
$EndComp
$Comp
L custom:LORA L2
U 1 1 5F87699F
P 8000 2450
F 0 "L2" H 8678 2251 50  0000 L CNN
F 1 "LORA" H 8678 2160 50  0000 L CNN
F 2 "custom:LORA" H 8550 2800 50  0001 C CNN
F 3 "" H 8550 2800 50  0001 C CNN
	1    8000 2450
	1    0    0    -1  
$EndComp
$Comp
L custom:RS485 R1
U 1 1 5F879355
P 4450 2200
F 0 "R1" H 4475 2575 50  0000 C CNN
F 1 "RS485" H 4475 2484 50  0000 C CNN
F 2 "custom:RS485" H 4450 2450 50  0001 C CNN
F 3 "" H 4450 2450 50  0001 C CNN
	1    4450 2200
	1    0    0    -1  
$EndComp
$Comp
L custom:LM2596 L1
U 1 1 5F87A2D9
P 2800 3100
F 0 "L1" H 2850 3375 50  0000 C CNN
F 1 "LM2596" H 2850 3284 50  0000 C CNN
F 2 "custom:LM2596" H 2850 3250 50  0001 C CNN
F 3 "" H 2850 3250 50  0001 C CNN
	1    2800 3100
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
L Device:C C1
U 1 1 5F88A420
P 3650 3000
F 0 "C1" H 3765 3046 50  0000 L CNN
F 1 "C" H 3765 2955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 3688 2850 50  0001 C CNN
F 3 "~" H 3650 3000 50  0001 C CNN
	1    3650 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5F88C241
P 4000 3000
F 0 "C2" H 4118 3046 50  0000 L CNN
F 1 "CP" H 4118 2955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 4038 2850 50  0001 C CNN
F 3 "~" H 4000 3000 50  0001 C CNN
	1    4000 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J6
U 1 1 5F8A008B
P 7650 1700
F 0 "J6" H 7758 1981 50  0000 C CNN
F 1 "Conn_01x03_Male" H 7758 1890 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7650 1700 50  0001 C CNN
F 3 "~" H 7650 1700 50  0001 C CNN
	1    7650 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J7
U 1 1 5F8A439B
P 8750 1700
F 0 "J7" H 8858 1981 50  0000 C CNN
F 1 "Conn_01x03_Male" H 8858 1890 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8750 1700 50  0001 C CNN
F 3 "~" H 8750 1700 50  0001 C CNN
	1    8750 1700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x06 SW1
U 1 1 5F88E134
P 7550 3800
F 0 "SW1" H 7550 4367 50  0000 C CNN
F 1 "SW_DIP_x06" H 7550 4276 50  0000 C CNN
F 2 "Package_DIP:DIP-12_W7.62mm" H 7550 3800 50  0001 C CNN
F 3 "~" H 7550 3800 50  0001 C CNN
	1    7550 3800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7250 3600 7250 3700
Wire Wire Line
	6500 1250 6500 1350
Wire Wire Line
	6500 1450 6500 1550
Wire Wire Line
	6500 1650 6500 1750
Wire Wire Line
	6500 1850 6500 1950
Wire Wire Line
	3300 3150 3650 3150
Wire Wire Line
	4000 3150 3650 3150
Connection ~ 3650 3150
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5F8A9A07
P 1750 2950
F 0 "J2" H 1858 3131 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1858 3040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1750 2950 50  0001 C CNN
F 3 "~" H 1750 2950 50  0001 C CNN
	1    1750 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2750 3650 2850
Wire Wire Line
	4000 2850 4000 2750
Wire Wire Line
	4000 2750 3650 2750
Wire Wire Line
	3300 3050 3300 2750
Wire Wire Line
	3300 2750 3650 2750
Connection ~ 3650 2750
$Comp
L Device:R R2
U 1 1 5F8AE845
P 4500 2900
F 0 "R2" H 4570 2946 50  0000 L CNN
F 1 "R" H 4570 2855 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4430 2900 50  0001 C CNN
F 3 "~" H 4500 2900 50  0001 C CNN
	1    4500 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2750 4500 2750
Connection ~ 4000 2750
Wire Wire Line
	4500 3050 4500 3150
Wire Wire Line
	4500 3400 4000 3400
Wire Wire Line
	4000 3400 4000 3150
Connection ~ 4000 3150
$Comp
L Device:R R3
U 1 1 5F8B1CF2
P 6700 4500
F 0 "R3" H 6770 4546 50  0000 L CNN
F 1 "R" H 6770 4455 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6630 4500 50  0001 C CNN
F 3 "~" H 6700 4500 50  0001 C CNN
	1    6700 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Male J5
U 1 1 5F8B32B5
P 6900 4250
F 0 "J5" H 6872 4132 50  0000 R CNN
F 1 "Conn_01x02_Male" H 6872 4223 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 6900 4250 50  0001 C CNN
F 3 "~" H 6900 4250 50  0001 C CNN
	1    6900 4250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6700 4250 6700 4350
Wire Wire Line
	6700 4650 6250 4650
Wire Wire Line
	6700 4150 6700 4050
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5F8B54D4
P 1400 3350
F 0 "J1" H 1508 3531 50  0000 C CNN
F 1 "Conn_01x02_Male" H 1508 3440 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1400 3350 50  0001 C CNN
F 3 "~" H 1400 3350 50  0001 C CNN
	1    1400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3350 1950 3350
Wire Wire Line
	1950 3350 1950 3050
Wire Wire Line
	1950 2950 2400 2950
Wire Wire Line
	2400 2950 2400 3050
Wire Wire Line
	2400 3150 2400 3450
Wire Wire Line
	2400 3450 1600 3450
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5F8AD900
P 4300 3250
F 0 "J3" H 4408 3531 50  0000 C CNN
F 1 "Conn_01x03_Male" H 4408 3440 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4300 3250 50  0001 C CNN
F 3 "~" H 4300 3250 50  0001 C CNN
	1    4300 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 3350 4500 3400
Text GLabel 5200 4550 0    50   Input ~ 0
VCCI
Text GLabel 5200 4650 0    50   Input ~ 0
GND1
Text GLabel 6250 4150 2    50   Input ~ 0
LRXI
Text GLabel 6250 4050 2    50   Input ~ 0
LTXI
Text GLabel 7250 3500 0    50   Input ~ 0
VCCO
Text GLabel 7250 3600 0    50   Input ~ 0
3V3
Text GLabel 7250 3800 0    50   Input ~ 0
RLD
Text GLabel 7250 4000 0    50   Input ~ 0
LTXD
Text GLabel 7250 3900 0    50   Input ~ 0
LRXD
Text GLabel 7850 3500 2    50   Input ~ 0
VCCI
Text GLabel 7850 3600 2    50   Input ~ 0
MODE
Text GLabel 7850 3700 2    50   Input ~ 0
MANUAL
Text GLabel 7850 3800 2    50   Input ~ 0
RLI
Text GLabel 7850 4000 2    50   Input ~ 0
LTXI
Text GLabel 7850 3900 2    50   Input ~ 0
LRXI
Text GLabel 7500 2400 0    50   Input ~ 0
M0
Text GLabel 7500 2500 0    50   Input ~ 0
M1
Text GLabel 7500 2600 0    50   Input ~ 0
LRXD
Text GLabel 7500 2700 0    50   Input ~ 0
LTXD
Text GLabel 7500 2800 0    50   Input ~ 0
AUX
Text GLabel 7500 2900 0    50   Input ~ 0
VCCI
Text GLabel 7500 3000 0    50   Input ~ 0
GND2
Text GLabel 6700 4050 1    50   Input ~ 0
3V3
Text GLabel 6250 2850 2    50   Input ~ 0
GND2
Text GLabel 6250 3050 2    50   Input ~ 0
3V3
Text GLabel 6250 3250 2    50   Input ~ 0
RRXD
Text GLabel 6250 3350 2    50   Input ~ 0
RTXD
Text GLabel 4500 3250 2    50   Input ~ 0
RLD
Text GLabel 4000 2750 2    50   Input ~ 0
VCCO
Text GLabel 3850 2050 0    50   Input ~ 0
VCCI
Text GLabel 3850 2150 0    50   Input ~ 0
RTXD
Text GLabel 3850 2250 0    50   Input ~ 0
RRXD
Text GLabel 3850 2350 0    50   Input ~ 0
GND1
Text GLabel 5100 2200 2    50   Input ~ 0
B
Text GLabel 5100 2300 2    50   Input ~ 0
A
Text GLabel 6500 1550 0    50   Input ~ 0
B
Text GLabel 6500 1750 0    50   Input ~ 0
A
Text GLabel 7850 1600 2    50   Input ~ 0
VCCI
Text GLabel 7850 1700 2    50   Input ~ 0
M0
Text GLabel 7850 1800 2    50   Input ~ 0
GND1
Text GLabel 8950 1600 2    50   Input ~ 0
VCCI
Text GLabel 8950 1700 2    50   Input ~ 0
M1
Text GLabel 8950 1800 2    50   Input ~ 0
GND1
Text GLabel 4000 3150 2    50   Input ~ 0
GND2
Text GLabel 6500 1350 0    50   Input ~ 0
GND1
Text GLabel 6250 2850 1    50   Input ~ 0
GND1
Text GLabel 6250 3950 2    50   Input ~ 0
RLI
Text GLabel 6250 3850 2    50   Input ~ 0
MANUAL
Text GLabel 6250 3750 2    50   Input ~ 0
MODE
Text GLabel 6250 3650 2    50   Input ~ 0
AUX
Text GLabel 5200 4750 0    50   Input ~ 0
3V3
$Comp
L Connector:Conn_01x02_Male J8
U 1 1 5F8D920A
P 8600 3350
F 0 "J8" H 8708 3531 50  0000 C CNN
F 1 "Conn_01x02_Male" H 8708 3440 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8600 3350 50  0001 C CNN
F 3 "~" H 8600 3350 50  0001 C CNN
	1    8600 3350
	1    0    0    -1  
$EndComp
Text GLabel 8800 3350 2    50   Input ~ 0
LRXD
Text GLabel 8800 3450 2    50   Input ~ 0
LTXD
$EndSCHEMATC
