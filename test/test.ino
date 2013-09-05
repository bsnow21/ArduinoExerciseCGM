int button1 = A0;
int button2 = A1;
int led = 3;

boolean lastButton1 = LOW;
boolean lastButton2 = LOW;
boolean currentButton1 = LOW;
boolean currentButton2 = LOW;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  currentButton1 = debounce1(lastButton1);
  if (currentButton1 == 1)
  {
    digitalWrite(led,HIGH);
  }
  
  currentButton2 = debounce2(lastButton2);
  if (currentButton2 == 1)
  {
    digitalWrite(led,LOW);
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
