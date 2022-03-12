#include "configs.h"
using namespace Pomodoro;

Timer pomodoro(REST_PIN, WAIT_PIN, WORK_PIN, configs::timeFunc);

void pressed()
{
  pomodoro.change();
}

void setup()
{
  configs::check_debug(); //must be used before Timer.setUp
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(0, pressed, FALLING);
  pomodoro.setUp(configs::rest_time, configs::work_time);
}

void loop()
{
  tone(SPEAKER, BEEP_FEQUENCY, BEEP_DURATION);
  delay(BEEP_DURATION);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_ON);
}
