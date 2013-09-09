// flashing sequence after led values has reached 255
void endlessLoop()
{
  // continuosuly on
  while(0==0)
  {
    // set led off for .5 sec
    analogWrite(led,0);
    delay(500);
    // set led on for .5 sec
    analogWrite(led,255);
    delay(500);
  }
}
