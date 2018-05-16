/*
 * Authors: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt, and
 *    Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: Creates a circle object
 * Date Created: 4/6/2018
 * Dates Modified:
 *    4/06/2018: File created and functions initialized
 *    4/17/2018: isCircle() function added to aid in movements based on mouse
 */


#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <iostream>
#include "SDL_Plotter.h"
#include <cmath>
#include "Global.h"
#include "Point.h"

using namespace std;

struct Color{
    int red, green, blue;
};

class Circle{
private:
    Point     center;
    int radius = 15;
    Color     color;

public:
    Circle();
    void draw(SDL_Plotter* graphics);
    void setCenter(int x, int y);
    void setColor(int red, int green, int blue);
    bool isCircle(int x, int y);
    void setRadius(int x);
    Circle& operator=(const Circle);
    Point getCenter();
};

Circle::Circle() {
    center.x = 0;
    center.y = 0;
    color.red = 0;
    color.green = 0;
    color.blue = 0;
}

/*
 * description: constructor for the Circle class
 * return: none
 * precondition: none
 * postcondition: a Circle object exists
 */
void Circle::draw(SDL_Plotter* graphics) {
    int startX = center.x - radius;
    int startY = center.y - radius;
    double distance;

    for ( int i = startX; i < (startX + 2*radius) &&
                                        (i < graphics->getCol()); i++ ) {
        for (int j = startY; j < (startY + 2*radius) &&
                                        (j < graphics->getRow()); j++) {
            distance = sqrt(pow((i - center.x), 2) + pow((j - center.y), 2));

            if (abs(distance) <= radius) {
                graphics->plotPixel(i, j, color.red, color.green, color.blue);
            }
        }
    }
}

/*
 * description: sets the location of the center of the circle
 * return: void
 * precondition: a Circle object exists
 * postcondition: the center of the Circle is set to the parameters
 */
void Circle::setCenter(int x, int y) {
    //set x
    if(x > radius && x < SCREEN_WIDTH - radius){
        center.x = x;
    }
    else if(x < radius){
        center.x = radius;
    }
    else{
        center.x = SCREEN_HEIGHT - radius;
    }

    //set y
    if(y > radius && y < SCREEN_HEIGHT - radius){
        center.y = y;
    }
    else if(y < radius){
        center.y = radius;
    }
    else{
        center.y = SCREEN_HEIGHT - radius;
    }
}

/*
 * description: sets the color of the Circle object
 * return: void
 * precondition: a Circle object exists
 * postcondition: the color of the Circle is set
 */
void Circle::setColor(int red, int green, int blue) {
    color.red = red;
    color.green = green;
    color.blue = blue;
}

/*
 * description: checks if a location is within the Circle
 * return: bool
 * precondition: a Circle object exists
 * postcondition: the Circle is unchanged
 */
bool Circle::isCircle(int x, int y) {
    bool flag = false;
    double distance;
    distance = sqrt(pow((x-center.x), 2) + pow((y - center.y),2));
    if(radius >= distance) {
        flag = true;
    }
    return flag;

}

/*
 * description: gives the location of the Circle object
 * return: Point
 * precondition: a Circle object exists
 * postcondition: the Circle is unchanged
 */
Point Circle::getCenter() {
    return center;
}

/*
 * description: overloaded assignment operator
 * return: Circle object
 * precondition: a Circle object exists
 * postcondition: the Circle is assigned to another Circle
 */
Circle& Circle::operator=(const Circle that) {
    if (this != &that){
        this->color.red = that.color.red;
        this->color.green = that.color.green;
        this->color.blue = that.color.blue;

        this->center.x = that.center.x;
        this->center.y = that.center.y;
    }

    return *this;
}

/*
 * description: set radius
 * return: none
 * precondition: a Circle object exists
 * postcondition: radius changed to x
 */
void Circle::setRadius(int x) {
    this->radius = x;
}

#endif // CIRCLE_H_INCLUDED
