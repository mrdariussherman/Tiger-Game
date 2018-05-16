/*
 * Author: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt,
 *         Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: creates a tiger object to use for the tiger and men game
 * Date Created: 3/27/2018
 * Date Modified:
 *    3/27/18: File created
 *    4/13/18: Added a point to the class to store location
 *    4/17/18: Added two functions to integrate with other class and deleted
 *             unnecessary information
 */

#ifndef TIGERPROJECT_TIGER_H
#define TIGERPROJECT_TIGER_H

#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

class Tiger{
private:
    Circle location;
    bool isTurn;
    bool surrounded;
public:
    Tiger ();
    void move(int, int);
    void setIsTurn(bool setting);
    bool getTurn();

    bool isSurrounded(){return surrounded;}
    void setSurrounded(bool s){surrounded = s;}

    Point getLocation();
    void drawTiger(SDL_Plotter* g, int R, int G, int B);
    bool isCircle(int x, int y);

};

/*
 * Description: construct the tiger with initial settings
 * return: none
 * precondition: none
 * postcondition: a tiger object is created
 */
Tiger::Tiger(){
    this->location.setCenter(0,0);
    this->location.setRadius(15);
    this->isTurn = false;
    this->surrounded = false;
}

/*
 * description: update the location and status of the tiger when a move
 *           occurs
 * return: void
 * precondition: a tiger object exists
 * postcondition: the location of the tiger and turn are updated
 */
void Tiger::move(int x1, int y1){
    this->location.setCenter(x1,y1);
}

/*
 * description: updates to the tiger's turn after the men move
 * return: void
 * precondition: a tiger object exists
 * postcondition: it is the tiger's turn
 */
void Tiger::setIsTurn(bool setting){
    isTurn = setting;
}

/*
 * description: returns the status of the tiger's turn
 * return: bool
 * precondition: a tiger object exists
 * postcondition: the tiger is unchanged
 */
bool Tiger::getTurn(){
    return isTurn;
}


/*
 * description: returns the location of the tiger on the plot
 * return: point
 * precondition: a tiger object exists
 * postcondition: the tiger is unchanged
 */
Point Tiger::getLocation(){
    return this->location.getCenter();
}

/*
 * description: draws a circle object on the SDL_Plotter at
 *              the tiger's location
 * return: void
 * precondition: a tiger object exists
 * postcondition: the tiger is unchanged, and a circle is drawn
 */
void Tiger::drawTiger(SDL_Plotter* g, int R, int G, int B){
    location.setColor(R,G,B);
    location.draw(g);
    drawFarmerClothing(g, location.getCenter());
}

/*
 * description: returns if the mouse click was in the token
 * return: bool
 * precondition: a tiger object exists
 * postcondition: the tiger is unchanged
 */
bool Tiger::isCircle(int x, int y){
    return location.isCircle(x,y);
}

#endif //TIGERPROJECT_TIGER_H
