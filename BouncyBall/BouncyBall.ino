#include "Arduboy.h"

Arduboy ab;

int dx = 1;
int dy = 1;
int xb;
int yb;
byte boardPosX;


void setup() {
  ab.beginNoLogo();
  ab.setFrameRate(60);


  xb = 10;
  yb = 20;
  boardPosX = 10;
}

void loop() {
  if(!(ab.nextFrame()))
  {
    return;
  }


  ab.clear();
  
  drawBall();
  drawBoard();
  moveBall();

  ab.display();
}

void drawBall(){
  ab.drawPixel(xb,   yb,   1);
  ab.drawPixel(xb+1, yb,   1);
  ab.drawPixel(xb,   yb+1, 1);
  ab.drawPixel(xb+1, yb+1, 1);
}

void drawBoard(){
  ab.drawRect(boardPosX, 63, 11, 1, 1);
}

void moveBall(){

  if(abs(dx) == 2){
    xb += dx/2;
  }else{
    xb += dx;
  }
  yb = yb + dy;

  
  if(yb <= 0){
    yb = 2;
    dy = -dy;
  }

  if(yb >= HEIGHT){
    yb = HEIGHT - 2;
    dy = -dy;
  }

  if(xb <= 0){
    xb = 2;
    dx = -dx;
  }

  if(xb >= WIDTH - 2){
    xb = WIDTH - 2;
    dx = -dx;
  }


  if(ab.pressed(RIGHT_BUTTON)){
    boardPosX++;
  }

  if(ab.pressed(LEFT_BUTTON)){
    boardPosX--;
  }
  
}

