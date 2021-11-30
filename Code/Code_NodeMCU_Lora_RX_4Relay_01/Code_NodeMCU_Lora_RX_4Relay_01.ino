/**********************************************************************************
 *  TITLE: LoRa control 4 Relays using NodeMCU ESP8266 with real-time feedback (Receiving end)
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/uWCY1CkvhR8
 *  Related Blog : https://iotcircuithub.com/esp8266-projects/
 *  by Tech StudyCell
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP8266 NodeMCU : https://github.com/esp8266/Arduino
 *  
 **********************************************************************************/

// define the GPIO connected with Relays and switches
#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14 //D5
#define RelayPin4 12 //D6

#define sLed   16   //D0

String incomingString;

void setup()
{
  Serial.begin(115200);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  pinMode(sLed, OUTPUT);


  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);

  digitalWrite(sLed, HIGH);
}

void loop()
{ 
  lora_control();
}

void lora_control(){
  
  if(Serial.available()) {
    incomingString = Serial.readString();
    digitalWrite(sLed, LOW);
    if(incomingString.indexOf("R1") >0) {
      digitalWrite(RelayPin1, !digitalRead(RelayPin1));
      Serial.println("AT+SEND=1,6,FR1");
    }
    else if(incomingString.indexOf("R2") >0) {
      digitalWrite(RelayPin2, !digitalRead(RelayPin2));
      Serial.println("AT+SEND=1,6,FR2");
    }
    else if(incomingString.indexOf("R3") >0) {
      digitalWrite(RelayPin3, !digitalRead(RelayPin3));
      Serial.println("AT+SEND=1,6,FR3");
    }
    else if(incomingString.indexOf("R4") >0) {
      digitalWrite(RelayPin4, !digitalRead(RelayPin4));
      Serial.println("AT+SEND=1,6,FR4");
    }
   delay(100);
   digitalWrite(sLed, HIGH);
 }
}
