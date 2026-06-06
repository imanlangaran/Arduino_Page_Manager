#pragma once

#include <Arduino.h> // Add this line

#include "./IPage.h"

class Page2 : public IPage
{
private:
  bool printed;

public:
  Page2(void)
  {
    printed = false;
  }

  void run(void)
  {
    if (!printed)
    {
      Serial.println("[page2] hellow there only once...");
      printed = true;
    }
  }
};