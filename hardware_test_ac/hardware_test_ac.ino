const int DES_TEMP = 9;
const int CUR_TEMP = 5;
const int AC_OUT = 3;

const int BUTTON = 7;

const int DIAL = A1;


void setup() {
  pinMode(AC_OUT, OUTPUT);
  pinMode(BUTTON, INPUT);
  analogWriteResolution(8);
  analogReadResolution(10);

  Serial.begin(9600);
  while(!Serial);
  Serial1.begin(9600);
}

void loop() {
  static int i = 0;
  
  Serial.print("pot: ");
  Serial.println(analogRead(DIAL));
  Serial.print("button: ");
  Serial.println(digitalRead(BUTTON));
  
  if (i < 4) {
    analogWrite(DES_TEMP, 0);
    analogWrite(CUR_TEMP, 255);
    digitalWrite(AC_OUT, LOW);  
    i++;
  } else if (i < 8) {
    analogWrite(DES_TEMP, 127);
    analogWrite(CUR_TEMP, 127);
    digitalWrite(AC_OUT, LOW);
    i++;
  } else if (i < 12) {
    analogWrite(DES_TEMP, 255);
    analogWrite(CUR_TEMP, 0);
    digitalWrite(AC_OUT, HIGH);
    i++;
  } else {
    analogWrite(DES_TEMP, 127);
    analogWrite(CUR_TEMP, 127);
    digitalWrite(AC_OUT, HIGH);
    i++;
    if (i == 16) {
      i = 0;
    }
  }
  if (i % 2 == 0) {
    Serial1.write("cs 1600", 8);
  }
  delay(100);
}
