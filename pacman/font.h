/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 11/29/2017
* Date Created: 11/1/2017
* Date Last Modified: 11/11/2017
*/

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "SDL_Plotter.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include "map.h"
#include "SDL_Plotter.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include "tile.h"

using namespace std;

const int CHARCOUNT = 36;
const int COLCOUNT = 25;
const int ROWCOUNT = 25;
const int NUMCOUNT = 10;
enum letter{a = 0,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
char font[CHARCOUNT][COLCOUNT][ROWCOUNT];
int numbers[NUMCOUNT][COLCOUNT][ROWCOUNT];

void initLetter(){
    ifstream inFont;
    string trash;
    inFont.open("font.txt");

    // Import letters
    for(int i = 0; i < CHARCOUNT; i++) {
        inFont >> trash;
        for(int j = 0; j < ROWCOUNT; j++) {
            for(int k = 0; k < COLCOUNT; k++) {
                inFont >> font[i][j][k];
            }
        }
    }
    inFont.close();
}

void drawLetter(SDL_Plotter& g, int c, int r, letter ltr){
    int startX = c * 25;
    int startY = r * 25;

    //prints single character
    for(int row = 0; row < ROWCOUNT; row++) {
        for(int col = 0; col < COLCOUNT; col++) {
            if(font[ltr][row][col] == '1') {
                g.plotPixel(col + startX, row + startY, 255,255,255);
            }
        }
    }
}

void initNumber(){
    ifstream inNum;

    inNum.open("nums.txt");

    // Import number
    for(int i = 0; i < NUMCOUNT; i++) {
        for(int j = 0; j < ROWCOUNT; j++) {
            for(int k = 0; k < COLCOUNT; k++) {
                inNum >> numbers[i][j][k];
            }

        }
    }
    inNum.close();
}

void printNum(SDL_Plotter& g, int c, int r, int num)
{
    int startX = c * 25;
    int startY = r * 25;
    //prints single character

    for(int row = 0; row < ROWCOUNT; row++) {
        for(int col = 0; col < COLCOUNT; col++) {
            if(numbers[num][row][col] == 1) {
                g.plotPixel(col + startX, row + startY, 255,255,255);
            }
        }
    }
}

void updateScore(int score, SDL_Plotter& g,  Tile map[36][28]){


    int row = 1;  //stubbed values
    int col = 8;
    int n = 0;

    for(int max = 1; max < score; max *=10){
        n++;
    }

    for(int i = 0; i < n;i++){
        map[row][col+n-i].drawTile(g);
    }

    for(int i = 0; i < n; i++){
        printNum(g, col+n-i, row, score%10);
        score /= 10;
    }


}

void eraseScore(){

}

#endif // FONT_H_INCLUDED



