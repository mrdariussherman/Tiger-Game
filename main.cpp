/*
 * Authors: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt, and
 *     Darius Sherman
 * Date Created: 4/6/2018
 * Dates Modified:
 *    4/10/2018
 *    4/13/2017: grid and circles
 *    4/17/2018: mouse movements
 *    4/19/2018: tiger jumping functionality
 *    4/20/2018: winning functionality
 *    4/25/2018: final testing and debugging
*/

/*
 * Data Abstraction:
 *            An SDL Plotter is initialized to display and play the game
 *            2 integers, x and y, are initialized to store the active token's
 *                 location
 *            An integer, p, is initialized to save previous indices
 *            An integer, i, is initialized to control confetti speed
 *            4 integers, curX, curY, dropX and dropY are initialized for
 *                 locations
 *            5 bools are initialized for movement status
 *            3 bools are initialized for game ending
 *            A vector of Men and a Tiger are initialized for gameplay
 *            A Plot and a Point are initialized for the gameboard
 *  Input:
 *            The user moves pieces on the board with the mouse
 *  Process:
 *            The game updates based on the pieces movement
 *            The game analyzes the players' positions and determines when
 *                the game ends
 *  Output:
 *            The game is displayed and updated in the SDL Plotter
 *  Assumptions:
 *            The user has read the user's manual
 *            The SDL Plotter is fully functioning
 *            The user has a mouse
*/

#include <iostream>

#include "Alphabet.h"
#include "Circle.h"
#include "Confetti.h"
#include "Draw.h"
#include "Global.h"
#include "Men.h"
#include "Plot.h"
#include "Point.h"
#include "SDL_Plotter.h"
#include "Tiger.h"

using namespace std;

int main( int argc, char** args )
{
    //Main program
    SDL_Plotter *g;
    g = new SDL_Plotter(SCREEN_WIDTH, SCREEN_HEIGHT);

    int x = xNOT;
    int y = yNOT;
    int p;          //used to save index of man currently being moved by mouse
    int i = 100;    //used to slowly speed up confetti
    int curX, curY, dropX, dropY;
    bool isValidMove;   //check if a move is valid
    bool foundPos;      //check if a physical location is valid to move to
    bool mouseDown = false;

    bool won = false;       //has anyone one
    bool tigerWins = false; //tiger has won, men loose
    bool justWon = false;   //true if someone has just won

    Plot virtualGraph;
    Point temp;

    //initialize the men and tiger and their locations
    int s = 18;
    vector<Man> men(s);
    Tiger tiger;

    tiger.move(x+(m*4), y+(m*2));

    //First row of men
    for (int i = 0; i < s/2; i++) {
        men[i].move(x+(i*m), y+(m*11));
    }

    //Second row of men
    for (int i = 9; i < s; i++) {
        men[i].move(x + ((i%9)*m), y+(m*12));
    }


    while(!g->getQuit()) {


        // while someone has not won
        if(!won){

            //clear screen
            g->clear();

            //draw visual board
            drawGrid(g);


            if (g->getMouseDown(x, y)) {

                //Save the vertex closes to x,y
                temp = virtualGraph.validPoints(x,y);
                curX = temp.x;
                curY = temp.y;
                if(tiger.getTurn()){

                    if(tiger.isCircle(curX,curY)){
                        mouseDown = true;
                    }

                }
                else{
                    for(int i= 0; i < s; i++){
                        if(men[i].isCircle(curX, curY)){
                            p = i;
                            mouseDown = true;
                        }
                    }
                }

            }

            if (g->getMouseMotion(x,y) && mouseDown) {
                if(tiger.getTurn())
                    tiger.move(x,y);
                else
                    men[p].move(x,y);
            }

            if (g->getMouseUp(x,y) && mouseDown) {
                mouseDown = false;



                //get closest vertex to x,y
                temp = virtualGraph.validPoints(x,y);
                if(temp.x != 0 && temp.y != 0){
                    foundPos = true;
                    dropX = temp.x;
                    dropY = temp.y;
                }
                else{
                    foundPos = false;
                    dropX = curX;
                    dropY = curY;
                }

                //check if the move is valid
                isValidMove = virtualGraph.moveToken(
                                    curX,curY,dropX,dropY,tiger.getTurn());


                //if the vertex is closest and the move is in a valid direction
                if(isValidMove && foundPos){
                    if(tiger.getTurn()){
                        tiger.move(dropX, dropY);
                        tiger.setIsTurn(false);
                        //if the tiger jumps a man, curX and curY will have
                        //   been updated my moveToken() to reflect the man's
                        //   location
                        for(int i = 0; i < s; i++){
                            if((men[i].getLocation().x == curX) &&
                                            (men[i].getLocation().y == curY)){
                                men[i].setAlive(false);
                            }
                        }
                    }
                    else{
                        men[p].move(dropX, dropY);
                        tiger.setIsTurn(true);

                        //check if tiger is surrounded
                        tiger.setSurrounded(virtualGraph.checkSurrounded(
                                tiger.getLocation().x, tiger.getLocation().y));
                    }
                }
                //Snap back to original position
                else{
                    if(tiger.getTurn()){
                        tiger.move(curX,curY);
                    }
                    else{
                        men[p].move(curX,curY);
                    }
                }

            }



            //Draw men and get a count of those still alive
            int aliveCount = 0;
            for(int i= 0; i < s; i++){
                if(men[i].getAlive()){
                    men[i].drawMan(g, 0xFF, 0x00, 0x00);
                    aliveCount++;
                }
            }
            if(aliveCount <= 3){
                won = true;
                tigerWins = true;
                justWon = true;
            }


            //Draw Tiger
            tiger.drawTiger(g, 255, 235, 153);
            if(tiger.isSurrounded()){
                won = true;
                justWon = true;
            }

            //Draw whose turn
            if(tiger.getTurn()){
                drawFarmersTurn(g, 35, 25);
            }
            else{
                drawTomatoesTurn(g, 50, 25);
            }
        }

        //Someone has won
        else{

            if(justWon){
                g->clear();
                justWon = false;
            }

            if(tiger.isSurrounded()){
                drawTomatoesWin(g, 52, 25);
            }
            else if(tigerWins){
                drawFarmerWins(g, 43, 25);
           }

            //confetti
            if(i > 0)
                i--;
            g->Sleep(i);
            confetti(g, 30);

        }

        if(g->kbhit()){
            g->getKey();
        }

        g->update();

    }

    return 0;
}



