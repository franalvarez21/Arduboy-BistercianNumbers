
#ifndef BISTERCIAN_H
#define BISTERCIAN_H

#include <Arduboy2.h>

/**
 * Bistercian uses a 4x4 space to draw a number.
 * They can represent a number up to 9999, including the 0. Negative numbers have the same
 * representation as positive ones.
 * 
 * The print() method will only print the first four digits of any giving number, ignoring
 * any value above 9999. No leading zeros are needed, expecting an integer number by default.
 *
 * Usage:
 * Call setCursor() to set the coordinates X and Y.
 * Call the print() method to draw the bistercian number.
 */
class Bistercian
{
private:
  int16_t cursorX;
  int16_t cursorY;
  uint8_t color;

  /** \brief
     * Draws a single digit in bistercian.
     *
     * \param number The digit to draw.
     * \param sector The sector to draw on.
     */
  void printDigit(int32_t number, uint8_t sector);

  /** \brief
     * Private function. Print each pixel by sector.
     */
  void drawPixel(uint8_t x, uint8_t x2, uint8_t y, uint8_t y2, uint8_t sector);

  /** \brief
     * Private function. Print each pixel by sector by size.
     */
  void drawPixelBySize(uint8_t x, uint8_t y, uint8_t sector);

public:
  /** \brief
     * Constructor for th Bistercian class.
     * cursorX and cursorY are set to 0 by default.
     * the color used is WHITE by default (1).
     */
  Bistercian() : cursorX(0), cursorY(0), color(1){};

  /** \brief
     * Draws a number in bistercian.
     *
     * \param number The number to draw.
     */
  void print(int32_t number);

  /** \brief
     * Set the coordinates to draw the bistercian number on.
     *
     * \param cursorX The X coordinate, in pixels.
     * \param cursorY The Y coordinate, in pixels.
     *
     * \details
     * Coordinates in which to draw the number. The most top-left corner is 0,0 and the
     * most right-bottom corner is 128,64. Since each number uses a 4x4 space, the
     * theoretically highest value for cursorX is 124 and for cursorY is 60, but this
     * values are not enforced.
     */
  void setCursor(int16_t cursorX, int16_t cursorY);

  /** \brief
     * Get the X coordinate of the current cursor position.
     *
     * \return The cursorX coordinate.
     */
  int16_t getCursorX() const;

  /** \brief
     * Get the Y coordinate of the current cursor position.
     *
     * \return The cursorY coordinate.
     */
  int16_t getCursorY() const;

  /** \brief
     * Set the color.
     *
     * \param color The color for the pixels draw by the drawPixel function.
     */
  void setColor(uint8_t color);

  /** \brief
     * Get the color.
     *
     * \return The color used by the drawPixel function.
     */
  uint8_t getColor() const;
};

#endif
