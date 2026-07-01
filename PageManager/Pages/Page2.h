#pragma once

#include <Arduino.h>

#include "./IPage.h"
#include "../helpers/IntervalTimer.h"
#include "../display_wrapper.h"

class Page2 : public IPage
{
private:
  IntervalTimer counterTimer;

public:
  Page2(void)
      : counterTimer(500)
  {
  }

  void run(void)
  {

    if (counterTimer.ready())
    {

      g_clear_display();

      g_show_text(10, 30, "[page 2]");

      g_update_display();
    }
  }
};