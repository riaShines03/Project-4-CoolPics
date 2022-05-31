/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 *  EECS 183
 * Project 4: CoolPics
 *
 * <*partner* and Adria Shines>
 * <*partner UM uniqname* and adrias>
 *
 * <Assign center, radius, color of circle with corresponding info from file 
    and returns this info>
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;


// Initializes the center to (0,0)
// Initializes the radius to 0
// Initializes the color to black
Circle::Circle() {
    center = Point(0, 0);
    radius = 0;
    color = Color(0, 0, 0);
}

// Initializes the center to input Point pt value
// Initializes the radius to input int r value
// Initializes the color to input Color c value
Circle::Circle(Point pt, int r, Color c) {
    center = pt;
    radius = checkRadius(r);
    color = c;
}

// Sets center to the value of input Point pt
void Circle::setCenter(Point pt) {
    center = pt;
}

// Returns the value of center
Point Circle::getCenter() {
    return center;
}

// Sets radius to the value of input int r
void Circle::setRadius(int r) {
    radius = checkRadius(r);
}

// Returns the value of radius
int Circle::getRadius() {
    return radius;
}

// Sets color to the value of input Color c
void Circle::setColor(Color c) {
    color = c;
}

// Returns the value of color
Color Circle::getColor() {
    return color;
}

// Reads in values into center, radius, and color in format center radius color
void Circle::read(istream& ins) {
    radius = checkRadius(radius);
    ins >> center >>  radius >>  color;
}

// Writes the center, radius, and color of the circle 
//in format center radius circle
void Circle::write(ostream& outs) {
    char space1 = ' ';
    char space2 = ' ';
    radius = checkRadius(radius);

    outs << center << space1 << radius << space2 << color;
}




istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
