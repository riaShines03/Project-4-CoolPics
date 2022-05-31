/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <*partner* and Adria Shines>
 * <*partner UM uniqname* and adrias>
 *
 * <Assign the start, end, color for each corner (if needed), 
    for rectangle with corresponding info from file and returns it>
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;





Rectangle::Rectangle() {

}

//Initialize the start and end point of rectangle with Points pt1 and pt2
// Initialize the color of each corner with Color color
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// Initializes the start and end point of rectangle with Points pt1 and pt2
// Initializes the color of each corner with the corresponding Color variable
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
    Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;

}

// Sets the start variable with the input Point pt value
void Rectangle::setStart(Point pt) {
    start = pt;
}

// Returns the value of start variable
Point Rectangle::getStart() {
    return start;
}

// Sets the end variable with the input Point pt value
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// Returns the value of end variable
Point Rectangle::getEnd() {
    return end;
}

// Sets the color of each corner with input Color color value
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomLeft = color;
    colorBottomRight = color;
}

// Sets colorTopLeft to the input Color color value
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

// Return value of colorTopLeft
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// Sets colorTopRight to the input Color color value
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

// Returns value of colorTopRight
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// Sets colorBottomRight to the input Color color value
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// Returns value of colorBottomRight
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Sets colorBottomLeft to the input Color color value
void Rectangle::setColorBottomLeft(Color c) {
    colorBottomLeft = c;
}

// Returns value of colorBottomLeft
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

// Reads in value for variables start end and color
// For form 2, it reads in value for variables start, end,
// and each color variable
void Rectangle::read(istream& ins) {
    Color color;
    ins >> start >> end >> color;
    ins >> start >> end >> colorTopLeft >> colorTopRight 
        >> colorBottomRight >> colorBottomLeft;
}

// Writes the value of start end and each color variable
void Rectangle::write(ostream& outs) {
    outs << start << end << colorTopLeft << colorTopRight 
        << colorBottomRight << colorBottomLeft;
}





istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
