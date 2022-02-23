
#include <Arduboy2.h>
#include <ArduboyFX.h>
#include "fxdata/fxdata.h"

Arduboy2 arduboy;

uint32_t x    = 0;
uint32_t y    = 0;

uint32_t xSize = 1191;
uint32_t ySize = 848 / 8;


void setup() {

  arduboy.boot();
  arduboy.flashlight();
  arduboy.systemButtons();
  arduboy.setFrameRate(30);

  FX::disableOLED();
  FX::begin(FX_DATA_PAGE);

}

void loop() {

  if (!arduboy.nextFrame()) return; 

  if (arduboy.pressed(LEFT_BUTTON) && x >= 8)                     x = x - 8;
  if (arduboy.pressed(RIGHT_BUTTON) && x < xSize - WIDTH)         x = x + 8;
  if (arduboy.pressed(UP_BUTTON) && y >= 1)                       y = y - 1;
  if (arduboy.pressed(DOWN_BUTTON) && y < ySize - (HEIGHT / 8))   y = y + 1;

  // FX::seekData(World);

  // FX::readDataBytes(World + (xSize * y) + x, arduboy.sBuffer, 128);
  FX::readDataBytes(World + (xSize * y) + x, arduboy.sBuffer, 128);
  FX::readDataBytes(World + (xSize * (y + 1)) + x, arduboy.sBuffer + (1 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 2)) + x, arduboy.sBuffer + (2 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 3)) + x, arduboy.sBuffer + (3 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 4)) + x, arduboy.sBuffer + (4 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 5)) + x, arduboy.sBuffer + (5 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 6)) + x, arduboy.sBuffer + (6 * 128), 128);
  FX::readDataBytes(World + (xSize * (y + 7)) + x, arduboy.sBuffer + (7 * 128), 128);

  FX::readEnd();
  
  FX::enableOLED();
  arduboy.display(CLEAR_BUFFER);
  FX::disableOLED();

}
