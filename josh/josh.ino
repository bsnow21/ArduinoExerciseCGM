int button1 = A0;
int button2 = A1;
int led = 3;

boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;

int ledLevel = 0;
int delayTime = 117;

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
  if (currentButton1 == 1 && ledLevel == 254)
  {
    endlessLoop();
  }
  else if (currentButton1 == 1)
  {
    ledLevel++;
  }
  
  currentButton2 = debounce2(lastButton2);
  if (currentButton2 == 1 && ledLevel != 0)
  {
    ledLevel = ledLevel - 1;
  }
  int x = millis();
  Serial.println(x);
  analogWrite(led,ledLevel);
  delay(delayTime);
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
