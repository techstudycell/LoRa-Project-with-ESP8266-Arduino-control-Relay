# LoRa-Project-with-ESP8266-Arduino-control-Relay
In this Lora project, I have shown how to make the LoRa Arduino ESP8266 control relay using the RYLR896 LoRa module with real-time feedback.
So after turning on and off the appliances the receiver circuit will send feedback to the transmitter circuit.

## Tutorial Video on the LoRa Project
Video Link:  https://youtu.be/uWCY1CkvhR8

In this video, I have covered the following topics.

Explained this ESP8266 Arduino Lora home automation project.
Explained Transmitter & Receiver Lora circuit.
Configure LoRa with AT commands.
Explained the source codes for this LoRA project.
Connecting the LoRa module with Arduino and ESP8266.
Control high voltage appliances with LoRa.
So if you follow all the steps, you can easily make this Lora Arduino project to control any appliances from 10KM away in the rural areas without Wi-Fi and Bluetooth. So this project is very useful in rural areas.

Although the PCB is not mandatory, however, if you want, you can also use this PCB to make the circuit compact and give the project a professional look.

## Required component for this Transmitter circuit
1. REYAX RYLR896 Lora Module
2. Arduino Nano
3. 220-ohm Resistor
4. 4.7k Resistor
5. 10k Resistor
6.  5-mm LED 3no
7.  Push buttons 4no

## Required component for this Receiver circuit
1.  REYAX RYLR896 Lora Module
2.  ESP8266 NodeMCU
3.  5v 4-channel Relay Module
4.  4.7k Resistor
5.  10k Resistor

## Required Components for the PCB
1. Relays 5v (SPDT) (4 no)
2. BC547 Transistors (4 no)
3. PC817 Optocuplors (4 no)
4. 510-ohm 0.25-watt Resistor (4 no) (R1 - R4)
5. 1k 0.25-watt Resistors (5 no) (R5 - R9)
6. LED 5-mm (5 no)
7. 1N4007 Diodes (5 no) (D1 - D5)
8. Push Buttons (4 no)
9. Terminal Connectors
10. 5V DC supply

## Required Software:
1.  Arduino IDE

## Transmitter Lora Circuit Using Arduino
In the transmitter LoRa circuit, I have used Arduino Nano. I have made a voltage divider using 4.7k and 10k resistors to drop down the 5-volt logic level to the 3.3-volt logic level.

The pushbuttons are connected with the D2, D3, D4, and D5 digital pins of the Arduino.

I have used the INPUT_PULLUP function in Arduino IDE instead of using the pull-up resistors.

And the LEDs are connected with the D7, D8, and D13 digital pins of the Arduino.

On the Arduino board, a resistor is already connected in series with theD13 pin, so I have not used any series resistor with the LED for the D13 pin.

You can use any 5V DC supply or 9V battery to supply the circuit.

## Receiver Lora Circuit Using Arduino
In the receiver LoRa circuit, I have used NodeMCU as the microcontroller. In the circuit, I have also made a voltage divider using 4.7k and 10k resistors to drop down the 5-volt logic level to the 3.3-volt logic level.

I have used D1, D2, D5 & D6 GPIO pins to control the 4 relays.

**The Boot will fail if RX is grounded during the Boot process of NodeMCU. So, connect the LoRa module after giving the supply to NodeMCU.

I have used a 5V 2Amp power supply to supply the NodeMCU and relay module.

Please take the proper safety precautions while working with high voltage.

## Configuring the Parameters With AT Commands
First, you have to connect the LoRa module with FTDI232 USB to serial interface board as per the circuit to configure some parameters with AT commands.

In Serial monitor select the Baud rate = 115200 and "Both NL & CR".

AT Commands used for the Transmitter LoRa module
AT+ADDRESS=1
AT+NETWORKID=5
AT+BAND=865000000

AT Commands used for the Receiver LoRa module
AT+ADDRESS=1
AT+NETWORKID=5
AT+BAND=865000000
Select the BAND as per the eligible LoRa bands available in your country.

Please refer to the tutorial video for more details.

## Codes for This LoRa Project Using Arduino and ESP8266
In this Lora Project, I have used Arduino Nano for the transmitter circuit, and NodeMCU for the receiving circuit.

First, download the source codes. Then upload the code for the transmitter circuit to Arduino. And upload the code of the receiving circuit to NodeMCU.

## Design the PCB for the Receiving LoRa Circuit
To avoid any loose connections, I have designed the PCB for the receier Lora circuit.

You can download the PCB Gerber file of this home automation project from the following link:
https://github.com/techstudycell/LoRa-Project-with-ESP8266-Arduino-control-Relay/tree/main/PCB_Gerber

## Order the PCB from JLCPCB
After downloading the Garber file you can easily order the PCB

Visit https://jlcpcb.com/RAB and Sign in / Sign up
1. Click on the QUOTE NOW button.
2. Click on the "Add gerber file" button. Then browse and select the Gerber file you have downloaded.
3. Set the required parameter like Quantity, PCB masking color, etc.
4. After selecting all the Parameters for PCB click on SAVE TO CART button.
5. Type the Shipping Address.
6. Select the Shipping Method suitable for you.
7. Submit the order and proceed with the payment.
8. You can also track your order from the JLCPCB.com

My PCBs took 2 days to get manufactured and arrived within a week using the DHL delivery option. PCBs were well packed and the quality was really good at this affordable price.

## Solder All the Components on PCB
After that, I have soldered all the components as per the circuit diagram.

Then connect the NodeMCU board with the PCB.

## Connect the Appliances With the Relay Module
Connect the 4 appliances with the relay module as per the circuit diagram.

Please take proper safety precautions while working with high voltage.

## Connect the LoRa Module With Arduino and ESP8266
After uploading the codes, connect the LoRa modules with the Arduino and NodeMCU.

For the receiving circuit turn ON the 5V supply before connecting the LoRa module.

## Control the Appliances With LoRa
Now you can control the appliances with the transmitter LoRa circuit and also monitor the real-time feedback from the receiver LoRa circuit.

Please make sure there should not be any loose connection, otherwise, this circuit may not work.

In the future, I will try to add more features to this LoRa project.

I will really appreciate it if you share your valuable feedbacks. Also if you have any query please write in the comment section.

Thank you & Happy Learning.
