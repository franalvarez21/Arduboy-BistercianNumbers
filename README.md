# Arduboy-BistercianNumbers

Tiny 4x4 Bistercian Numerical Display for the Arduboy system.

Displays any numerical value up to 9999 in a 4x4 space, intended as proof of concept and flavour to some games (futuristic or cryptic numerals).

Bistercian numbers are cistercian numbers represented as a composition of binary numbers visualized in a 2x2 square space. Due to being cistercian numbers they allow the representation of a numeral value up to 9999 on a 4x4 space.

Cistercian single digits numbers go from 1 to 9, but to allow bigger numbers (one bistercian number after another) bistercian numbers go from 0 to 9, this also makes the information in a 2x2 square complete without leaving an empty space, meaning a zero has a specific visual representation the same way a zero is represented by the character '0' (a completely empty space in bistercian number is not possible as a 0 value, since [0000] is represented as the composition of all zeros in all the corners of a bistercian number, and a zero is represented by one pixel).

![Preview](https://github.com/franalvarez21/Arduboy-BistercianNumbers/blob/main/examples/numerical_chart.png?raw=true "Chart Example")

## Usage:

Set the pixel coordinates with setCursor() where you want to draw the 4x4 number.
Draw the number using print();

```cpp  
#include "Bistercian.h"

Bistercian bistercian;

bistercian.setCursor(5, 5);
bistercian.print(259);
```

## Dependencies:

Requires the Arduboy2 library, as it uses the drawPixel() function.
