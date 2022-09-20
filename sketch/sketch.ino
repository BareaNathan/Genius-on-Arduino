#define GREENLED 2
#define YELLOWLED 3
#define REDLED 4
#define BLUELED 5
#define UNDEFINED -1

#define GREENBUTTON 8 
#define YELLOWBUTTON 9
#define REDBUTTON 10
#define BLUEBUTTON 11

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

  pinMode(GREENBUTTON, INPUT_PULLUP);
  pinMode(YELLOWBUTTON, INPUT_PULLUP);
  pinMode(REDBUTTON, INPUT_PULLUP);
  pinMode(BLUEBUTTON, INPUT_PULLUP);

}

void loop() {
  for(int index = 0; index < SEQUENCE_SIZE; index++){
    blink(lightSequence[index]);
  }
  Serial.println(buttonPressedCheck());
}

int buttonPressedCheck(){
  if(digitalRead(GREENBUTTON) == LOW){
    return blink(GREENLED);
  }
  if(digitalRead(YELLOWBUTTON) == LOW){
    return blink(YELLOWLED);
  }
  if(digitalRead(REDBUTTON) == LOW){
    return blink(REDLED);
  }
  if(digitalRead(BLUEBUTTON) == LOW){
    return blink(BLUELED);
  }
  return UNDEFINED;
}

void testSequence1(){
  blink(GREENLED);
  blink(YELLOWLED);
  blink(REDLED);
  blink(BLUELED);
  delay(SEC_05);
}

int blink(int ledPort){
  digitalWrite(ledPort, HIGH);
  delay(SEC_1);
  digitalWrite(ledPort, LOW);
  delay(SEC_05);
  return ledPort
}
