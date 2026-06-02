#include "IPage.h"
#include "Page1.h"

IPage* page;

Page1 page1;

void setup(){
  Serial.begin(9600);
  Serial.println("Ready");
  page = &page1;
}

void loop(){
  page->run();
}