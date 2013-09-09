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
