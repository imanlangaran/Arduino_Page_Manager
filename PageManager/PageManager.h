#pragma once

#include <Arduino.h>

#include "Pages/IPage.h"

class PageManager
{
private:
  static const uint8_t MAX_PAGES = 10;

  IPage *pages[MAX_PAGES];
  uint8_t pageCount;
  uint8_t currentPage;

public:
  PageManager()
  {
    pageCount = 0;
    currentPage = 0;
  }

  bool registerPage(IPage *page)
  {
    if (pageCount >= MAX_PAGES)
    {
      return false;
    }

    pages[pageCount] = page;
    pageCount++;

    return true;
  }

  void nextPage()
  {
    if (pageCount == 0)
    {
      return;
    }

    currentPage++;

    if (currentPage >= pageCount)
    {
      currentPage = 0;
    }
  }

  void run()
  {
    if (pageCount == 0)
    {
      return;
    }

    pages[currentPage]->run();
  }

  uint8_t getCurrentPage()
  {
    return currentPage;
  }

  uint8_t getPageCount()
  {
    return pageCount;
  }

  void setPage(uint8_t index)
  {
    if (index < pageCount)
    {
      currentPage = index;
    }
  }
};