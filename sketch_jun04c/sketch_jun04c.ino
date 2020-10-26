#include <Servo.h>

#define SERVO_UPPER_PIN	11
#define SERVO_LOWER_PIN	10

Servo upper;  //for upper servo motor
Servo lower;  //for lower servo motor

//previous position values
uint16_t upPos,lpPos;

//current position values
uint16_t uPos,lPos;

String dat;
int32_t data;

void setup() 
{
  Serial.begin(9600); //begin serial communication at 9600
  upper.attach(SERVO_UPPER_PIN);
  lower.attach(SERVO_LOWER_PIN);  
}
void loop() 
{
  if(Serial.available() > 0) 
  {
    dat=Serial.readString();
    data = dat.toInt();
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
}
