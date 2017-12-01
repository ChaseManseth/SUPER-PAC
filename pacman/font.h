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

using namespace std;

const int CHARCOUNT = 36;
const int COLCOUNT = 25;
const int ROWCOUNT = 25;
const int NUMCOUNT = 10;
enum letter{a = 0,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
char font[CHARCOUNT][COLCOUNT][ROWCOUNT];
int numbers[NUMCOUNT][COLCOUNT][ROWCOUNT];

void initLetter(SDL_Plotter& g, int c, int r, letter ltr){
    ifstream inFont;
    string trash;
    int startX = c * 25;
    int startY = r * 25;
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
                cout << row << " " << col << " " << numbers[num][row][col] << endl;
                g.plotPixel(col + startX, row + startY, 255,255,255);
            }
        }
    }
}

void updateScore(int score, SDL_Plotter& g){
    string scoreString;
    int row = 1;  //stubbed values
    int col = 8;
    ostringstream convert;

    //allows for the score to act as individual digits in a string
    score = 11203456;
    convert << score;
    scoreString = convert.str();

    //prints the individual digit one at a time
    for(int i = 0; i < scoreString.size(); i++){
        char x = scoreString.at(i);
        //x + 48: ascii to int
        printNum(g, (col+i), row, x + 48);
    }
}

void eraseScore(){

}

#endif // FONT_H_INCLUDED



