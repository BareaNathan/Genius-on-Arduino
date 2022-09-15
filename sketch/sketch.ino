//Porta 2 não deve ser variável, correção para definir valor fixo de redLed
//int redLed = 2;
#define REDLED 2
#define SEC_1 1000
#define SEC_05 500

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(REDLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(REDLED);
  blink(REDLED);
  //redLed++;
}

void blink(int ledPort){
  digitalWrite(ledPort, HIGH);
  delay(SEC_1);
  digitalWrite(ledPort, LOW);
  delay(SEC_05);
}
