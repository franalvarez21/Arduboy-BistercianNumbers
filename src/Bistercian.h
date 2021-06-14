#ifndef BISTERCIAN_H
#define BISTERCIAN_H

#include <Arduboy2.h>

/**
 * Bistercian uses a 4x4 space to draw a number.
 * If the number is bigger than the maximum representable value of 9999, a new bistercian
 * number will appear on the left side. This will go on until the expected number is fully
 * draw. There are no spaces between bistercians representing the same number.
 *
 * Usage:
 * Call setCursor() to set the coordinates X and Y.
 * Call the print() method to draw the bistercian.
 * The coordinates X and Y can be inform using the
 * print() method itself.
 */
class Bistercian
{
public:
  Bistercian(Arduboy2Base *arduboy) : cursorX(0), cursorY(0), color(1) { this->arduboy = arduboy; };

  /** \brief
     * Draws a number in bistercian.
     *
     * \param number The number to draw.
     * 
     * \details
     * draws a bistercian number in the location set by the cursor X and cursor Y values.
     */
  void print(int32_t number);

  /** \brief
     * Set the location to draw the bistercian number on.
     *
     * \param x The X coordinate, in pixels.
     * \param y The Y coordinate, in pixels.
     *
     * \details
     * The location of the draw cursor is set the the specified coordinates.
     * The coordinates are in pixels. As with all drawing functions, location 0, 0
     * is the top left corner of the display.
     */
  void setCursor(int16_t x, int16_t y);

  /** \brief
     * Get the X coordinate of the current cursor position.
     *
     * \return The X coordinate of the current cursor position.
     *
     * \details
     * The X coordinate returned is a pixel location with 0 indicating the
     * leftmost column.
     */
  int16_t getCursorX() const;

  /** \brief
     * Get the Y coordinate of the current cursor position.
     *
     * \return The Y coordinate of the current cursor position.
     *
     * \details
     * The Y coordinate returned is a pixel location with 0 indicating the
     * topmost row.
     */
  int16_t getCursorY() const;

  /** \brief
     * Set the text foreground color.
     *
     * \param color The color to be used for the numbers draw.
     */
  void setTextColor(uint8_t color);

  /** \brief
     * Get the text foreground color.
     *
     * \return The color used for the number draw.
     */
  uint8_t getTextColor() const;

private:
  /** \brief
     * Draws a single digit in bistercian.
     *
     * \param number The digit to draw.
     * \param division The sector to draw on.
     * 
     * \details
     * draws a bistercian number in the location set by the cursor X and cursor Y values.
     */
  void printDigit(int32_t number, uint8_t division);

  /** \brief
     * Private function. Print each pixel.
     */
  void drawPixel(uint8_t x, uint8_t x2, uint8_t y, uint8_t y2, uint8_t division);

  Arduboy2Base *arduboy;
  int16_t cursorX; //!< Default is 0.
  int16_t cursorY; //!< Default is 0.
  uint8_t color;   //!< BLACK == 0, everything else is WHITE. Default is WHITE.
  uint8_t location;
};

#endif
