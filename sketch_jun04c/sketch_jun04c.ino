#include <Servo.h>

#define SERVO_UPPER_PIN	11
#define SERVO_LOWER_PIN	10

Servo upper;  //for upper servo motor
Servo lower;  //for lower servo motor
uint16_t upPos,lpPos;

void setup() {
  Serial.begin(9600); //begin serial communication at 9600
  upper.attach(SERVO_UPPER_PIN);
  lower.attach(SERVO_LOWER_PIN);  
}
void loop() {
  uint16_t uPos,lPos;
  if(Serial.available() > 0) {
    String dat=Serial.readString();
    int32_t data = dat.toInt();
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
