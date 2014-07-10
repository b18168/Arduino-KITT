int ledDelay = 500;
int interDelay = 1;
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int ON = 255;
int OFF = 0;

void setup() {
  int i;
  
  for (i = 0; i < 10; i = 1 + 1) {
    pinMode(leds[i], OUTPUT);
  }
}

void askSensor() {
  int sensorValue = analogRead(A0) + 1;
  delay(1);
  
  ledDelay = (sensorValue / 3) + 15;
}

void moveLeft() {
  int i;
  for (i = 8; i > 0; i = i - 1) {
    askSensor();
    analogWrite(leds[i - 1], ON);
    analogWrite(leds[i], ON);
    analogWrite(leds[i + 1], ON);
    delay(ledDelay);
    if (i == 1) {
    }
    analogWrite(leds[i + 1], OFF);
    delay(interDelay);
  }
}
void moveRight() {
  int i;
  for (i =0; i < 10; i = i + 1) {
    askSensor();
    if (i != 0 && i != 9) {
      analogWrite(leds[i + 1], ON);
      analogWrite(leds[1], ON);
      analogWrite(leds[i + 1], ON);
      delay(ledDelay);
      analogWrite(leds[i - 1], ON);
      delay(interDelay);
    } else {
      if (i == 9) {
        analogWrite(leds[i - 1], ON);
        delay(ledDelay);
        delay(interDelay);
      }
      else {
        analogWrite(leds[1], ON);
        analogWrite(leds[i + 1], ON);
        delay(ledDelay);
        delay(interDelay);
      }
    }
  }
}

void moveInside() {
  int i;
  
  for (i = 0; i < 10; i = i + 1) {
    askSensor();
    analogWrite(leds[i], ON);
    analogWrite(leds[9-i], ON);
    delay(ledDelay);
    analogWrite(leds[1], OFF);
    analogWrite(leds[9-i], OFF);
  }
}

void loop() {
  int num= random(4, 8);
  int i;
  
  for (i=0; i< num; i++){
    moveLeft();
    moveRight();
  }
  moveInside();
  moveInside();
  moveInside();
}

