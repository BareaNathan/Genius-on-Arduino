
#define GREENLED 2
#define YELLOWLED 3
#define REDLED 4
#define BLUELED 5

#define SEC_1 1000
#define SEC_05 500

#define SEQUENCE_SIZE 4

int lightSequence[SEQUENCE_SIZE];

void setup() {
  
  Serial.begin(9600);
  portConfig();
  gameStart();
}

void gameStart(){
  lightSequence[0] = BLUELED;
  lightSequence[1] = GREENLED;
  lightSequence[2] = REDLED;
  lightSequence[3] = YELLOWLED;
}

void portConfig(){
  pinMode(GREENLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
}

void loop() {
  for(int index = 0; index < SEQUENCE_SIZE; index++){
    blink(lightSequence[index]);
  }
}

void testSequence1(){
  blink(GREENLED);
  blink(YELLOWLED);
  blink(REDLED);
  blink(BLUELED);
  delay(SEC_05);
}

void blink(int ledPort){
  digitalWrite(ledPort, HIGH);
  delay(SEC_1);
  digitalWrite(ledPort, LOW);
  delay(SEC_05);
}
