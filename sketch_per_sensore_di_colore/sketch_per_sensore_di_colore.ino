#include <Servo.h>
Servo servo_1;//serve per classificare il servo motre 1 chiamandolo servo_1
int move;
int valbutton;
int valbuttonold=LOW;
void setup() {
  servo_1.attach(5);// serve per dire quale pin lo governa
  pinMode(10,INPUT);
}

void loop() {
  valbutton= digitalRead(10);
  if (valbutton==HIGH && valbuttonold==LOW){
    move=analogRead(A0);
    map(move,0,1023,0,180);
    servo_1.write(move);
  }
  valbuttonold=valbutton;
  
}