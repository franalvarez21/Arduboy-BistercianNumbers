
#include "Bistercian.h"

void Bistercian::print(int32_t number)
{
  number = abs(number);
  uint32_t multiplier = 10;
  for (uint8_t i = 0; i < 4; i++)
  {
    printDigit((number % multiplier) == 0 ? 0 : (number % multiplier) / (multiplier / 10), i);
    multiplier *= 10;
  }
}

void Bistercian::setCursor(int16_t cursorX, int16_t cursorY)
{
  this->cursorX = cursorX;
  this->cursorY = cursorY;
}

int16_t Bistercian::getCursorX() const
{
  return cursorX;
}

int16_t Bistercian::getCursorY() const
{
  return cursorY;
}

void Bistercian::setColor(uint8_t color)
{
  this->color = color;
}

uint8_t Bistercian::getColor() const
{
  return color;
}

void Bistercian::printDigit(int32_t number, uint8_t sector)
{
  switch (number)
  {
  case 0:
    drawPixel(2, 1, 0, 3, sector);
    break;
  case 1:
    drawPixel(3, 0, 0, 3, sector);
    break;
  case 2:
    drawPixel(2, 1, 1, 2, sector);
    break;
  case 3:
    drawPixel(3, 0, 1, 2, sector);
    break;
  case 4:
    printDigit(0, sector);
    printDigit(3, sector);
    break;
  case 5:
    printDigit(1, sector);
    printDigit(3, sector);
    break;
  case 6:
    printDigit(2, sector);
    printDigit(3, sector);
    break;
  case 7:
    printDigit(0, sector);
    printDigit(2, sector);
    printDigit(3, sector);
    break;
  case 8:
    printDigit(1, sector);
    printDigit(2, sector);
    printDigit(3, sector);
    break;
  case 9:
    printDigit(0, sector);
    printDigit(1, sector);
    printDigit(2, sector);
    printDigit(3, sector);
    break;
  }
}

void Bistercian::drawPixel(uint8_t x, uint8_t x2, uint8_t y, uint8_t y2, uint8_t sector)
{
  switch (sector)
  {
  case 0:
    Arduboy2Base::drawPixel(cursorX + x, cursorY + y, color);
    break;
  case 1:
    Arduboy2Base::drawPixel(cursorX + x2, cursorY + y, color);
    break;
  case 2:
    Arduboy2Base::drawPixel(cursorX + x, cursorY + y2, color);
    break;
  case 3:
    Arduboy2Base::drawPixel(cursorX + x2, cursorY + y2, color);
    break;
  }
}
