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

#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "point.h"
#include "color.h"
#include "line.h"
#include "SDL_Plotter.h"
#include "tile.h"
#include <cmath>

const int NORMAL = 0, SUPERPAC = -1;
const int UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4;
const int CLOSED_WAKA = 5, HALF_WAKA = 6, FULL_WAKA = 7, HALF2 = 8;

class Pacman
{
    private:
        int lives;
        int r, c;
        Point center;
        int radius;
        int state;
        int speed;
        int score;
        int waka;
        int direction;

    public:
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Pacman(int row, int col);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getLives();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getState();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getWaka();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getSpeed();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getDirection();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getScore();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Point getCenter();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getR();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getC();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setR(int row);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setC(int col);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setLives(int l);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setState(int st);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setCenter(Point c);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setSpeed(int s);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setWaka(int w);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setDirection(int d);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setScore(int p);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool eat(Tile map[36][28], int& count);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void movePosition(int d, Tile map[36][28], SDL_Plotter& g);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void erasePac(SDL_Plotter& g);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void drawPac(SDL_Plotter& g);

};

#endif // PACMAN_H_INCLUDED
