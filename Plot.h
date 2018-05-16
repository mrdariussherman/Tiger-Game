/*
 * Authors: Mackensi Holt, Maggie Burton, Rachel Bugge, Elise Hebert,
 *        Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: Creates a virtual representation of the physical game
 *                   board and functions and attributes to interact with it
 * Due Date: 4/26/2018
 * Date Created: 4/01/2018
 * Dates Modified:
 *    4/13/2018: HashTable created
 *    4/17/2018: moveTokens modified, validPoints created
 *    4/19/2018: modified for tiger jumping
 *    4/19/2018: modified for men winning
 */

#ifndef PLOT_H_INCLUDED
#define PLOT_H_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>
#include "Point.h"

using namespace std;




/*
    @struct     Index
    @brief      Store information about where to find vertex in pos 2d array
*/
struct Index{
    int row = 0;        // row in pos 2d array where vertex info is stored
    int col = 0;        // col in pos 2d array where vertex info is stored
    int x = 0;          // x coordinate of the physical location of the vertex
    int y = 0;          // y coordinate of the physical location of the vertex
};


/*
    @class      Vertex
    @brief      Represents a vertex in the physical graph. Stores information
                about which of eight possible directions are valid moves for a
                token to make from a particular vertex.
*/
class Vertex{
private:
    Point location;

    bool isOccupied;

    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool upLeft = false;
    bool upRight = false;
    bool downLeft = false;
    bool downRight = false;

public:
    void setLocation(int x, int y){location.x = x; location.y = y;}
    Point getLocation(){return location;}

    void setOccupied(bool setting){isOccupied = setting;}
    bool getOccupied(){return isOccupied;}


    void setDirections(bool setUp, bool setDown, bool setLeft, bool setRight,
        bool setUpLeft, bool setUpRight, bool setDownLeft, bool setDownRight);

    bool getUp(){return up;}
    bool getDown(){return down;}
    bool getLeft(){return left;}
    bool getRight(){return right;}
    bool getUpLeft(){return upLeft;}
    bool getUpRight(){return upRight;}
    bool getDownLeft(){return downLeft;}
    bool getDownRight(){return downRight;}

};


/*
    @name       setDirections
    @brief      Sets the valid movement directions for each vertex
    @param      bool setUp         declare up direction true or false
                bool setDown       declare down direction true or false
                bool setLeft       declare left direction true or false
                bool setRight      declare right direction true or false
                bool setUpLeft     declare upLeft direction true or false
                bool setUpRight    declare upRight direction true or false
                bool setDownLeft   declare downLeft direction true or false
                bool setDownRight  declare downRight direction true or false
    @return     void
*/
void Vertex::setDirections(bool setUp, bool setDown, bool setLeft,
        bool setRight, bool setUpLeft, bool setUpRight, bool setDownLeft,
        bool setDownRight){

    up = setUp;
    down = setDown;
    left = setLeft;
    right = setRight;
    upLeft = setUpLeft;
    upRight = setUpRight;
    downLeft = setDownLeft;
    downRight = setDownRight;
}


/*
    @class      Plot
    @brief      Represents the physical graph through a 2d array and a hash
                table to find the correct position in the array for a
                particular vertex.
*/
class Plot{
private:
    Vertex pos[13][9];          //2d array of Vertices [row][col]
    const int hashSize = 149;   //size of hashTable
    vector<Index> hashTable;    //Stores the indices of pos through a hash


    void SetUpVertices();
    void SetHashTable(int xNOT, int yNOT, int r, int c);
    int hashFunction(int x, int y);
    int Hash(int x, int y);
    bool deltaCheck(int deltaX, int deltaY, int row, int col);


public:

    Plot();

    bool moveToken(int &curX, int &curY, int dropX, int dropY, bool tigerTurn);
    Point validPoints(int x, int y);
    bool checkSurrounded(int curX, int curY);

    void print();
};

/*
    @name       SetUpVertices
    @brief      set valid movement directions of each vertex
    @return     void
*/
void Plot::SetUpVertices(){
    // Set row 0
    // Columns not called have no active directions
    pos[0][4].setDirections(0,0,0,0,0,0,1,1);

    // Set row 1
    // Columns not called have no active directions
    pos[1][3].setDirections(0,0,0,0,0,1,1,1);
    pos[1][5].setDirections(0,0,0,0,1,0,1,1);

    // Set row 2
    // Columns not called have no active directions
    pos[2][2].setDirections(0,0,0,0,0,1,0,1);
    pos[2][4].setDirections(0,0,0,0,1,1,1,1);
    pos[2][6].setDirections(0,0,0,0,1,0,1,0);

    // Set row 3
    // Columns not called have no active directions
    pos[3][3].setDirections(0,0,0,0,1,1,0,1);
    pos[3][5].setDirections(0,0,0,0,1,1,1,0);

    // Set row 4
    pos[4][0].setDirections(0,1,0,1,0,0,0,0);
    pos[4][1].setDirections(0,1,1,1,0,0,0,0);
    pos[4][2].setDirections(0,1,1,1,0,0,0,0);
    pos[4][3].setDirections(0,1,1,1,0,0,0,0);
    pos[4][4].setDirections(0,1,1,1,1,1,1,1);
    pos[4][5].setDirections(0,1,1,1,0,0,0,0);
    pos[4][6].setDirections(0,1,1,1,0,0,0,0);
    pos[4][7].setDirections(0,1,1,1,0,0,0,0);
    pos[4][8].setDirections(0,1,1,0,0,0,0,0);

    // Set row 5
    pos[5][0].setDirections(1,1,0,1,0,0,0,0);
    pos[5][1].setDirections(1,1,1,1,0,0,0,0);
    pos[5][2].setDirections(1,1,1,1,0,0,0,0);
    pos[5][3].setDirections(1,1,1,1,0,1,1,0);
    pos[5][4].setDirections(1,1,1,1,0,0,0,0);
    pos[5][5].setDirections(1,1,1,1,1,0,0,1);
    pos[5][6].setDirections(1,1,1,1,0,0,0,0);
    pos[5][7].setDirections(1,1,1,1,0,0,0,0);
    pos[5][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 6
    pos[6][0].setDirections(1,1,0,1,0,0,0,0);
    pos[6][1].setDirections(1,1,1,1,0,0,0,0);
    pos[6][2].setDirections(1,1,1,1,0,1,1,0);
    pos[6][3].setDirections(1,1,1,1,0,0,0,0);
    pos[6][4].setDirections(1,1,1,1,0,0,0,0);
    pos[6][5].setDirections(1,1,1,1,0,0,0,0);
    pos[6][6].setDirections(1,1,1,1,1,0,0,1);
    pos[6][7].setDirections(1,1,1,1,0,0,0,0);
    pos[6][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 7
    pos[7][0].setDirections(1,1,0,1,0,0,0,0);
    pos[7][1].setDirections(1,1,1,1,0,1,1,0);
    pos[7][2].setDirections(1,1,1,1,0,0,0,0);
    pos[7][3].setDirections(1,1,1,1,0,0,0,0);
    pos[7][4].setDirections(1,1,1,1,0,0,0,0);
    pos[7][5].setDirections(1,1,1,1,0,0,0,0);
    pos[7][6].setDirections(1,1,1,1,0,0,0,0);
    pos[7][7].setDirections(1,1,1,1,1,0,0,1);
    pos[7][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 8
    pos[8][0].setDirections(1,1,0,1,0,1,0,1);
    pos[8][1].setDirections(1,1,1,1,0,0,0,0);
    pos[8][2].setDirections(1,1,1,1,0,0,0,0);
    pos[8][3].setDirections(1,1,1,1,0,0,0,0);
    pos[8][4].setDirections(1,1,1,1,0,0,0,0);
    pos[8][5].setDirections(1,1,1,1,0,0,0,0);
    pos[8][6].setDirections(1,1,1,1,0,0,0,0);
    pos[8][7].setDirections(1,1,1,1,0,0,0,0);
    pos[8][8].setDirections(1,1,1,0,1,0,1,0);

    // Set row 9
    pos[9][0].setDirections(1,1,0,1,0,0,0,0);
    pos[9][1].setDirections(1,1,1,1,1,0,0,1);
    pos[9][2].setDirections(1,1,1,1,0,0,0,0);
    pos[9][3].setDirections(1,1,1,1,0,0,0,0);
    pos[9][4].setDirections(1,1,1,1,0,0,0,0);
    pos[9][5].setDirections(1,1,1,1,0,0,0,0);
    pos[9][6].setDirections(1,1,1,1,0,0,0,0);
    pos[9][7].setDirections(1,1,1,1,0,1,1,0);
    pos[9][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 10
    pos[10][0].setDirections(1,1,0,1,0,0,0,0);
    pos[10][1].setDirections(1,1,1,1,0,0,0,0);
    pos[10][2].setDirections(1,1,1,1,1,0,0,1);
    pos[10][3].setDirections(1,1,1,1,0,0,0,0);
    pos[10][4].setDirections(1,1,1,1,0,0,0,0);
    pos[10][5].setDirections(1,1,1,1,0,0,0,0);
    pos[10][6].setDirections(1,1,1,1,0,1,1,0);
    pos[10][7].setDirections(1,1,1,1,0,0,0,0);
    pos[10][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 11
    pos[11][0].setDirections(1,1,0,1,0,0,0,0);
    pos[11][1].setDirections(1,1,1,1,0,0,0,0);
    pos[11][2].setDirections(1,1,1,1,0,0,0,0);
    pos[11][3].setDirections(1,1,1,1,1,0,0,1);
    pos[11][4].setDirections(1,1,1,1,0,0,0,0);
    pos[11][5].setDirections(1,1,1,1,0,1,1,0);
    pos[11][6].setDirections(1,1,1,1,0,0,0,0);
    pos[11][7].setDirections(1,1,1,1,0,0,0,0);
    pos[11][8].setDirections(1,1,1,0,0,0,0,0);

    // Set row 12
    pos[12][0].setDirections(1,0,0,1,0,0,0,0);
    pos[12][1].setDirections(1,0,1,1,0,0,0,0);
    pos[12][2].setDirections(1,0,1,1,0,0,0,0);
    pos[12][3].setDirections(1,0,1,1,0,0,0,0);
    pos[12][4].setDirections(1,0,1,1,1,1,0,0);
    pos[12][5].setDirections(1,0,1,1,0,0,0,0);
    pos[12][6].setDirections(1,0,1,1,0,0,0,0);
    pos[12][7].setDirections(1,0,1,1,0,0,0,0);
    pos[12][8].setDirections(1,0,1,0,0,0,0,0);

    // Set occupancy
    for(int r = 0; r < 13; r++){
        for(int c = 0; c < 9; c++){
            if(r >= 11)
                pos[r][c].setOccupied(true);
            else
                pos[r][c].setOccupied(false);
        }
    }
}


/*
    @name       SetHashTable
    @brief      Uses physical coordinates to place 2d array location of each
                vertex in a hash table
    @param      int xNOT      physical x coordinate of [0][0]
                int yNOT      physical y coordinate of [0][0]
                int r       row location in 2d array of vertex being hashed
                int c       column location of 2d array of vertex being hashed
    @return     void
*/
void Plot::SetHashTable(int xNOT, int yNOT, int r, int c){

    int tempX = xNOT + c*m;   //physical x coordinate of vertex being hashed
    int tempY = yNOT + r*m;   //physical y coordinate of vertex being hashed
    int hashVal = hashFunction(tempX, tempY);  // hash of x and y coordinates

    //While the index in the hash table is occupied, increase the index by 1
    //while(hashTable[temp].row + hashTable[temp].col != 0){
      //  temp = (temp+1) % hashSize;
    //}

    //quadratic probe
    int i = 1;
    int temp = hashVal;
    while(hashTable[temp].row + hashTable[temp].col != 0){
        temp = (hashVal + (i*i)) % hashSize;
        i++;
    }

    //If the index in the hash table is not occupied, insert vertex info
    if(hashTable[temp].row == 0 && hashTable[temp].col == 0){
        hashTable[temp].row = r;
        hashTable[temp].col = c;
        hashTable[temp].x = tempX;
        hashTable[temp].y = tempY;

    }
    else{
        cout << "collision [" << r << "][" << c << "] " << temp << endl;
    }

}

/*
    @name       hashFunction
    @brief      Hash the physical x and y coordinates of a particular vertex
    @param      int x   x coordinate of location to hash
                int y   y coordinate of location to hash
    @return     int     the value computed in the hash function, corresponding
                        to an index in the hash table
*/
int Plot::hashFunction(int x, int y){
    return (x*x - y) % hashSize;
}

/*
    @name       Hash
    @brief      Take physical coordinates and hash. Probe hashTable until
                the correct index is found
    @param      int x   x coordinate of location to hash
                int y   y coordinate of location to hash
    @return     int     the index of hashTable with stores the correct info
                        about the vertex
*/
int Plot::Hash(int x, int y){

    int hashVal = hashFunction(x,y);

    int i = 0;
    int temp = hashVal;


    while(hashTable[temp].x != x || hashTable[temp].y != y){
        i++;
        temp = (hashVal + (i*i)) % hashSize;
    }

    return temp;
}

/*
    @name       deltaCheck
    @brief      determine, based on deltaX and deltaY, if the direction the
                token wants to move to is a valid direction based on the
                current vertex.
    @param      int deltaX  change in x position
                int deltaY  change in y position
                int row     row index in pos array
                int col     col index in pos array
    @return     bool        true if direction is valid, false otherwise
*/
bool Plot::deltaCheck(int deltaX, int deltaY, int row, int col){
    bool isValidDrop = false;
        //up
        if(deltaX == 0 && deltaY == 1){
            isValidDrop = pos[row][col].getUp();
        }
        //down
        else if(deltaX == 0 && deltaY == -1){
            isValidDrop = pos[row][col].getDown();
        }
        //left
        else if(deltaX == 1 && deltaY == 0){
            isValidDrop = pos[row][col].getLeft();
        }
        //right
        else if(deltaX == -1 && deltaY == 0){
            isValidDrop = pos[row][col].getRight();
        }
        //upLeft
        else if(deltaX == 1 && deltaY == 1){
            isValidDrop = pos[row][col].getUpLeft();
        }
        //upRight
        else if(deltaX == -1 && deltaY == 1){
            isValidDrop = pos[row][col].getUpRight();
        }
        //downLeft
        else if(deltaX == 1 && deltaY == -1){
            isValidDrop = pos[row][col].getDownLeft();
        }
        //downRight
        else if(deltaX == -1 && deltaY == -1){
            isValidDrop = pos[row][col].getDownRight();
        }

    return isValidDrop;
}

/*
    @name       Plot (constructor)
    @brief      The size of the hashTable is initialized to hashSize.
                Calls SetUpVertices() and SetHashTable for each active vertex.
    @return     none
*/
Plot::Plot():hashTable(hashSize){
    //Set valid directions for each vertex
    SetUpVertices();

    int temp;
    int r, c;

    //for rows 4-12, hash each physical location and store vertex info
    for(r = 4; r < 13; r++){
        for(c = 0; c < 9; c++){
            SetHashTable(xNOT, yNOT, r, c);
            pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);
        }
    }

    //for row r and column c, has the physical location and store vertex info
    for(r = 0; r < 4; r++){
        for(c = 0; c < 9; c++){
            pos[r][c].setLocation(0,0);
        }
    }

    r = 0;
    c = 4;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 1;
    c = 3;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 1;
    c = 5;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 2;
    c = 2;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 2;
    c = 4;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 2;
    c = 6;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 3;
    c = 3;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);

    r = 3;
    c = 5;
    SetHashTable(xNOT, yNOT, r, c);
    pos[r][c].setLocation(xNOT + c * m, yNOT + r * m);
}

/*
    @name       moveToken
    @brief      Hash the current location to get vertex info. Determine in
                which direction the drop is trying to occur. Check if that
                direction is a valid direction to move. If valid, update
                the occupancy of the current vertex and drop vertex.
    @param      int &curX       current x coordinate; If tiger tries to jump it
                                will be updated with the location of the man
                int &curY       current y coordinate; If tiger tries to jump it
                                will be updated with the location of the man
                int dropX       x coordinate to drop to
                int dropY       y coordinate to drop to
                bool tigerTurn  true if currently the tiger's turn, false
                                otherwise
    @return     bool            true if the move is in a valid direction that
                                is unoccupied, false otherwise
*/
bool Plot::moveToken(int &curX, int &curY, int dropX,
                     int dropY, bool tigerTurn){

    //get hash of current location
    int curHash = Hash(curX, curY);
    int row = hashTable[curHash].row;
    int col = hashTable[curHash].col;

    //Calculate differences in x and y
    int deltaX = (curX - dropX)/m;
    int deltaY = (curY - dropY)/m;

    bool isValidDrop = false;
    bool isOccupied;

    //Normal move
    if(abs(deltaX) <= 1 && abs(deltaY) <= 1){
        isValidDrop = deltaCheck(deltaX, deltaY, row, col);
        isOccupied = pos[row - deltaY][col - deltaX].getOccupied();

        if(isValidDrop && !isOccupied){
            pos[row][col].setOccupied(false);
            pos[row - deltaY][col - deltaX].setOccupied(true);
        }
        else{
            isValidDrop = false;
        }
    }

    //If tiger tries to jump
    else if(tigerTurn && (abs(deltaX) == 2 || abs(deltaY) == 2)){
        deltaX /= 2;
        deltaY /= 2;

        //Check first location for valid direction and occupancy
        isValidDrop = deltaCheck(deltaX, deltaY, row, col);
        isOccupied = pos[row - deltaY][col - deltaX].getOccupied();

        if(isValidDrop && isOccupied){
            //Check second location for valid direction and occupancy
            isValidDrop = deltaCheck(deltaX, deltaY, row-deltaX, col-deltaY);
            isOccupied = pos[row - 2*deltaY][col - 2*deltaX].getOccupied();

            if(isValidDrop && !isOccupied){
                pos[row][col].setOccupied(false);
                pos[row-deltaY][col-deltaX].setOccupied(false);
                pos[row - 2*deltaY][col - 2*deltaX].setOccupied(true);

                curX = pos[row-deltaY][col-deltaX].getLocation().x;
                curY = pos[row-deltaY][col-deltaX].getLocation().y;

            }
            else{
                isValidDrop = false;
            }
        }
        else{
            isValidDrop = false;
        }

    }

    return isValidDrop;
}


/*
    @name       validPoints
    @brief      Determine which vertex is closest to x and y
    @param      int x    current x coordinate
                int y    current y coordinate
    @return     Point    the x and y values corresponding to the coordinates
                         of the closest valid vertex within m/2 - 2 pixels
                         away, OR x = 0, y = 0 if a vertex is not valid or no
                         vertex is close enough.
*/
Point Plot::validPoints(int x, int y){

    int dist;
    Point temp;
    Point Pos;
    Pos.x = 0;
    Pos.y = 0;
    for(int r = 0; r < 13; r++){
        for(int c = 0; c < 9; c++){
            temp = pos[r][c].getLocation();
            if(temp.x != 0 && temp.y != 0){
                dist = sqrt(pow((temp.x - x),2) + pow((temp.y - y),2));
                if(dist < m/2 - 2){
                    Pos.x = temp.x;
                    Pos.y = temp.y;
                }
            }
        }
    }

    return Pos;

}


/*
    @name       checkSurrounded
    @brief      Determine if a vertex is surrounded
    @param      int curX   current x coordinate
                int curY   current y coordinate
    @return     bool       true if a vertex is surrounded, false otherwise
*/
bool Plot::checkSurrounded(int curX, int curY){
    //get hash of current location
    int curHash = Hash(curX, curY);
    int row = hashTable[curHash].row;
    int col = hashTable[curHash].col;

    bool surrounded = true;

    int deltaX, deltaY;

    if(curX != 0 && curY != 0){
        //check up
        deltaX = 0;
        deltaY = 1;
        if(pos[row][col].getUp()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getUp()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check down
        deltaX = 0;
        deltaY = -1;
        if(pos[row][col].getDown()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getDown()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }



        //check left
        deltaX = 1;
        deltaY = 0;
        if(pos[row][col].getLeft()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getLeft()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check right
        deltaX = 1;
        deltaY = 0;
        if(pos[row][col].getRight()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getRight()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check upLeft
        deltaX = 1;
        deltaY = 1;
        if(pos[row][col].getUpLeft()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getUpLeft()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check upRight
        deltaX = -1;
        deltaY = 1;
        if(pos[row][col].getUpRight()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getUpRight()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check downLeft
        deltaX = 1;
        deltaY = -1;
        if(pos[row][col].getDownLeft()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getDownLeft()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }


        //check downRight
        deltaX = -1;
        deltaY = -1;
        if(pos[row][col].getDownRight()){
            if(pos[row - deltaY][col - deltaX].getOccupied()){
                if(pos[row-deltaY][col-deltaX].getDownRight()){
                    if(!pos[row - 2*deltaY][col - 2*deltaX].getOccupied()){
                        surrounded = false;
                    }
                }
            }
            else{
                surrounded = false;
            }
        }
    }
    else{
        surrounded = false;
    }

    return surrounded;

}

/*Debugging function*/
void Plot::print(){

    // Test hash table indicies

  /*  for(int i = 0; i < hashSize; i++){
        cout << i << ": [" << hashTable[i].row << "][" << hashTable[i].col
            << "] -> (" << hashTable[i].x << "," << hashTable[i].y
            << ")"<< endl;
    }
    /**/


    //Test locations
/*    Point temp;
    for(int r = 0; r < 13; r++){
        for(int c = 0; c < 9; c++){
            temp = pos[r][c].getLocation();
            if(temp.x == 0){
                cout << "  (0,0)    ";
            }
            else
                cout << "(" << temp.x << "," << temp.y << ")  ";
        }
        cout << endl;
    }
/**/


    // Test vertex directions
/*
    for(int r = 0; r < 13; r++){
        for(int c = 0; c < 9; c++){

            if(pos[r][c].getUpLeft() == true){
                cout << "\\ ";
            }
            else
                cout << "  ";

            if(pos[r][c].getUp() == true)
                cout << "| ";
            else
                cout << "  ";

            if(pos[r][c].getUpRight() == true)
                cout << "/ ";
            else
                cout << "  ";

        }
        cout<< endl;
        for(int c = 0; c < 9; c++){
            if(pos[r][c].getLeft() == true)
                cout << "- ";
            else
                cout << "  ";

            if(pos[r][c].getOccupied() == true)
                cout << "o ";
            else
                cout << "  ";

            if(pos[r][c].getRight() == true)
                cout << "- ";
            else
                cout << "  ";
        }
        cout << endl;
        for(int c = 0; c < 9; c++){

            if(pos[r][c].getDownLeft() == true)
                cout << "/ ";
            else
                cout << "  ";

            if(pos[r][c].getDown() == true)
                cout << "| ";
            else
                cout << "  ";

            if(pos[r][c].getDownRight() == true)
                cout << "\\ ";
            else
                cout << "  ";

        }
        cout << endl;
    }
    /**/

}


#endif // PLOT_H_INCLUDED
