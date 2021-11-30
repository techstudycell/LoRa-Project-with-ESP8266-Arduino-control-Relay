/*************************************************************************************************************************************************
 *  TITLE: This is transmitter LoRa Arduino sketch to send and receive signal
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/uWCY1CkvhR8
 *  Related Blog : https://iotcircuithub.com/esp8266-projects/
 *  by Tech StudyCell
 *************************************************************************************************************************************************/

const int pLED = 13;
const int rLED = 7;
const int gLED = 8;

const int pSwitch_1 = 2;
const int pSwitch_2 = 3;
const int pSwitch_3 = 4;
const int pSwitch_4 = 5;

int i;
String incomingString;
boolean state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  
  pinMode(pSwitch_1, INPUT_PULLUP);
  pinMode(pSwitch_2, INPUT_PULLUP);
  pinMode(pSwitch_3, INPUT_PULLUP);
  pinMode(pSwitch_4, INPUT_PULLUP);

}

void getFeedback(String excpt_str){
  i = 0;
  incomingString = "";
  state = true;

  digitalWrite(gLED, LOW);
  digitalWrite(rLED, LOW);

  //Serial.print("Waiting for feedback");
  while(1){
    if(Serial.available()>0){
      incomingString = Serial.readString();
      if(incomingString.indexOf(excpt_str) > 0) {
        state = true; break;
      }
    }      
    if (i > 60) {
      state = false; break;
    }
    delay(100);
    digitalWrite(pLED, !digitalRead(pLED));
    i++;
    }

    if(state){
      digitalWrite(gLED, HIGH);
      digitalWrite(rLED, LOW);
      digitalWrite(pLED, LOW);
      //Serial.println("Received");
    }
    else{
      digitalWrite(gLED, LOW);
      digitalWrite(rLED, HIGH);
      digitalWrite(pLED, LOW);
      //Serial.println("Not Received");
    }    
}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(pSwitch_1) == LOW){
      Serial.println("AT+SEND=2,6,R1");
      getFeedback("FR1");
    }
  else if (digitalRead(pSwitch_2) == LOW){
      Serial.println("AT+SEND=2,6,R2");
      getFeedback("FR2");
    }
  else if (digitalRead(pSwitch_3) == LOW){
      Serial.println("AT+SEND=2,6,R3");
      getFeedback("FR3");
    }
  else if (digitalRead(pSwitch_4) == LOW){
      Serial.println("AT+SEND=2,6,R4");
      getFeedback("FR4");
    }
}
  
