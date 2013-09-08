int button1 = A0;
int button2 = A1;
int led = 3;
int PrevTime = 0;
int NewTime = 0;
int TotalTime = 0;
int ChangeTime = 0;

boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;

int ledLevel = 0;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  currentButton1 = debounce1(lastButton1);
  NewTime = millis();
  ChangeTime = NewTime - PrevTime;
  PrevTime = NewTime;
  ledLevel = round(TotalTime/30000*255);
  Serial.println(ledLevel);
  if (currentButton1 == 1 && ledLevel == 254)
  {
    endlessLoop();
  }
  else if (currentButton1 == 1)
  {
    if(TotalTime + ChangeTime<=255){    
      TotalTime += ChangeTime;
    }
    else TotalTime = 30000;
  }
  
  currentButton2 = debounce2(lastButton2);
  if (currentButton2 == 1)
  {
    if(TotalTime - ChangeTime>=0){
      TotalTime = TotalTime - ChangeTime;
    }
    else TotalTime = 0;
  }
  
  analogWrite(led,ledLevel);
  delay(100);
}

void endlessLoop()
{
  while(0==0)
  {
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
