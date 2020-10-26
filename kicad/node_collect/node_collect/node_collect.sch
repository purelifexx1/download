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
L custom:LORA L?
U 1 1 5F8DFC3E
P 5950 2500
F 0 "L?" H 6628 2301 50  0000 L CNN
F 1 "LORA" H 6628 2210 50  0000 L CNN
F 2 "" H 6500 2850 50  0001 C CNN
F 3 "" H 6500 2850 50  0001 C CNN
	1    5950 2500
	1    0    0    -1  
$EndComp
$Comp
L custom:ESP32 E?
U 1 1 5F8E2DAF
P 5050 4100
F 0 "E?" H 5050 4775 50  0000 C CNN
F 1 "ESP32" H 5050 4684 50  0000 C CNN
F 2 "" H 5050 3050 50  0001 C CNN
F 3 "" H 5050 3050 50  0001 C CNN
	1    5050 4100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DIP_x04 SW?
U 1 1 5F8E426E
P 6850 3900
F 0 "SW?" H 6850 4367 50  0000 C CNN
F 1 "SW_DIP_x04" H 6850 4276 50  0000 C CNN
F 2 "" H 6850 3900 50  0001 C CNN
F 3 "~" H 6850 3900 50  0001 C CNN
	1    6850 3900
	1    0    0    -1  
$EndComp
Text GLabel 5500 4550 2    50   Input ~ 0
TX2I
Text GLabel 5500 4450 2    50   Input ~ 0
RX2I
Text GLabel 5500 4950 2    50   Input ~ 0
GND
Text GLabel 6550 3700 0    50   Input ~ 0
RX2I
Text GLabel 6550 3800 0    50   Input ~ 0
TX2I
Text GLabel 5500 3650 2    50   Input ~ 0
D23
Text GLabel 6550 3900 0    50   Input ~ 0
D23
Text GLabel 6550 4000 0    50   Input ~ 0
D22
Text GLabel 5500 3750 2    50   Input ~ 0
D22
Text GLabel 5450 2650 0    50   Input ~ 0
RXO
Text GLabel 5450 2750 0    50   Input ~ 0
TXO
Text GLabel 7150 3800 2    50   Input ~ 0
TXO
Text GLabel 7150 3700 2    50   Input ~ 0
RXO
Wire Wire Line
	7150 3900 7150 4000
Text GLabel 5500 5050 2    50   Input ~ 0
3V3
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 5F8E6526
P 6800 4400
F 0 "J?" H 6908 4681 50  0000 C CNN
F 1 "Conn_01x03_Male" H 6908 4590 50  0000 C CNN
F 2 "" H 6800 4400 50  0001 C CNN
F 3 "~" H 6800 4400 50  0001 C CNN
	1    6800 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 5F8E71F3
P 6800 4900
F 0 "J?" H 6908 5181 50  0000 C CNN
F 1 "Conn_01x03_Male" H 6908 5090 50  0000 C CNN
F 2 "" H 6800 4900 50  0001 C CNN
F 3 "~" H 6800 4900 50  0001 C CNN
	1    6800 4900
	1    0    0    -1  
$EndComp
Text GLabel 5450 2450 0    50   Input ~ 0
M0
Text GLabel 5450 2550 0    50   Input ~ 0
M1
Text GLabel 5500 4050 2    50   Input ~ 0
AUX
Text GLabel 5500 4150 2    50   Input ~ 0
AUX
Text GLabel 5450 2850 0    50   Input ~ 0
AUX
Text GLabel 5450 3050 0    50   Input ~ 0
GND
Text GLabel 5450 2950 0    50   Input ~ 0
3V3
Text GLabel 7000 4300 2    50   Input ~ 0
3V3
Text GLabel 7000 4500 2    50   Input ~ 0
GND
Text GLabel 7000 4800 2    50   Input ~ 0
3V3
Text GLabel 7000 5000 2    50   Input ~ 0
GND
Text GLabel 7000 4900 2    50   Input ~ 0
M1
Text GLabel 7000 4400 2    50   Input ~ 0
M0
Text GLabel 7150 4000 2    50   Input ~ 0
GND
Wire Notes Line
	5100 2300 6900 2300
Wire Notes Line
	6900 2300 6900 3250
Wire Notes Line
	6900 3250 5100 3250
Wire Notes Line
	5100 3250 5100 2300
Wire Notes Line
	4500 3350 5800 3350
Wire Notes Line
	5800 3350 5800 5200
Wire Notes Line
	5800 5200 4500 5200
Wire Notes Line
	4500 5200 4500 3350
Wire Notes Line
	6250 3350 7450 3350
Wire Notes Line
	7450 3350 7450 5150
Wire Notes Line
	7450 5150 6250 5150
Wire Notes Line
	6250 5150 6250 3350
Text Label 5650 2300 0    197  ~ 0
Communication
Text Label 7050 3350 0    197  ~ 0
Interface
Text Label 3450 3350 0    197  ~ 0
Processing
$EndSCHEMATC
