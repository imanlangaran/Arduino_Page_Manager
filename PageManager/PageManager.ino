
#include "PageManager.h"
#include "Pages/IPage.h"

#include "Pages/Page1.h"
#include "Pages/Page2.h"

#include "./ButtonHandlers/PushButtonInput.h"

#include "display_wrapper.h"

IInputDevice *input;

PageManager pageManager;
Page1 page1;
Page2 page2;

void setup()
{
  Serial.begin(9600);
  Serial.println("Ready");

  input = new PushButtonInput(2);

  g_init_display();

  pageManager.registerPage(&page1);
  pageManager.registerPage(&page2);
}

void loop()
{
  input->update();

  if (input->hasEvent())
  {
    switch (input->getEvent())
    {
    case InputEvent::Click:
      Serial.println("Click");
      break;

    case InputEvent::DoubleClick:
      Serial.println("Double Click");
      pageManager.nextPage();
      break;

    case InputEvent::LongPress:
      Serial.println("Long Press");
      break;

    default:
      break;
    }
  }

  pageManager.run();
}