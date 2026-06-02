#include <Arduino.h> // Add this line

#include "Page1.h"


Page1::Page1(void){
  printed = false;
}

void Page1::run(void){
  if(!printed){
    Serial.println("hellow there only once...");
    printed = true;
  }

}
