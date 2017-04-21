#include <Servo.h>
Servo servo1;
Servo servo2;
int servoPin = 8;
Servo servo;
String in;
int angle = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(5);
  servo.attach(servoPin);
  servo2.attach(3);
  Serial1.begin(9600);
}

void loop() {
  while (Serial1.available() > 0) {
    in = Serial1.read();
    Serial.println(in);
  }
  if (in == int("G") or in == "71") {
    servoSetAngle();
    delay(1000);
    servoBall();
    lighter();
  }
  else {
    servoSpin();
  }

}

void servoBall() {
  for (int pos = 0; pos <= 120; pos += 1) {
    servo2.write(pos);
    delay(15);
  }
}

void servoSpin() {
  servo1.write(0);
}

void servoSetAngle() {
  servo1.write(30);
}
void lighter() {
  for (angle = 0; angle < 210; angle++)
  {
    servo.write(angle);
    delay(15);
  }
  //now scan back from 180 to 0 degrees
  for (angle = 210; angle > 0; angle--)
  {
    servo.write(angle);
    delay(15);
  }

}


