/*
 * Authors: Maggie Burton, Rachel Bugge, Elise Hebert, Mackensi Holt,
 *          Darius Sherman
 * Assignment Title: Tiger Game
 * File Description: Includes functions to draw letters
 * Date Created: 4/20/2018
 * Dates Modified:
 *    4/20/2018: file created
 *    4/25/2018: new letters added
 */


#ifndef ALPHABET_H_INCLUDED
#define ALPHABET_H_INCLUDED

#include "SDL_Plotter.h"

/*
 * description: draws a square of pixels to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: a squre of pixels is drawn on the Plotter
 */
void drawSquare(SDL_Plotter *g, int i0, int j0, int R, int G, int B){
    for(int i = i0; i < 2 + i0; i++){
        for(int j = j0; j < 2 + j0; j++){
            g->plotPixel(i,j,R,G,B);
        }
    }

}

/*
 * description: draws a letter 'a' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'a' is drawn on the Plotter
 */
void drawA(SDL_Plotter *g, int x, int y){

    int letterA[16][12] = {
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //6
            {0,0,0,1,1,1,1,0,0,0,1,0},
            {0,0,1,0,0,0,0,1,0,0,1,0}, //8
            {0,1,0,0,0,0,0,0,1,0,1,0},
            {1,0,0,0,0,0,0,0,0,1,1,0}, //10
            {1,0,0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,0,0,1,0}, //12
            {1,0,0,0,0,0,0,0,0,1,1,0},
            {0,1,0,0,0,0,0,0,1,0,1,0}, //14
            {0,0,1,0,0,0,0,1,0,0,1,0},
            {0,0,0,1,1,1,1,0,0,0,1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 12 + x; j++){
            if(letterA[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }

}

/*
 * description: draws a letter 'e' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'e' is drawn on the Plotter
 */
void drawE(SDL_Plotter *g, int x, int y){
    int letterE[16][11] = {
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //6
            {0,0,0,1,1,1,1,0,0,0,0},
            {0,0,1,0,0,0,0,1,0,0,0}, //8
            {0,1,0,0,0,0,0,0,1,0,0},
            {1,1,1,1,1,1,1,1,1,1,0}, //10
            {1,0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0,0,0}, //12
            {1,0,0,0,0,0,0,0,0,1,0},
            {0,1,0,0,0,0,0,0,1,0,0}, //14
            {0,0,1,0,0,0,0,1,0,0,0},
            {0,0,0,1,1,1,1,0,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 11 + x; j++){
            if(letterE[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'F' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'F' is drawn on the Plotter
 */
void drawF(SDL_Plotter *g, int x, int y){
    int letterF[16][9] = {
            {0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,0}, //2
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}, //4
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}, //6
            {1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,0,0,0}, //8
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}, //10
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}, //12
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}, //14
            {1,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 9 + x; j++){
            if(letterF[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'i' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'i' is drawn on the Plotter
 */
void drawI(SDL_Plotter *g, int x, int y){
    int letterI[16][12] = {
            {0,0},
            {0,0}, //2
            {0,0},
            {0,0}, //4
            {0,0},
            {0,0}, //6
            {1,0},
            {0,0}, //8
            {1,0},
            {1,0}, //10
            {1,0},
            {1,0}, //12
            {1,0},
            {1,0}, //14
            {1,0},
            {1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 12 + x; j++){
            if(letterI[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'm' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'm' is drawn on the Plotter
 */
void drawM(SDL_Plotter *g, int x, int y){
    int letterM[16][12] = {
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0}, //6
            {1,0,0,1,1,0,0,0,1,1,0,0},
            {1,0,1,0,0,1,0,1,0,0,1,0}, //8
            {1,1,0,0,0,1,1,0,0,0,1,0},
            {1,0,0,0,0,1,0,0,0,0,1,0}, //10
            {1,0,0,0,0,1,0,0,0,0,1,0},
            {1,0,0,0,0,1,0,0,0,0,1,0}, //12
            {1,0,0,0,0,1,0,0,0,0,1,0},
            {1,0,0,0,0,1,0,0,0,0,1,0}, //14
            {1,0,0,0,0,1,0,0,0,0,1,0},
            {1,0,0,0,0,1,0,0,0,0,1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 12 + x; j++){
            if(letterM[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'n' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'n' is drawn on the Plotter
 */
void drawN(SDL_Plotter *g, int x, int y){
    int letterN[16][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //6
            {1,0,0,1,1,1,1,0,0,0},
            {1,0,1,0,0,0,0,1,0,0}, //8
            {1,1,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //10
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //12
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //14
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 10 + x; j++){
            if(letterN[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
* description: draws a letter 'o' to the Plotter
* return: void
* precondition: an SDL Plotter exists
* postcondition: the letter 'o' is drawn on the Plotter
*/
void drawO(SDL_Plotter *g, int x, int y){
    int letterO[16][11] = {
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //6
            {0,0,0,1,1,1,1,0,0,0,0},
            {0,0,1,0,0,0,0,1,0,0,0}, //8
            {0,1,0,0,0,0,0,0,1,0,0},
            {1,0,0,0,0,0,0,0,0,1,0}, //10
            {1,0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,0,1,0}, //12
            {1,0,0,0,0,0,0,0,0,1,0},
            {0,1,0,0,0,0,0,0,1,0,0}, //14
            {0,0,1,0,0,0,0,1,0,0,0},
            {0,0,0,1,1,1,1,0,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 11 + x; j++){
            if(letterO[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'r' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'r' is drawn on the Plotter
 */
void drawR(SDL_Plotter *g, int x, int y){
    int letterR[16][8]= {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0}, //6
            {1,0,0,1,1,1,0,0},
            {1,0,1,0,0,0,1,0}, //8
            {1,1,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0}, //10
            {1,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0}, //12
            {1,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0}, //14
            {1,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 8 + x; j++){
            if(letterR[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 's' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 's' is drawn on the Plotter
 */
void drawS(SDL_Plotter *g, int x, int y){
    int letterS[16][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}, //6
            {0,0,0,1,1,1,1,0,0,0},
            {0,0,1,0,0,0,0,1,0,0}, //8
            {0,1,0,0,0,0,0,0,1,0},
            {1,1,0,0,0,0,0,0,0,0}, //10
            {0,0,1,1,1,1,0,0,0,0},
            {0,0,0,0,0,0,1,1,0,0}, //12
            {0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //14
            {0,1,0,0,0,0,0,1,0,0},
            {0,0,1,1,1,1,1,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 10 + x; j++){
            if(letterS[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'T' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'T' is drawn on the Plotter
 */
void drawCapT(SDL_Plotter *g, int x, int y){
    int letterCapT[16][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,0}, //2
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //4
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //6
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //8
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //10
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //12
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}, //14
            {0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 10 + x; j++){
            if(letterCapT[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 't' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 't' is drawn on the Plotter
 */
void drawLowerT(SDL_Plotter *g, int x, int y){
    int letterLowerT[16][5] = {
            {0,0,0,0,0},
            {0,0,0,0,0}, //2
            {0,0,0,0,0},
            {0,0,0,0,0}, //4
            {0,1,0,0,0},
            {0,1,0,0,0}, //6
            {1,1,1,1,0},
            {0,1,0,0,0}, //8
            {0,1,0,0,0},
            {0,1,0,0,0}, //10
            {0,1,0,0,0},
            {0,1,0,0,0}, //12
            {0,1,0,0,0},
            {0,1,0,0,0}, //14
            {0,1,0,1,0},
            {0,0,1,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 5 + x; j++){
            if(letterLowerT[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'u' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'u' is drawn on the Plotter
 */
void drawU(SDL_Plotter *g, int x, int y){
    int letterU[16][11] = {
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //2
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //4
            {0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0}, //6
            {1,0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,0,1,0}, //8
            {1,0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,0,1,0}, //10
            {1,0,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,0,1,0}, //12
            {1,0,0,0,0,0,0,0,1,1,0},
            {0,1,0,0,0,0,0,1,0,1,0}, //14
            {0,0,1,0,0,0,1,0,0,1,0},
            {0,0,0,1,1,1,0,0,0,1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 11 + x; j++){
            if(letterU[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws a letter 'W' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the letter 'W' is drawn on the Plotter
 */
void drawW(SDL_Plotter *g, int x, int y){
    int letterW[16][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {1,0,0,0,0,0,0,0,1,0}, //2
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //4
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //6
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //8
            {1,0,0,0,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,0,1,0}, //10
            {1,1,0,0,1,0,0,1,1,0},
            {0,1,0,0,1,0,0,1,0,0}, //12
            {0,1,0,1,1,1,0,1,0,0},
            {0,1,0,1,0,1,0,1,0,0}, //14
            {0,1,1,1,0,1,1,1,0,0},
            {0,0,1,0,0,0,1,0,0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 10 + x; j++){
            if(letterW[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws an '!' to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: an '!' is drawn on the Plotter
 */
void drawEx(SDL_Plotter *g, int x, int y){
    int letterEx[16][2] = {
            {0,0},
            {0,0}, //2
            {0,0},
            {1,0}, //4
            {1,0},
            {1,0}, //6
            {1,0},
            {1,0}, //8
            {1,0},
            {1,0}, //10
            {1,0},
            {0,0}, //12
            {0,0},
            {0,0}, //14
            {0,0},
            {1,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 2 + x; j++){
            if(letterEx[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}

/*
 * description: draws an apostrophe to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: an apostrophe is drawn on the Plotter
 */
void drawApos(SDL_Plotter *g, int x, int y){
    int letterApos[16][2] = {
            {0,0},
            {0,0}, //2
            {1,1},
            {0,1}, //4
            {1,0},
            {0,0}, //6
            {0,0},
            {0,0}, //8
            {0,0},
            {0,0}, //10
            {0,0},
            {0,0}, //12
            {0,0},
            {0,0}, //14
            {0,0},
            {0,0}

    };
    for(int i = y; i < 16 + y; i++){
        for(int j = x; j < 2 + x; j++){
            if(letterApos[i-y][j-x] == 1){
                drawSquare(g, j*2, i*2, 0, 0, 0);
            }
        }
    }
}


#endif // ALPHABET_H_INCLUDED
