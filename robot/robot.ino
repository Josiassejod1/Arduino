# include <Servo.h>
Servo batman;
Servo robin;

void setup() {
  // put your setup code here, to run once:
 batman.attach(2);
 robin.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
    batman.write(0);
    robin.write(0);
    delay(1000);
    batman.write(70);
    delay(1000);
    batman.write(90);
    robin.write(90);
    delay(1000);
    batman.write(180);
    robin.write(179);
}
