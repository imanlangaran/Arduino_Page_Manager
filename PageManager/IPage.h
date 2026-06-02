#pragma once

class IPage
{
  public:
    virtual void run(void) = 0;
    virtual ~IPage() {};
};

