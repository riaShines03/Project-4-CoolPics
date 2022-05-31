/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 *  EECS 183
 * Project 4: CoolPics
 *
 * <*partner* and Adria Shines>
 * <*partner UM uniqname* and adrias>
 *
 * <Implement function necessary in creating a color for a point.>
 */

#include "Color.h"

// Initializes each color variable to 0.
Color::Color() {
	red = 0;
	green = 0;
	blue = 0;
}

// Initializes each color variable with the color input variable value
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);

}

// Sets the variable red to the redVal input that is in range
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// Returns the new value of the variable red that is in range
int Color::getRed() {
    return checkRange(red);
}

// Sets the variable green to the greenVal input that is in range
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

// Returns the new value of the variable green that is in range
int Color::getGreen() {
    return checkRange(green);
}

// Sets the variable blue to the blueVal input that is in range
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// Returns the new value of the variable blue that is in range
int Color::getBlue() {
    return checkRange(blue);
}

// Ensures a color's value is in range and reads in its value
void Color::read(istream& ins) {

    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);

    ins >> red >> green >> blue;

}

// Ensures a color's value is in range and writes it value to output
void Color::write(ostream& outs) {
    red = checkRange(red);
    green = checkRange(green);
    blue = checkRange(blue);
    char space1 = ' ';
    char space2 = ' ';

    outs << red << space1 << green << space2 <<
        blue ;
}

// Checks if a value is within range. 
// If not, it assigns the value to the nearest value that's in range
int Color::checkRange(int val) {
    const int COLOR_RANGE = 255;
    if (val >= 0 && val <= COLOR_RANGE) {
        val = val;
    }
    if (val < 0) {
        val = 0;
    }

    if (val > COLOR_RANGE) {
        val = COLOR_RANGE;
    }
    return val;
}






istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
