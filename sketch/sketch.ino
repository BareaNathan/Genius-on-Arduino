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

enum States{
  READY_FOR_NEXT_ROUND,
  USER_INTERACT,
  GAME_OVER_SUCCESS,
  GAME_OVER_FAIL
};

int lightSequence[SEQUENCE_SIZE];

int gameRound = 0;

int buttonPress = 0;

void setup() {
  Serial.begin(9600);
  portConfig();
  gameStart();
}

void gameStart(){
  int randomNumberGenerator = analogRead(0);
  randomSeed(randomNumberGenerator);
  for(int index = 0; index < SEQUENCE_SIZE; index++){
    lightSequence[index] = collordraw();
  }
}

int collordraw(){
  return random(GREENLED,BLUELED + 1);
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
  switch(actualState()){
    case READY_FOR_NEXT_ROUND:
      prepareNextRound();
      break;
    case USER_INTERACT:
      userInputChecker();
      break;
    case GAME_OVER_SUCCESS:
      gameOverSuccess();
      break;
    case GAME_OVER_FAIL:
      gameOverFail();
      break;
  }
  delay(500);
}

void userInputChecker(){
  int response = buttonPressedCheck();

  if (response == UNDEFINED){
    return;
  }

  if (response == lightSequence[buttonPress]){
    buttonPress++;
  } else {
    gameRound = SEQUENCE_SIZE + 2;
  }
}

void prepareNextRound(){
  gameRound++;
  buttonPress = 0;
  if(gameRound <= SEQUENCE_SIZE){
    playround();
  }
}

int actualState(){
  if(gameRound <= SEQUENCE_SIZE){
    if(buttonPress == gameRound){
      return READY_FOR_NEXT_ROUND;
    } else {
      return USER_INTERACT;
    }
  } else if(gameRound == SEQUENCE_SIZE + 1){
    return GAME_OVER_SUCCESS;
  } else {
    return GAME_OVER_FAIL;
  }
}

void playround(){
    for(int index = 0; index < gameRound; index++){
    blink(lightSequence[index]);
  }
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

void gameOverSuccess(){
  blink(GREENLED);
  blink(YELLOWLED);
  blink(REDLED);
  blink(BLUELED);
  delay(SEC_05);
}

void gameOverFail(){
  digitalWrite(GREENLED, HIGH);
  digitalWrite(YELLOWLED, HIGH);
  digitalWrite(REDLED, HIGH);
  digitalWrite(BLUELED, HIGH);
  delay(1000);
  digitalWrite(GREENLED, LOW);
  digitalWrite(YELLOWLED, LOW);
  digitalWrite(REDLED, LOW);
  digitalWrite(BLUELED, LOW);
  delay(500);
}

int blink(int ledPort){
  digitalWrite(ledPort, HIGH);
  delay(SEC_1);
  digitalWrite(ledPort, LOW);
  delay(SEC_05);
  return ledPort;
}
