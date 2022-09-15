
#define REDLED 2
#define SEC_1 1000
#define SEC_05 500

void setup() {
  
  Serial.begin(9600);
  pinMode(REDLED, OUTPUT);
}

void loop() {
  
  Serial.println(REDLED);
  blink(REDLED);
}

void blink(int ledPort){
  digitalWrite(ledPort, HIGH);
  delay(SEC_1);
  digitalWrite(ledPort, LOW);
  delay(SEC_05);
}
