int b4 = 12;
int b5 = 13;
int b3 = 11;
int b0 = 8;
const float tempOutside = 9;
const float tempUp = 6;
const float tempDown = 7;

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

}

void loop() {
   while(Serial.available()) {

       command= Serial.readString();// read the incoming data as string

       if(command == "1"){//serial command 1 to turn on burglar alarm
         burglarAlarmLampOn();
         Serial.println("Burglar alarm on");//serial output to pi
       }else if(command == "2"){//serial input from pi: command 2 to turn off burglar alarm 
         burglarAlarmLampOff();
         Serial.println("Burglar alarm off");//serial output to pi
       }else if(command == "3"){//serial input from pi: command 3 to turn on firealarm alarm 
         turnAlarmOn();
         Serial.println("Fire alarm on");//serial output to pi
       }else if(command == "4"){//serial input from pi: command 4 to turn off firealarm alarm 
         turnAlarmOff();
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
       }else if(command == "10"){
        getTempOutside();
       }else if(command == "11"){
        getTempInside();
       }else if(command == "14"){//serial input from pi: command 13 to check if burglar alarm is on 
          isBurglarAlarmOn();
       }else if(command == "15"){//serial input from pi: command 14 to check if fire alarm is on 
         isAlarmOn();
       }else if(command == "16"){//serial input from pi: command 15 to check if outside lamp is on 
         isOutsideLampOn();
       }else if(command == "17"){//serial input from pi: command 16 to check if indoor lamp is on 
         isIndoorLampOn();
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
void turnAlarmOn(){
  digitalWrite(b4, HIGH);
  digitalWrite(b5, LOW);
  digitalWrite(b3, LOW);
  digitalWrite(b0, LOW);  
}
void turnAlarmOff(){
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
}
