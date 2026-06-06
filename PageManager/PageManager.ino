
#include "PageManager.h"
#include "Pages/IPage.h"

#include "Pages/Page1.h"
#include "Pages/Page2.h"

PageManager pageManager;

Page1 page1;
Page2 page2;

void setup()
{
  Serial.begin(9600);
  Serial.println("Ready");
  pageManager.registerPage(&page1);
  pageManager.registerPage(&page2);
}

void loop()
{
  if (Serial.available())
  {
    char input = Serial.read();

    if (input == 'n')
    {
      pageManager.nextPage();
    }
  }
  pageManager.run();
}