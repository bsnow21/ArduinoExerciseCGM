// set delay time
// 30 sec/256 levels = 0.11719 sec/level
// random number generator used to get as close to 0.11719 sec/level as possible
int getDelayTime()
{
  int rand = random(1,100);
  // if random number between 1-81, set delay to 117 ms
  if (rand <= 81)
  {
    delayTime = 117;
  }
  // if random number between 82-100, set delay to 118 ms
  else
  {
    delayTime = 118;
  }
  return delayTime;
}
