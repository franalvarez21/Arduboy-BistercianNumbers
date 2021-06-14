
#include "src/Bistercian.h"

Arduboy2Base arduboy;
Bistercian bistercian(&arduboy);

void setup()
{
  arduboy.begin();
}

void loop()
{
  arduboy.clear();

  // display values from 0 to 99
  uint32_t number = 0;
  for (size_t x = 0; x < 25; x++)
  {
    for (uint8_t y = 0; y < 4; y++)
    {
      bistercian.setCursor(x * 5, y * 10);
      bistercian.print(number);
      number++;
    }
  }

  // display other values
  bistercian.setCursor(5 * 5, 6 * 10);
  bistercian.print(1992);
  bistercian.setCursor(7 * 5, 6 * 10);
  bistercian.print(4723);
  bistercian.setCursor(9 * 5, 6 * 10);
  bistercian.print(6859);
  bistercian.setCursor(11 * 5, 6 * 10);
  bistercian.print(7085);
  bistercian.setCursor(13 * 5, 6 * 10);
  bistercian.print(8971);
  bistercian.setCursor(15 * 5, 6 * 10);
  bistercian.print(9938);
  bistercian.setCursor(17 * 5, 6 * 10);
  bistercian.print(91);
  bistercian.setCursor(19 * 5, 6 * 10);
  bistercian.print(1903);

  arduboy.display();
}
