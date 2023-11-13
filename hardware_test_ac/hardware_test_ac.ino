const int DES_TEMP = 8;
const int CUR_TEMP = 7;
const int AC_OUT = 5;

const int BUTTON = 4;

const int DIAL = A1;


void setup() {
  pinMode(DES_TEMP, OUTPUT);
  pinMode(CUR_TEMP, OUTPUT);
  pinMode(AC_OUT, OUTPUT);
  pinMode(BUTTON, INPUT);

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
  
  if (i < 5) {
    digitalWrite(DES_TEMP, HIGH);
    digitalWrite(CUR_TEMP, LOW);
    digitalWrite(AC_OUT, LOW);  
    i++;
  } else if (i < 10) {
    digitalWrite(DES_TEMP, LOW);
    digitalWrite(CUR_TEMP, HIGH);
    digitalWrite(AC_OUT, LOW);
    i++;
  } else {
    digitalWrite(DES_TEMP, LOW);
    digitalWrite(CUR_TEMP, LOW);
    digitalWrite(AC_OUT, HIGH);
    i++;
    if (i == 15) {
      i = 0;
    }
  }
  if (i % 2 == 0) {
    Serial1.write("cs 1600", 8);
  }
  delay(100);
}
