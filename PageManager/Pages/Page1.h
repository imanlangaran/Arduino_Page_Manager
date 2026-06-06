#pragma once

#include <Arduino.h> // Add this line

#include "./IPage.h"

class Page1 : public IPage
{
private:
  bool printed;
  uint8_t counter;

public:
  Page1(void)
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

    addCounter();
    internalDelay();

  }

  void addCounter(){
    counter++;
    Serial.print("[page1] counter: ");
    Serial.println(counter);
  }

  // TODO: implement delay without 'delay'
  void internalDelay(){
    delay(100);
  }
};