#pragma once

#include <Arduino.h>

#include "IInputDevice.h"
#include "../helpers/IntervalTimer.h"

class PushButtonInput : public IInputDevice
{
private:
  uint8_t pin;

  bool currentState;
  bool lastState;

  bool waitingSecondClick;
  bool longPressTriggered;

  unsigned long pressStartTime;
  unsigned long firstClickTime;

  InputEvent pendingEvent;

  IntervalTimer debounceTimer;

  static const unsigned long LONG_PRESS_MS = 1000;
  static const unsigned long DOUBLE_CLICK_MS = 300;

public:
  PushButtonInput(uint8_t buttonPin)
      : pin(buttonPin),
        debounceTimer(50)
  {
    pinMode(pin, INPUT);

    currentState = digitalRead(pin);
    lastState = currentState;

    waitingSecondClick = false;
    longPressTriggered = false;

    pressStartTime = 0;
    firstClickTime = 0;

    pendingEvent = InputEvent::None;
  }

  void update() override
  {
    if (!debounceTimer.ready())
      return;

    currentState = digitalRead(pin);

    // Pressed
    if (lastState == LOW && currentState == HIGH)
    {
      pressStartTime = millis();
      longPressTriggered = false;
    }

    // Long press
    if (currentState == HIGH &&
        !longPressTriggered &&
        millis() - pressStartTime >= LONG_PRESS_MS)
    {
      pendingEvent = InputEvent::LongPress;

      longPressTriggered = true;
      waitingSecondClick = false;
    }

    // Released
    if (lastState == HIGH && currentState == LOW)
    {
      if (!longPressTriggered)
      {
        if (!waitingSecondClick)
        {
          waitingSecondClick = true;
          firstClickTime = millis();
        }
        else if (millis() - firstClickTime <= DOUBLE_CLICK_MS)
        {
          pendingEvent = InputEvent::DoubleClick;
          waitingSecondClick = false;
        }
      }
    }

    // Single click timeout
    if (waitingSecondClick &&
        millis() - firstClickTime > DOUBLE_CLICK_MS)
    {
      pendingEvent = InputEvent::Click;
      waitingSecondClick = false;
    }

    lastState = currentState;
  }

  bool hasEvent() override
  {
    return pendingEvent != InputEvent::None;
  }

  InputEvent getEvent() override
  {
    InputEvent event = pendingEvent;
    pendingEvent = InputEvent::None;
    return event;
  }
};