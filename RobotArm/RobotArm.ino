#include <Servo.h>

Servo myservo;

const int SERVO_PIN = 9;

// Based on your image:
const int JOY_X_PIN = A3;  // VRx
const int JOY_Y_PIN = A2;  // VRy (optional)
const int JOY_SW_PIN = A1; // SW (optional)

int angle = 90;            // start centered
const int deadzone = 25;   // joystick center wiggle (tweak 10-50)
const float alpha = 0.15;  // smoothing (0.05-0.3)

float filtered = 512;

void setup() {
  myservo.attach(SERVO_PIN);

  pinMode(JOY_SW_PIN, INPUT_PULLUP); // joystick button usually pulls LOW when pressed
  myservo.write(angle);
}

void loop() {
  int raw = analogRead(JOY_X_PIN);   // use X axis to control servo

  // smooth the reading
  filtered = (alpha * raw) + ((1.0 - alpha) * filtered);

  // optional deadzone around center to reduce jitter
  int centered = (int)filtered - 512;
  if (abs(centered) < deadzone) centered = 0;

  // map to servo angle
  // clamp input back into 0..1023 after deadzone adjustment
  int adjusted = constrain(512 + centered, 0, 1023);
  angle = map(adjusted, 0, 1023, 0, 180);

  myservo.write(angle);

  // OPTIONAL: press joystick button to snap to center
  if (digitalRead(JOY_SW_PIN) == LOW) {
    myservo.write(90);
    delay(200);
  }

  delay(10);
}
