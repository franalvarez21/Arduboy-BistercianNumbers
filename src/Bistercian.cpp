
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

void Bistercian::setCursor(int16_t x, int16_t y)
{
  cursorX = x;
  cursorY = y;
}

int16_t Bistercian::getCursorX() const
{
  return cursorX;
}

int16_t Bistercian::getCursorY() const
{
  return cursorY;
}

void Bistercian::setTextColor(uint8_t color)
{
  this->color = color;
}

uint8_t Bistercian::getTextColor() const
{
  return color;
}

void Bistercian::printDigit(int32_t number, uint8_t division)
{
  switch (number)
  {
  case 0:
    drawPixel(2, 1, 0, 3, division);
    break;
  case 1:
    drawPixel(3, 0, 0, 3, division);
    break;
  case 2:
    drawPixel(2, 1, 1, 2, division);
    break;
  case 3:
    drawPixel(3, 0, 1, 2, division);
    break;
  case 4:
    printDigit(0, division);
    printDigit(3, division);
    break;
  case 5:
    printDigit(1, division);
    printDigit(3, division);
    break;
  case 6:
    printDigit(2, division);
    printDigit(3, division);
    break;
  case 7:
    printDigit(0, division);
    printDigit(2, division);
    printDigit(3, division);
    break;
  case 8:
    printDigit(1, division);
    printDigit(2, division);
    printDigit(3, division);
    break;
  case 9:
    printDigit(0, division);
    printDigit(1, division);
    printDigit(2, division);
    printDigit(3, division);
    break;
  }
}

void Bistercian::drawPixel(uint8_t x, uint8_t x2, uint8_t y, uint8_t y2, uint8_t division)
{
  if (division == 0)
  {
    arduboy->drawPixel(cursorX + x, cursorY + y, color);
  }
  else if (division == 1)
  {
    arduboy->drawPixel(cursorX + x2, cursorY + y, color);
  }
  else if (division == 2)
  {
    arduboy->drawPixel(cursorX + x, cursorY + y2, color);
  }
  else if (division == 3)
  {
    arduboy->drawPixel(cursorX + x2, cursorY + y2, color);
  }
}
