// initialize button and led inputs/outputs
int button1 = A0;
int led = 3;

// set initial button values
boolean lastButton1 = LOW;
boolean currentButton1 = LOW;

void setup()
{
  // set input/output pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led,OUTPUT);
  
  // set up serial monitor
  Serial.begin(9600);
}

void loop()
{
  // set up random time for led to go off
  int randTime = random(5,10);
  delay(randTime*1000);
  analogWrite(led,255);
  
  // start recording user's reaction time
  int timeStart = millis();
  while(0==0)
  {
    // determine if "UP" button is pressed
    currentButton1 = debounce1(lastButton1);
    if (currentButton1 == 1)
    {
      // stop time if "UP" button is pressed
      int timeEnd = millis();
      
      // determine total reaction time
      int timeTotal = timeEnd - timeStart;
      Serial.println(timeTotal);
    }
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
