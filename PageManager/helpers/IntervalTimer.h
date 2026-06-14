#pragma once

#include <Arduino.h>

class IntervalTimer
{
private:
  unsigned long interval;
  unsigned long lastRunTime;
  bool active;

public:
  IntervalTimer(unsigned long intervalMs)
  {
    interval = intervalMs;
    lastRunTime = 0;
    active = true;
  }

  bool ready()
  {
    if (!active)
      return false;

    unsigned long now = millis();

    if (now - lastRunTime >= interval)
    {
      lastRunTime = now;
      return true;
    }

    return false;
  }

  void stop()
  {
    active = false;
  }

  void start()
  {
    active = true;
    lastRunTime = millis();
  }

  void reset()
  {
    lastRunTime = millis();
  }
};