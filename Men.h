/*
 * Author: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt,
 *         Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: creates a man object to use for the tiger and men game
 * Date Created: 3/27/2018
 * Date Modified:
 *    3/27/18: File created
 *    4/13/18: Added a point to the class to store location
 *    4/17/18: Added two functions to integrate with other class and deleted
 *             unnecessary information
 */

#ifndef TIGERPROJECT_MEN_H
#define TIGERPROJECT_MEN_H

#include <iostream>
#include "SDL_Plotter.h"
#include "Circle.h"
#include "Point.h"
#include "Draw.h"

using namespace std;

class Man{
private:
    Circle location;
    bool alive;
public:
    Man();
    void gotJumped();
    void move(int, int);
    bool getAlive();
    void setAlive(bool setting){alive = setting;}
    void drawMan(SDL_Plotter* g, int R, int G, int B);
    Point getLocation();
    bool isCircle(int x, int y);

};

/*
 * description: constructor for the Man class
 * return: none
 * precondition: none
 * postcondition: a Man object exists
 */
Man::Man(){
    this->location.setCenter(0,0);
    this->location.setRadius(15);
    this->alive = true;
}

/*
 * description: updates the location of the Man after a move
 * return: void
 * precondition: a Man object exists
 * postcondition: the Man's location is updated
 */
void Man::move(int x1, int y1){
    this->location.setCenter(x1,y1);
}

/*
 * description: updates the status of the Man's life
 * return: void
 * precondition: a Man object exists
 * postcondition: the Man is not alive
 */
void Man::gotJumped(){
    this->alive = false;
}

/*
 * description: returns the status of a Man's life
 * return: bool
 * precondition: a Man object exists
 * postcondition: the object is unchanged
 */
bool Man::getAlive(){
    return this->alive;
}

/*
 * description: returns the location of the Man
 * return: point
 * precondition: a Man object exists
 * postcondition: the object is unchanged
 */
Point Man::getLocation(){
    return this->location.getCenter();
}

/*
 * description: draws a circle object on the SDL_Plotter at
 *              the man's location
 * return: void
 * precondition: a man object exists
 * postcondition: the man is unchanged, and a circle is drawn
 */
void Man::drawMan(SDL_Plotter* g, int R, int G, int B){
    location.setColor(R,G,B);
    location.draw(g);
    drawTomatoLeaves(g,location.getCenter());
}

/*
 * description: returns if the mouse click was in the token
 * return: bool
 * precondition: a man object exists
 * postcondition: the man is unchanged
 */
bool Man::isCircle(int x, int y){
    return location.isCircle(x,y);
}

#endif //TIGERPROJECT_MEN_H

