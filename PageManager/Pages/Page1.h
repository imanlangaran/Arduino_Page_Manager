#pragma once

#include <Arduino.h>

#include "./IPage.h"
#include "../helpers/IntervalTimer.h"

class Page1 : public IPage
{
private:
  bool printed;
  uint8_t counter;

  IntervalTimer counterTimer;

public:
  Page1(void)
      : counterTimer(100)
  {
    printed = false;
    counter = 0;
  }

  void run(void)
  {
    if (!printed)
    {
      Serial.println("[page1] hellow there only once...");
      printed = true;
    }

    if (counterTimer.ready())
    {
      addCounter();
    }
  }

  void addCounter()
  {
    counter++;
    Serial.print("[page1] counter: ");
    Serial.println(counter);
  }

  void stop()
  {
    counterTimer.stop();
  }

  void start()
  {
    counterTimer.start();
  }
};