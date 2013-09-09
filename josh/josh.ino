// Lab Design Exercise: Time Integration
// Team CleanGreenMachine

// initialize button and led inputs/outputs
int button1 = A0;
int button2 = A1;
int led = 3;

// set initial button values
boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;

// set initial led level
int ledLevel = 0;
int delayTime;

void setup()
{
  // set input/output pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  // begin recording how long the iteration takes
  int timeStart = millis();
  
  // set delay time
  // 30 sec/256 levels = 0.11719 sec/level
  // random number generator used to get as close to 0.11719 sec/level as possible
  int rand = random(1,100);
  if (rand <= 81)
  {
    delayTime = 117;
  }
  else
  {
    delayTime = 118;
  }
  
  // determine "UP" button state
  currentButton1 = debounce1(lastButton1);
  
  // if "UP" is pressed and current led level is 254, start the flashing sequence
  if (currentButton1 == 1 && ledLevel == 254)
  {
    endlessLoop();
  }
  // if "UP" is pressed otherwise, increase led level by 1
  else if (currentButton1 == 1)
  {
    ledLevel++;
  }
  
  // determine "DOWN" button state
  currentButton2 = debounce2(lastButton2);
  
  // if "DOWN" is pressed and current led level isn't 0, decrease led level by 1
  if (currentButton2 == 1 && ledLevel != 0)
  {
    ledLevel = ledLevel - 1;
  }
  
  // if both "UP" and "DOWN" are pressed, reset the led level to 0
  if (currentButton1 == 1 && currentButton2 == 1)
  {
    ledLevel = 0;
  }

  // set the correct led level
  analogWrite(led,ledLevel);
  
  // stop recording how long the iteration takes
  int timeEnd = millis();
  
  // determine how long the iteration takes
  int timeTotal = timeEnd - timeStart;

  // change the delay time if the iteration time isn't negligible (if > 1 ms)
  delay(delayTime-timeTotal);
}

// flashing sequence
void endlessLoop()
{
  // continuosuly on
  while(0==0)
  {
    // set led off for 1 sec
    analogWrite(led,0);
    delay(1000);
    // set led on for 1 sec
    analogWrite(led,255);
    delay(1000);
  }
}

// determine "UP" button state
boolean debounce1(boolean last)
{
  // read button state
  boolean current = digitalRead(button1);
  // if the button state has changed
  if(last !=current)
  {
    delay(5); //long enough for switch to finish bouncing, not too long to let your finger hit
    
    // set current button value
    current = digitalRead(button1);
  }
  return current;
}

// determine "DOWN" button state
boolean debounce2(boolean last)
{
  // read button state
  boolean current = digitalRead(button2);
  // if the button state has changed
  if(last !=current)
  {
    delay(5); //long enough for switch to finish bouncing, not too long to let your finger hit

    // set current button value
    current = digitalRead(button2);
  }
  return current;
}
