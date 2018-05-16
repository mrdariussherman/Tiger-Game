/*
 * Authors: Darius Sherman, Rachel Bugge, Elise Hebert, Mackensi Holt, and
 *          Maggie Burton
 * File Description: Draws the physical game board to the screen
 * Date Created: 4/6/2018
 * Dates Modified:
 *    4/10/2018: Horizontal and diagonal lines
 *    4/13/2018: Added diagonal lines
 *    4/20/2018: Added words
 *    4/24/2018: Added flare to circles
 */

#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "Global.h"
#include "Point.h"

/*
 * description: draws the lines of the gameboard to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: the gameboard is drawn to the Plotter
 */
void drawGrid(SDL_Plotter *g){
    int R = 0x4E;
    int G = 0x2C;
    int B = 0x07;

    // Draw horizontal lines
    for(int i = 4; i < 13; i++){
        for(int j = 0; j < (SCREEN_WIDTH - 2*(xNOT) - (m/2)); j++){
            g->plotPixel(xNOT + j, yNOT + (i*m), R,G,B);
        }
    }

    // Draw vertical lines
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < m*8; j++){
            g->plotPixel(xNOT + (i*m), yNOT + (m*4) + j, R,G,B);
        }
    }

    //decreasing diagonal #1
    int k = 0;
    for(int i = 0; i < 100; i++) {
        g->plotPixel(xNOT + 200 + k, yNOT + i, R, G, B);
        k += 1;
    }
    //decreasing diagonal #2
    k = 0;
    for(int i = 0; i < 100; i++) {
        g->plotPixel(xNOT + 150 + k, yNOT + 50 + i, R, G, B);
        k += 1;
    }
    //decreasing diagonal #3
    k = 0;
    for(int i = 0; i < 300; i++) {
        //for (int j = 0; j < 9; j++) {}
        g->plotPixel(xNOT + 100 + k, yNOT + 100 + i, R, G, B);
        k+=1;
    }
    //decreasing diagonal #4
    k = 0;
    for(int i = 0; i < 200; i++) {
        g->plotPixel(xNOT + 0 + k, yNOT + 400 + i, R, G, B);
        k += 1;
    }

    //increasing diagonal #1
    k = 0;
    for(int i = 0; i < 100; i++) {
        g->plotPixel(-226 - (xNOT + k), yNOT + i + 1, R,G,B);
        k += 1;
    }
    //increasing diagonal #2
    k = 0;
    for(int i = 0; i < 100; i++) {
        g->plotPixel(-176 - (xNOT + k), yNOT + i + 51, R,G,B);
        k += 1;
    }
    //increasing diagonal #3
    k = 0;
    for(int i = 0; i < 300; i++) {
        g->plotPixel(-126 - (xNOT + k), yNOT + i + 101, R,G,B);
        k += 1;
    }
    //increasing diagonal #4
    k = 0;
    for(int i = 0; i < 200; i++) {
        g->plotPixel(-25 - (xNOT + k), yNOT + i + 400, R,G,B);
        k += 1;
    }
}

/*
 * description: writes "Farmer's Turn" to SDL Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: "Farmer's Turn" is drawn to the Plotter
 */
void drawFarmersTurn(SDL_Plotter *g, int x, int y){
    drawF(g, x + 105, y);
    drawA(g, x + 116, y);
    drawR(g, x + 131, y);
    drawM(g, x + 140, y);
    drawE(g, x + 155, y);
    drawR(g, x + 169, y);
    drawApos(g, x + 177, y);
    drawS(g, x + 182, y);

    drawLowerT(g, x + 200, y);
    drawU(g, x + 207, y);
    drawR(g, x + 221, y);
    drawN(g, x + 231, y);
}

/*
 * description: draws "Farmer Wins!" to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: "Farmer Wins!" is drawn to the Plotter
 */
void drawFarmerWins(SDL_Plotter *g, int x, int y){
    drawF(g, x + 105, y);
    drawA(g, x + 116, y);
    drawR(g, x + 131, y);
    drawM(g, x + 140, y);
    drawE(g, x + 155, y);
    drawR(g, x + 169, y);

    drawW(g, x + 185, y);
    drawI(g, x + 197, y);
    drawN(g, x + 202, y);
    drawS(g, x + 213, y);
    drawEx(g, x + 225, y);
}

/*
 * description: draws "Tomatoes' Turn" to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: "Tomatoes' Turn" is drawn to the Plotter
 */
void drawTomatoesTurn(SDL_Plotter *g, int x, int y){
    drawCapT(g, x + 82, y);
    drawO(g, x + 90, y);
    drawM(g, x + 103, y);
    drawA(g, x + 117, y);
    drawLowerT(g, x + 131, y);
    drawO(g, x + 138, y);
    drawE(g, x + 151, y);
    drawS(g, x + 164, y);
    drawApos(g, x + 176, y);

    drawLowerT(g, x + 185, y);
    drawU(g, x + 192, y);
    drawR(g, x + 206, y);
    drawN(g, x + 216, y);


}

/*
 * description: draws "Tomatoes Win!" to the Plotter
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: "Tomatoes Win!" is drawn to the Plotter
 */
void drawTomatoesWin(SDL_Plotter *g, int x, int y){
    drawCapT(g, x + 82, y);
    drawO(g, x + 90, y);
    drawM(g, x + 103, y);
    drawA(g, x + 117, y);
    drawLowerT(g, x + 131, y);
    drawO(g, x + 138, y);
    drawE(g, x + 151, y);
    drawS(g, x + 164, y);

    drawW(g, x + 185, y);
    drawI(g, x + 197, y);
    drawN(g, x + 202, y);
    drawEx(g, x + 215, y);
}

/*
 * description: draws leaves on a tomato object
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: leaves are drawn on the tomatoes
 */
void drawTomatoLeaves(SDL_Plotter *g, Point center){
    int R = 0;
    int G = 90;
    int B = 0;

    int cx = center.x;
    int cy = center.y;


        for(int i = 5; i <= 6; i++)
            g->plotPixel(cx - 14, cy - i, R,G,B);


        for(int i = 6; i <= 8; i++)
            g->plotPixel(cx - 13, cy - i, R,G,B);


        for(int i = 7; i <= 9; i++)
            g->plotPixel(cx - 12, cy - i, R,G,B);


        for(int i = 7; i <= 10; i++)
            g->plotPixel(cx - 11, cy - i, R,G,B);


        for(int i = 8; i <= 11; i++)
            g->plotPixel(cx - 10, cy - i, R,G,B);


        for(int i = 8; i <= 12; i++)
            g->plotPixel(cx - 9, cy - i, R,G,B);


        for(int i = 1; i <= 5; i++)
            g->plotPixel(cx - 8, cy - i, R,G,B);
        for(int i = 9; i <= 13; i++)
            g->plotPixel(cx - 8, cy - i, R,G,B);


        for(int i = 3; i <= 9; i++)
            g->plotPixel(cx - 7, cy - i, R,G,B);
        for(int i = 10; i <= 13; i++)
            g->plotPixel(cx - 7, cy - i, R,G,B);


        for(int i = 4; i <= 14; i++)
            g->plotPixel(cx - 6, cy - i, R,G,B);


        for(int i = 5; i <= 14; i++)
            g->plotPixel(cx - 5, cy - i, R,G,B);


        for(int i = 6; i <= 14; i++)
            g->plotPixel(cx - 4, cy - i, R,G,B);


        for(int i = 8; i <= 14; i++)
            g->plotPixel(cx - 3, cy - i, R,G,B);


        for(int i = 9; i <= 15; i++)
            g->plotPixel(cx - 2, cy - i, R,G,B);


        for(int i = 10; i <= 17; i++)
            g->plotPixel(cx - 1, cy - i, R,G,B);


        for(int i = 10; i <= 18; i++)
            g->plotPixel(cx, cy - i, R,G,B);


        for(int i = 9; i <= 19; i++)
            g->plotPixel(cx + 1, cy - i, R,G,B);


        for(int i = 7; i <= 19; i++)
            g->plotPixel(cx + 2, cy - i, R,G,B);


        for(int i = 15; i <= 19; i++)
            g->plotPixel(cx + 3, cy - i, R,G,B);
        for(int i = 13; i <= 14; i++)
            g->plotPixel(cx + 3, cy - i, R,G,B);
        for(int i = 6; i <= 11; i++)
            g->plotPixel(cx + 3, cy - i, R,G,B);


        for(int i = 16; i <= 19; i++)
            g->plotPixel(cx + 4, cy - i, R,G,B);
        for(int i = 5; i <= 10; i++)
            g->plotPixel(cx + 4, cy - i, R,G,B);
        for(int i = 13; i <= 14; i++)
            g->plotPixel(cx + 4, cy - i, R,G,B);


        for(int i = 17; i <= 19; i++)
            g->plotPixel(cx + 5, cy - i, R,G,B);
        for(int i = 4; i <= 9; i++)
            g->plotPixel(cx + 5, cy - i, R,G,B);
        for(int i = 12; i <= 14; i++)
            g->plotPixel(cx + 5, cy - i, R,G,B);


        for(int i = 3; i <= 5; i++)
            g->plotPixel(cx + 6, cy - i, R,G,B);
        for(int i = 11; i <= 14; i++)
            g->plotPixel(cx + 6, cy - i, R,G,B);


        for(int i = 10; i <= 13; i++)
            g->plotPixel(cx + 7, cy - i, R,G,B);


        for(int i = 9; i <= 13; i++)
            g->plotPixel(cx + 8, cy - i, R,G,B);


        for(int i = 8; i <= 12; i++)
            g->plotPixel(cx + 9, cy - i, R,G,B);


        for(int i = 6; i <= 11; i++)
            g->plotPixel(cx + 10, cy - i, R,G,B);


        for(int i = 5; i <= 10; i++)
            g->plotPixel(cx + 11, cy - i, R,G,B);


        for(int i = 4; i <= 8; i++)
            g->plotPixel(cx + 12, cy - i, R,G,B);
}

/*
 * description: draws clothing on the farmer
 * return: void
 * precondition: an SDL Plotter exists
 * postcondition: clothes are drawn on the farmer
 */
void drawFarmerClothing(SDL_Plotter *g, Point center){
    int R = 0;
    int G = 89;
    int B = 179;

    int cx = center.x;
    int cy = center.y;

        for(int i = 2; i <= 6; i++){
            g->plotPixel(cx - 14, cy + i, R,G,B);
            g->plotPixel(cx + 14, cy + i, R,G,B);

        }

        for(int i = 2; i <= 8; i++){
            g->plotPixel(cx - 13, cy + i, R,G,B);
            g->plotPixel(cx + 13, cy + i, R,G,B);
        }

        for(int i = 1; i <= 9; i++){
            g->plotPixel(cx - 12, cy + i, R,G,B);
            g->plotPixel(cx + 12, cy + i, R,G,B);
        }

        for(int i = -10; i <= 10; i++){
            g->plotPixel(cx - 11, cy + i, R,G,B);
            g->plotPixel(cx + 11, cy + i, R,G,B);
        }

        for(int i = -11; i <= 11; i++){
            g->plotPixel(cx - 10, cy + i, R,G,B);
            g->plotPixel(cx + 10, cy + i, R,G,B);
        }

        for(int i = -12; i <= 12; i++){
            g->plotPixel(cx - 9, cy + i, R,G,B);
            g->plotPixel(cx + 9, cy + i, R,G,B);
        }

        for(int i = 1; i <= 13; i++){
            g->plotPixel(cx - 8, cy + i, R,G,B);
            g->plotPixel(cx + 8, cy + i, R,G,B);
        }

        for(int i = 1; i <= 13; i++){
            g->plotPixel(cx - 7, cy + i, R,G,B);
            g->plotPixel(cx + 7, cy + i, R,G,B);
        }

        for(int i = 1; i <= 14; i++){
            g->plotPixel(cx - 6, cy + i, R,G,B);
            g->plotPixel(cx + 6, cy + i, R,G,B);
        }

        for(int i = 1; i <= 14; i++){
            g->plotPixel(cx - 5, cy + i, R,G,B);
            g->plotPixel(cx + 5, cy + i, R,G,B);
        }

        for(int i = 1; i <= 15; i++){
            g->plotPixel(cx - 4, cy + i, R,G,B);
            g->plotPixel(cx + 4, cy + i, R,G,B);
        }

        for(int i = 1; i <= 15; i++){
            g->plotPixel(cx - 3, cy + i, R,G,B);
            g->plotPixel(cx + 3, cy + i, R,G,B);
        }

        for(int i = 1; i <= 15; i++){
            g->plotPixel(cx - 2, cy + i, R,G,B);
            g->plotPixel(cx + 2, cy + i, R,G,B);
        }

        for(int i = 1; i <= 15; i++){
            g->plotPixel(cx - 1, cy + i, R,G,B);
            g->plotPixel(cx , cy + i, R,G,B);
            g->plotPixel(cx + 1, cy + i, R,G,B);
        }



        for(int i = 3; i <= 10; i++){
            for(int j = 0; j <= 7; j++){
                g->plotPixel(cx - j, cy + i, 0,51,102);
                g->plotPixel(cx + j, cy + i, 0,51,102);
            }
        }


        for(int i = -13; i <= -11; i++){
            for(int j = 0; j <= 15; j++){
                g->plotPixel(cx - j, cy + i, 102,51,0);
                g->plotPixel(cx + j, cy + i, 102,51,0);
            }
        }

        for(int i = -20; i <= -17; i++){
            for(int j = 0; j <= 9; j++){
                g->plotPixel(cx - j, cy + i, 102,51,0);
                g->plotPixel(cx + j, cy + i, 102,51,0);
            }
        }

        for(int i = -16; i <= -14; i++){
            for(int j = 0; j <= 9; j++){
                g->plotPixel(cx - j, cy + i, 138,138,92);
                g->plotPixel(cx + j, cy + i, 138,138,92);
            }
        }


}

#endif // DRAW_H_INCLUDED
