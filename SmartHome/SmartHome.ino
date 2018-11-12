int b4 = 12;
int b5 = 13;
int b3 = 11;
int b0 = 8;
const float tempOutside = 9;
const float tempUp = 6;
const float tempDown = 7;
const int fire = D2;
const int waterLeak = D4;
const int stove = D5;
const int window = D6;
String command;

void setup() {
 Serial.begin(9600);  
 pinMode(b4, OUTPUT);
 pinMode(b5, OUTPUT);
 pinMode(b3, OUTPUT);
 pinMode(b0, OUTPUT);
 pinMode(tempOutside, INPUT); 
 pinMode(tempUp, INPUT);
 pinMode(tempDown, INPUT);
 pinMode(fire, INPUT);
 pinMode(waterLeak, INPUT);
 pinMode(stove, INPUT);
 pinMode(window, INPUT);
}

void loop() {
   while(Serial.available()) {

    command= Serial.readString();// read the incoming data as string
    
    //constantly checking if;
    isFire(); //there is a fire
    isWaterleak(); //water leak

    if(command == "1"){//serial command 1 to turn on burglar alarm
      burglarAlarmLampOn();
      Serial.println("Burglar alarm on");//serial output to pi
    }else if(command == "2"){//serial input from pi: command 2 to turn off burglar alarm 
      burglarAlarmLampOff();
      Serial.println("Burglar alarm off");//serial output to pi
    }else if(command == "3"){//serial input from pi: command 3 to turn on firealarm alarm 
      turnFireAlarmOn();
      Serial.println("Fire alarm on");//serial output to pi
    }else if(command == "4"){//serial input from pi: command 4 to turn off firealarm alarm 
      turnFireAlarmOff();
      Serial.println("Fire alarm off");//serial output to pi
    }else if(command == "5"){//serial input from pi: command 5 to turn on outside lamp 
      turnOutsideLampOn();
      Serial.println("Lamp outside on");//serial output to pi
    }else if(command == "6"){//serial input from pi: command 6 to turn off outside lamp 
      turnOutsideLampOff();
      Serial.println("Lamp outside off");//serial output to pi
    }else if(command == "7"){//serial input from pi: command 7 to turn on indoor lamp 
      turnIndoorLampOn();
      Serial.println("Lamp inside on");//serial output to pi
    }else if(command == "8"){//serial input from pi: command 8 to turn off indoor lamp 
      turnIndoorLampOff();
      Serial.println("Lamp inside off");//serial output to pi
    }else if(command == "10"){//serial input from pi: command 10 to check temperature outside
     getTempOutside();
    }else if(command == "11"){//serial input from pi: command 11 to check temperature inside
     getTempInside();
    }else if(command == "14"){//serial input from pi: command 14 to check if burglar alarm is on 
       isBurglarAlarmOn();
    }else if(command == "15"){//serial input from pi: command 15 to check if fire alarm is on 
      isAlarmOn();
    }else if(command == "16"){//serial input from pi: command 16 to check if outside lamp is on 
      isOutsideLampOn();
    }else if(command == "17"){//serial input from pi: command 17 to check if indoor lamp is on 
      isIndoorLampOn();
    }else if(command == "20"){ //serial input from pi: command 20 to check the state of the house FIRE, Water Leak, Stove, Window
     checkStateOfHouse();
    }else {//serial input from pi (no such command known)
      Serial.println("Not known command"); //serial output to pi
    }
   }
}
void turnOutsideLampOn(){
  digitalWrite(b4, LOW);
  digitalWrite(b5, HIGH);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, HIGH);  
}
void turnOutsideLampOff(){
  digitalWrite(b4, HIGH);
  digitalWrite(b5, HIGH);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, HIGH);   
}
void isOutsideLampOn(){
  if((digitalRead(b4)==LOW)&&(digitalRead(b5)==HIGH)&&
  (digitalRead(b3)==HIGH&&(digitalRead(b0)==HIGH))){
    Serial.println("Outside lamp is on");//serial output to pi
  }else{
    Serial.println("Outside lamp is off");//serial output to pi
  }
}
void turnIndoorLampOn(){
  digitalWrite(b4, LOW);
  digitalWrite(b5, LOW);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, LOW);    
}
void turnIndoorLampOff(){
  digitalWrite(b4, HIGH);
  digitalWrite(b5, LOW);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, LOW);  
}
void isIndoorLampOn(){
  if((digitalRead(b4)==LOW)&&(digitalRead(b5)==LOW)&&
  (digitalRead(b3)==HIGH)&&(digitalRead(b0)==LOW)){
    Serial.println("Indoor lamp is on");//serial output to pi
  }else{
    Serial.println("Indoor lamp is off");//serial output to pi
  }
}
void turnFireAlarmOn(){
  digitalWrite(b4, HIGH);
  digitalWrite(b5, LOW);
  digitalWrite(b3, LOW);
  digitalWrite(b0, LOW);  
}
void turnFireAlarmOff(){
  digitalWrite(b4, LOW);
  digitalWrite(b5, LOW);
  digitalWrite(b3, LOW);
  digitalWrite(b0, LOW);  
}
void isAlarmOn(){
  if((digitalRead(b4)==HIGH)&&(digitalRead(b5)==LOW)&&
  (digitalRead(b3)==LOW)&&(digitalRead(b0)==LOW)){
    Serial.println("Fire alarm is on");//serial output to pi
  }else{
    Serial.println("Fire alarm is off");//serial output to pi
  }
}
void burglarAlarmLampOn(){
  digitalWrite(b4, LOW);
  digitalWrite(b5, LOW);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, HIGH); 
}
void burglarAlarmLampOff(){
  digitalWrite(b4, HIGH);
  digitalWrite(b5, LOW);
  digitalWrite(b3, HIGH);
  digitalWrite(b0, HIGH);
}
void isBurglarAlarmOn(){
  if((digitalRead(b4)==LOW)&&(digitalRead(b5)==LOW)&&
  (digitalRead(b3)==HIGH)&&(digitalRead(b0)==HIGH)){
    Serial.println("Burglar alarm is on");//serial output to pi
  }else{
    Serial.println("Burglar alarm is off");//serial output to pi
  }
}
 void getTempOutside(){
  float temp = digitalRead(temoPutside);
  Serial.print("Temperature outside: ");//serial output to pi
  Serial.println(temp/2);
 }
 void getTempInside(){
  float tempUp = analogRead(tempUp);
  float mv = ( tempUp/1024.0)*5000; 
  float cel = mv/10;
  float tempDown = analogRead(tempDown);
  float mv1 = ( tempDown/1024.0)*5000; 
  float cel1 = mv/10;
  Serial.print("Temperature upstairs: ");//serial output to pi
  Serial.println(cel);
  Serial.print("Temperature downstairs: ");
  Serial.println(cel1);
 }
 void isFire(){
  if(digitalRead(fire)==LOW){
   turnFireAlarmOn();
   Serial.println("FIRE!!");   //serial output to pi
  }
 }
 void isWaterleak(){
  if(digitalRead(waterLeak)==LOW){
   Serial.println("WATER LEAK!!");   //serial output to pi
  }
 }
 void checkFireState(){
  if(digitalRead(fire)==LOW){
   turnFireAlarmOn();
   Serial.println("FIRE!! : 1");   //serial output to pi
  }else{
   turnFireAlarmOff();
   Serial.println("No fire : 2");
  }
 }
 void checkWaterleakState(){
  if(digitalRead(waterLeak)==LOW){
   Serial.println("WATER LEAK!! : 1");   //serial output to pi
  }else{
   Serial.println("No waterleak : 2");
  }
 }
 void checkStoveState(){
  if(digitalRead(stove)==LOW){
   Serial.println("Stove ON.");   //serial output to pi
  }else{
   Serial.println("Stove OFF."); 
  }
 }
 void checkWindowState(){
  if(digitalRead(window)==LOW){
   Serial.println("Window OPEN.");   //serial output to pi
  }else{
   Serial.println("Window Closed."); 
  }
 }
void checkStateOfHouse(){
 Serial.print("Starting check...");  //serial output to pi
 checkFireState();
 checkWaterleakState();
 checkStoveState();
 checkWindowState();
 Serial.println("Check complete.");
}
}
