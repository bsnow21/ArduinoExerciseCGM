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
