#include <Servo.h>
Servo upper;  //for upper servo motor
Servo lower;  //for lower servo motor
int upPos,lpPos;
void setup() {
  Serial.begin(9600); //begin serial communication at 9600
  upper.attach(11);
  lower.attach(10);  
}
void loop() {
  int uPos,lPos;
  if(Serial.available() > 0) {
    String dat=Serial.readString();
    long signed int data = dat.toInt();
    uPos=data%1000;
    lPos=data/1000;
    upPos=uPos;
    lpPos=lPos;
  }
  else
  {
    uPos=upPos;
    lPos=lpPos;
  }
    upper.write(uPos);
    lower.write(lPos);
    /*upper.write(0);
    lower.write(0);
    delay(10);*/
}
