#pragma once

#include <Arduino.h>

#include "./IPage.h"
#include "../helpers/IntervalTimer.h"
#include "../display_wrapper.h"

class Page1 : public IPage
{
private:
  bool printed;
  uint8_t counter;

  IntervalTimer counterTimer;

public:
  Page1(void)
      : counterTimer(500)
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

      g_clear_display();

      g_show_text(10, 30, "[page 1]");
      g_show_number(10, 50, counter);

      g_update_display();
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