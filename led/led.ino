int led3 = 53;

void setup() {

  pinMode(led3, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
  delay(1000);
    // put your main code here, to run repeatedly:
  digitalWrite(led3, HIGH);
  delay(1000);
  digitalWrite(led3, LOW);
}
