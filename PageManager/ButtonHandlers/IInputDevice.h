#pragma once

#include "InputEvent.h"

class IInputDevice
{
public:
    virtual void update() = 0;

    virtual bool hasEvent() = 0;

    virtual InputEvent getEvent() = 0;

    virtual ~IInputDevice() {}
};