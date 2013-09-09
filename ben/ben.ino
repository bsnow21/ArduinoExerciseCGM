// Inititialize the I/O ports
int button1 = A0;
int button2 = A1;
int led = 3;

// Initialize time variables
double PrevTime = 0;
double NewTime = 0;
double TotalTime = 0;
double ChangeTime = 0;
int ledLevel = 0;

// Initialize buttons
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;

// Set up the I/O
void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600); // Initializes Serial Monitor for debugging
}

void loop()
{
  // Read button presses with debouncing
  currentButton1 = debounce1(lastButton1);
  currentButton2 = debounce2(lastButton2);
  
  // Calculate the amount of time the button has been pressed
  NewTime = millis();
  ChangeTime = NewTime - PrevTime;
  PrevTime = NewTime;
  ledLevel = round(TotalTime*255/30000);
  Serial.println(TotalTime);
  
  // Go into a loop of blinking after 30 seconds
  if (currentButton1 == 1 && TotalTime == 30000)
  {
    endlessLoop();
  }
  else if (currentButton1 == 1)
  {
    if(TotalTime + ChangeTime<=30000){    
      TotalTime += ChangeTime; //Add the time the button has been pressed to the total
    }
    else TotalTime = 30000;
  }
  
  if (currentButton2 == 1)
  {
    if(TotalTime - ChangeTime>=0){
      TotalTime = TotalTime - ChangeTime; //Subtract the time the button has been pressed from the total
    }
    else TotalTime = 0;
  }
  if(currentButton2 == 1 && currentButton1 ==1){
  TotalTime = random(0,30000);// Set the LED to a random level
  }
  analogWrite(led,ledLevel);
  delay(100);
}

void endlessLoop()
{
  while(0==0)
  {
    //Endlessly turn the LED on/off every second
    analogWrite(led,0);
    delay(1000);
    analogWrite(led,255);
    delay(1000);
  }
}


boolean debounce1(boolean last)
{

  boolean current = digitalRead(button1);
  if(last !=current)
  {
    delay(5); //long enough for switch to finish bouncing, not too long to let your finger hit

    current = digitalRead(button1);
  }
  return current;
}

boolean debounce2(boolean last)
{

  boolean current = digitalRead(button2);
  if(last !=current)
  {
    delay(5); //long enough for switch to finish bouncing, not too long to let your finger hit

    current = digitalRead(button2);
  }
  return current;
}
