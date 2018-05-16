/*
 * Authors: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt, and
 *    Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: Contains functions to draw confetti on the game
 * Due Date: 4/26/2018
 * Date Created: 4/13/2018
 * Date Modified:
 *       4/13/2018: file created
 *       4/21/2018: file modified and added to game
 */

#ifndef CONFETTI_H_INCLUDED
#define CONFETTI_H_INCLUDED

#include <iostream>
#include "SDL_Plotter.h"
#include "Circle.h"
#include <ctime>
#include <string>

using namespace std;

/*
 * description: sets the color of the confetti circles
 * return: void
 * precondition: none
 * postcondition: the color of the confetti is set
 */
void setColorBasedOnTime(int& r, int& g, int& b){
    time_t currentTime;
    struct tm *localTime;
    long int start, stop;

    start = clock();

    time( &currentTime );
    localTime = localtime( &currentTime );

    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;

    stop = clock();

    r = 20;
    b = ((stop - start)*1250) % Sec * 10;
    g = ((stop - start)*1250) % Hour * 17;
}

/*
 * description: creates a random rgb value for the confetti
 * return: void
 * precondition: none
 * postcondition: the color of the confetti is set
 */
void setColorRandomly(int&r, int& g, int& b){
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}

/*
 * description: initiates a circle object
 * return: void
 * precondition: none
 * postcondition: circle is drawn in the Plotter
 */
void confetti( SDL_Plotter* graphics, int radius){
    int x, y, R, G, B;
    Circle theCircle;

    theCircle.setRadius(radius);

    x = rand() % graphics->getCol() + 1;
    y = rand() % graphics->getRow() + 1;

    //setColorBasedOnTime(R, G, B);
    setColorRandomly(R, G, B);

    theCircle.setCenter(x, y);
    theCircle.setColor(R, G, B);
    theCircle.draw(graphics);
}

/*
 * description: an array of confetti circles is created and drawn
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: confetti circles are drawn to the Plotter
 */
void drawConfetti( SDL_Plotter* graphics, int count, int radius){
    for ( int i = 0; i < count; i++ ){
        confetti(graphics, radius);
        graphics->update();
    }
}

#endif // CONFETTI_H_INCLUDED
