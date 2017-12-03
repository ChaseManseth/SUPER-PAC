/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 12/4/2017
* Date Created: 11/1/2017
* Date Last Modified: 12/3/2017
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

        /*
         * Description: The function reads the data from
         *              "font.txt" to the three-dimensional array font
         * Return: none
         * Precondition: "font.txt" has data
         * Postcondition: the font array has enough data to print the alphabet
         */
void initLetter();
        /*
         * Description: A single letter is drawn
         * Return: none
         * Precondition: g, c, r, and ltr exist
         * Postcondition: A letter, indicated by the enum ltr,
         *                is drawn to the SDL Plotter
         */
void drawLetter(SDL_Plotter& g, int c, int r, letter ltr);
        /*
         * Description: The function reads the data from
         *              "nums.txt" to the three-dimensional array font
         * Return: none
         * Precondition: "nums.txt" has data
         * Postcondition: the font array has enough data
         *                to print the numbers 0-9
         */
void initNumber();
        /*
         * Description: A single number is drawn
         * Return: none
         * Precondition: g, c, r, and num exist
         * Postcondition: A number is displayed the SDL Plotter
         */
void printNum(SDL_Plotter& g, int c, int r, int num);
        /*
         * Description: Uses the printNum() function
         *              to print the new value of score
         * Return: none
         * Precondition: g, score, and map exist
         * Postcondition: The current score is displayed on the SDL Plotter
         */
void updateScore(int score, SDL_Plotter& g, Tile map[36][28]);



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

    // Imports numbers
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

    int row = 1;
    int col = 7;
    int n = 0;
    //n is the number of digits in score

    //counts the number of digits in score
    for(int max = 1; max <= score; max *=10){
        n++;
    }

    // erases the previous score
    for(int i = 0; i < n; i++){
        map[row][col+n-i].drawTile(g);
    }

    //prints each digit of score
    for(int i = 0; i < n; i++){
        printNum(g, col+n-i, row, score%10);
        score /= 10;
    }
}
#endif // FONT_H_INCLUDED



