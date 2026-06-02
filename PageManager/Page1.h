#pragma once

#include "IPage.h"

class Page1 : public IPage {
  private:
    bool printed;

  public:
    Page1();
    void run(void) override;
};