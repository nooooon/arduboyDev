#include "Arduboy.h"

Arduboy ab;

#define CHR_CY 8
#define TEXT_CY (CHR_CY)
#define TEXT_MAX_Y (HEIGHT - TEXT_CY)

char* t = "Press Buttons!";

void setup() {
  ab.beginNoLogo();
  ab.setFrameRate(60);
}

void loop() {
  if(!(ab.nextFrame()))
  {
    return;
  }

  if(ab.pressed(RIGHT_BUTTON)){
    t = "Press Right";
  }
  
  if(ab.pressed(LEFT_BUTTON)){
    t = "Press Left";
  }
  
  if(ab.pressed(UP_BUTTON)){
    t = "Press Up";
  }
  
  if(ab.pressed(DOWN_BUTTON)){
    t = "Press Down";
  }
  
  if(ab.pressed(A_BUTTON)){
    t = "Press A";
  }
  
  if(ab.pressed(B_BUTTON)){
    t = "Press B";
  }
  
  ab.clear();
  ab.setCursor(10, (HEIGHT / 2) - (TEXT_CY / 2));
  ab.print(t);
  ab.display();
}
