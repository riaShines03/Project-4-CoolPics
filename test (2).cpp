/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <*partner* and Adria Shines>
 * <*partner UM uniqname* and adrias>
 *
 * <Contains functions for testing classes in the project.>
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;

void test_Point();
void test_Circle();
void test_Color();
void test_Line();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Circle();
    test_Triangle();
    test_Rectangle();
 
    return;
}

void test_Point() {
    cout << "TESTING: Point" << endl;
    // test of default constructor- Point()
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor- Point(int x, int y)
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
        << "," << p1.getY()
        << ")" << endl << endl;
    
    // Test member function read()
     Point testRead;
    ifstream testRead1;
    testRead1.open("readTest.txt");
    testRead.read(testRead1);
    cout << "Expecting: (43,12). Actual: " << testRead << endl;

    // Test member function write()
    Point testWrite(20, 21);
    ofstream testWrite1;
    testWrite1.open("writeTest.txt");
    testWrite.write(testWrite1);
    cout << "Expecting: (20,21). Actual:" << testWrite << endl << endl;

    return;
}

void test_Color() {
    cout << "TESTING: Color" << endl;
    // Test default constructor - Color() 
    Color Color1; 
    cout << "Expecting: 0 0 0. Actual: " << Color1 << endl;

    // Testing non-default constructor- Color(int redVal, int greenVal,
    // int blueVal) AND checkRange()
    Color Color2(3, 300, 200);
    cout << "Expecting: 3 255 200. Actual: " << Color2 << endl;

    // Testing setRed() and getRed()
    Color Color3;
    Color3.setRed(30);
    cout << "Expecting: 30. Actual: " << Color3.getRed() << endl;

    //Testing setGreen() and getGreen() and checkRange()
    Color Color4; 
    Color4.setGreen(300);
    cout << "Expecting: 255. Actual: " <<
        Color4.getGreen() << endl;

    // Testing setBlue() and getBlue() 
    Color Color5;
    Color5.setBlue(18);
    cout << "Expecting: 18. Actual: " <<
        Color5.getBlue() << endl;

    // Testing read()
    Color Read;

    ifstream testRead1;
    testRead1.open("ColorReadText.txt");
    Read.read(testRead1);
    cout << "Expecting: 100 150 200. Actual: " << Read << endl;

    // Testing write()
    Color testWrite(200, 200, 200);
    ofstream testWrite1;
    testWrite1.open("writeTest.txt");
    testWrite.write(testWrite1);
    cout << "Expecting: 200 200 200. Actual: " << testWrite << endl << endl;
}

void test_Line() {
    cout << "TESTING: Line()" << endl;

    // Testing Line() default constructor
    Line Line1;
    cout << "Expecting: (0,0) (0,0) 0 0 0  Actual: " << Line1 << endl;

    // Testing Line(pt1, pt2, color)
    Point pt1 = Point(4,6);
    Point pt2 = Point(2, 4);
    Color color = Color(0, 0, 0);

    Line Line2(pt1, pt2, color);
    cout << "Expected (4,6) (2,4) 0 0 0  Actual: " << Line2 << endl;

    // Testing setStart and getStart
    Line Line3;
    Line3.setStart(pt1);
    cout << "Expecting: (4,6)  Actual: " <<
        Line3.getStart() << endl;

    // Testing setEnd() and getEnd()
    Line Line4; 
    Line4.setEnd(pt2);
    cout << "Expecting: (2,4) Actual: " <<
        Line4.getEnd() << endl;

    // Testing setColor() and getColor() and checkRange()
    Line Line5;
    Color color2 = Color(100, 300, 14);
    Line5.setColor(color2);
    cout << "Expecting: 100 255 14. Actual: " << Line5.getColor() << endl;

    // Testing read
    Line Line6; 
    ifstream testLineRead;
    testLineRead.open("readTest.txt");
    Line6.read(testLineRead);
    cout << "Expecting: (43,12) (6,7) 8 0 0  Actual: " <<
        Line6 << endl;
    
    // Testing write()
    Line Line7(pt1, pt2, color); 
    ofstream testLineWrite;
    testLineWrite.open("writeTest.txt");
    Line7.write(testLineWrite);
    cout << "Expecting: (4,6) (2,4) 0 0 0 Actual: " << Line7 << endl;

}

void test_Circle() {
    cout << "TESTING: Circle()" << endl;

    //Testing default constructor- Circle()
    Circle circle1;
    cout << "Expecting: (0,0) 0  0 0 0 Actual: " << circle1 << endl;

    // Test constructor - circle(pt, r, c)
    Point pt1 = Point(21, 200);
    int r = -10;
    Color c = Color(300, 255, 255);
    Circle circle2(pt1, r, c);
    cout << "Expecting: (21, 99) 10 255 255 255. Actual: " << circle2 << endl;

    // Test setCenter() and getCenter()
    Circle circle3;
    circle3.setCenter(pt1);
    cout << "expecting: (21,99)  Actual: " << circle3.getCenter() << endl;

    //Test setRadius() and getRadius()
    Circle circle4;
    circle4.setRadius(r);
    cout << "expecting: 10. Actual: " << circle4.getRadius() << endl;

    // Test setColor() and getColor()
    Circle circle5;
    circle5.setColor(c);
    cout << "Expecting: 255 255 255. Actual: " << circle5.getColor() << endl;

    // Testing read()
    Circle readCircle;
    ifstream readTest;
    readTest.open("readTest.txt");
    readCircle.read(readTest);
    cout << "expecting: (43,12) 0 0 0 0. Actual: " << readCircle << endl;

    // Testing write()
    Circle writeCircle(pt1, r, c);
    ofstream writeTest;
    writeTest.open("writeTest.txt");
    writeCircle.write(writeTest);
    cout << "expecting: (21,99) 10 255 255 255. Actual: "
        << writeCircle << endl << endl;
}


void test_Triangle() {
    cout << "TESTING: Triangle(). Actual: " << endl;

    // Testing constructor Triangle(pt1, pt2, pt3, color)
    Point pt1 = Point(0, 0);
    Point pt2 = Point(24, 25);
    Point pt3 = Point(15, 30);
    Color color = Color(300, 155, 55);
    Triangle triangle2(pt1, pt2, pt3, color);
    cout << "Expecting (0,0) (24,25) (15,30) 255 155 55  Actual: "
        << triangle2 << endl;

    // Testing 3rd constructor Triangle(pt1, color1, pt2, color2, pt3, color3)
    Color color1 = Color(300, 155, 55);
    Color color2 = Color(10, 20, 30);
    Color color3 = Color(50, 50, 50);
    Triangle triangle3(pt1, color1, pt2, color2, pt3, color3);

    cout << "Expecting (0,0) 255 155 55 (24,25) 10 20 30" <<
        "(15,30) 50 50 50   Actual: " << triangle3 << endl << endl;

    // Testing setColor()
    Triangle triangle4; 
    triangle4.setColor(color);
    cout << "expecting:  (0,0) 255 155 55 (0,0) 255 155 55 (0,0) 255 155 55" <<
        "Actual: " << triangle4 << endl;

    // Testing setVertexOne, getVertexOne, setVertexTwo,
    // getVertexTwo, setVertexThree, getVertexThree
    Triangle triangle5;
    triangle5.setVertexOne(pt1);
    triangle5.setVertexTwo(pt2);
    triangle5.setVertexThree(pt3);
    cout << "expecting: (0,0) (24,25) (15,30) Actual: "
        << triangle5.getVertexOne() << triangle5.getVertexTwo()
        << triangle5.getVertexThree() << endl;

    // Testing setVertex__Color, getVertex__Color for three vertices
    Triangle triangle6;
    triangle6.setVertexOneColor(color1);
    triangle6.setVertexTwoColor(color2);
    triangle6.setVertexThreeColor(color3);
    cout << "expecting: 255 155 55 10 20 30 50 50 50 " <<
        " Actual: " << triangle6.getVertexOneColor()
        << triangle6.getVertexTwoColor() << triangle6.getVertexThreeColor()
        << endl;

    // Testing read
    Triangle readTriangle;
    ifstream readTest;
    readTest.open("readTriangleText.txt");
    readTriangle.read(readTest);
    cout << "expecting: (30,45) 1 2 3 (45,60) 4 5 6 (60,75) 7 8 9"
        << "Actual: " << readTriangle << endl;

    // Testing write()
    Triangle writeTriangle(pt1, color1, pt2, color2, pt3, color3);
    ofstream writeTest;
    writeTest.open("writeTest.txt");
    writeTriangle.write(writeTest);
    cout << "expecting: (0,0) 255 155 55 (24,25) 10 20 30 (15,30) 50 50 50 "
        << "Actual: "
        << writeTriangle << endl << endl;


}

void test_Rectangle() {
    cout << "TESTING: Rectangle()" << endl;

    // Testing 2nd constructor
    Point pt1 = Point(0, 0);
    Point pt2 = Point(24, 25);
    Color color = Color(300, 155, 55);
    Rectangle rectangle2(pt1, pt2, color);
    cout << "Expecting (0,0) (24,25) 255 155 55  Actual: "
        << rectangle2 << endl;

    // Testing third constructor 
    Color color1 = Color(300, 155, 55);
    Color color2 = Color(10, 20, 30);
    Color color3 = Color(50, 50, 50);
    Color color4 = Color(100, 100, 100);

    Rectangle rectangle3(pt1, pt2, color1, color2, color3, color4);
    cout << "Expecting: (0,0) (24,25) 255 155 55 10 20 30 50 50 50"
        << "100 100 100  Actual: " << rectangle3 << endl;


    // Test setStart() and getStart()
    Rectangle rectangle4;
    rectangle4.setStart(pt1);
    cout << "expecting: (0,0) Actual: " << rectangle4.getStart() << endl;

    // Test setEnd() and getEnd()
    Rectangle rectangle5;
    rectangle5.setEnd(pt2);
    cout << "expecting: (24,25) Actual: " << rectangle5.getEnd() << endl;

    // Testing setColor()
    Rectangle rectangle6; 
    rectangle6.setColor(color);
    cout << "expecting: 255 155 55 Actual: " << rectangle6 << endl;

    // Testing setColor(Location) and getColor(Location)
    Rectangle rectangle7;
    rectangle7.setColorTopLeft(color1);
    rectangle7.setColorTopRight(color2);
    rectangle7.setColorBottomRight(color3);
    rectangle7.setColorBottomLeft(color4);

    cout << "expecting: 255 155 55 10 20 30 50 50 50 100 100 100"
        << " Actual: " << rectangle7.getColorTopLeft() <<
        rectangle7.getColorTopRight() << rectangle7.getColorBottomRight()
        << rectangle7.getColorBottomLeft() << endl;

    // Testing read
    
    Rectangle readRectangle;
    ifstream readTest;
    readTest.open("readRectangleText.txt");
    readRectangle.read(readTest);
    cout << "expecting: (200, 200) (300, 300)" <<
        "255 155 55 10 20 30 50 50 50 100 100 100"
        << "Actual: " << readRectangle << endl;

    // Testing write()
    Rectangle writeRectangle(pt1, pt2, color1, color2, color3, color4);
    ofstream writeTest;
    writeTest.open("writeTest.txt");
    writeRectangle.write(writeTest);
    cout << "expecting: (0,0) (24,25) 255 155 55 10 20 30 50 50 50 100 100 100"
        << "Actual: "
        << writeRectangle << endl << endl;



}












