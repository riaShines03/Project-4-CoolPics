/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 *  EECS 183
 * Project 4: CoolPics
 *
 * <*partner* and Adria Shines>
 * <*partner UM uniqname* and adrias>
 *
 * <Implement functions involved in making/using a valid point.>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// Initialize the variables of Point() with 0
Point::Point() {
    x = 0;
    y = 0;
}

// Initialize the variables of Point() with input x and y values
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// Set the x variable to hold the xVal input after making sure its in range
void Point::setX(int xVal) {
    x = checkRange(xVal);

    return;
}

// Return the value of x variable in range
int Point::getX() {

    return checkRange(x);
}

// Set the y variable to hold the yVal input after making sure its in range
void Point::setY(int yVal) {
    y = checkRange(yVal);

    return;
}

// Return the value of y variable in range
int Point::getY() {

    return checkRange(y);
}

// Reads in a point in form (x,y)
void Point::read(istream& ins) {
    char parenthesis1;
    char parenthesis2;
    char space;
    x = checkRange(x);
    y = checkRange(y);

    ins >> parenthesis1 >> x >> space >> y >> parenthesis2;
    return;
}

// Writes the point out in form (x,y)
void Point::write(ostream& outs) {
    x = checkRange(x);
    y = checkRange(y);
    outs << "(" << x << "," << y << ")";
    return;
}

// Checks if a value is within range. 
// If not, it assigns the value to the nearest value that's in range
int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        val = val;
    }
    if (val < 0) {
        val = 0;
    }

    if (val >= DIMENSION) {
        val = DIMENSION - 1;
    }
    return val;
}





istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
