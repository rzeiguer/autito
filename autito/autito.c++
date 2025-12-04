#include <Servo.h>
Servo miservo;

void setup() {
  miservo.attach(3);

}

void loop() {

  miservo.write(0);
  delay(2000);
  miservo.write(180);
  delay(2000);

}