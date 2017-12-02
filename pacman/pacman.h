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
const int MID_PIXEL_OF_TILE = 12;

class Pacman
{
    private:
        int lives;
        int r, c;
        Point center;
        int radius;
        int state;
        int nextDir;
        int score;
        int waka;
        int direction;

    public:
        /*
         *  Description: Constructor for a Pacman object
         *  Return: none
         *  Precondition: row and col exist
         *  Postcondition: r is assigned row, c is assigned col,
         *                 Pacman is assigned initial, predetermined values
         */
        Pacman(int row, int col);
        /*
         *  Description: Returns the value of lives
         *  Return: int
         *  Precondition: lives exists
         *  Postcondition: the value for lives is returned, unaltered
         */
        int getLives() const;
        /*
         *  Description: Returns the value of state
         *  Return: int
         *  Precondition: state exists
         *  Postcondition: the value for state is returned, unaltered
         */
        int getState() const;
        /*
         *  Description: Returns the value of waka, the
         *               mouth state of open or closed
         *  Return: int
         *  Precondition: waka exists
         *  Postcondition: the value for waka is returned, unaltered
         */
        int getWaka()  const;
        /*
         *  Description: Returns the value of nextDir
         *  Return: int
         *  Precondition: nextDir exists
         *  Postcondition: the value for nextDir is returned, unaltered
         */
        int getNextDir() const;
        /*
         *  Description: Returns the value of direction
         *  Return: int
         *  Precondition: direction exists
         *  Postcondition: the value for direction is returned, unaltered
         */
        int getDirection() const;
        /*
         *  Description: Returns the value of score
         *  Return: int
         *  Precondition: score exists
         *  Postcondition: the value for score is returned, unaltered
         */
        int getScore() const;
        /*
         *  Description: Returns the the point 'center'
         *  Return: Point
         *  Precondition: center exists
         *  Postcondition: the value for center is returned, unaltered
         */
        Point getCenter() const;
        /*
         *  Description: Returns the value of r (row)
         *  Return: int
         *  Precondition: r exists
         *  Postcondition: the value for r is returned, unaltered
         */
        int getR() const;
        /*
         *  Description: Returns the value of c (column)
         *  Return: int
         *  Precondition: c exists
         *  Postcondition: the value for c is returned, unaltered
         */
        int getC() const;


        /*
         *  Description: Assigns r the value of row
         *  Return: int
         *  Precondition: row exists
         *  Postcondition: r is assigned the value of row
         */
        void setR(int row);
        /*
         *  Description: Assigns c the value of col
         *  Return: none
         *  Precondition: col exists
         *  Postcondition: c is assigned the value of col
         */
        void setC(int col);
        /*
         *  Description: Assigns lives the value of l
         *  Return: none
         *  Precondition: l exists
         *  Postcondition: lives is assigned the value of l
         */
        void setLives(int l);
        /*
         *  Description: Assigns nextDir the value of d
         *  Return: none
         *  Precondition: d exists
         *  Postcondition: nextDir is assigned the value of d
         */
         void setNextDir(int d);
        /*
         *  Description: Assigns state the value of st
         *  Return: none
         *  Precondition: st exists
         *  Postcondition: r is assigned the value of row
         */
        void setState(int st);
        /*
         *  Description: Assigns center the value of c
         *  Return: none
         *  Precondition: row exists
         *  Postcondition: r is assigned the value of row
         */
        void setCenter(Point c);
        /*
         *  Description: Assigns waka the value of w
         *  Return: none
         *  Precondition: w exists
         *  Postcondition: waka is assigned the value of w
         */
        void setWaka(int w);
        /*
         *  Description: Assigns direction the value of d
         *  Return: none
         *  Precondition: d exists
         *  Postcondition: direction is assigned the value of d
         */
        void setDirection(int d);
        /*
         *  Description: Assigns score the value of p
         *  Return: none
         *  Precondition: p exists
         *  Postcondition: score is assigned the value of p
         */
        void setScore(int p);

        /*
         *  Description: Returns true of a pellet or energizer has been eaten
         *  Return: bool
         *  Precondition: map and count exist
         *  Postcondition: r is assigned the value of row
         *                 Score is increased if a pellet is eaten
         *                 If an energizer is eaten, state is assigned SUPERPAC
         */
        bool eat(Tile map[36][28], int& count);

        /*
         *  Description: Controls the movement of Pacman
         *  Return: none
         *  Precondition: d, map, and g exist
         *  Postcondition: Depending on the direction, pacman's position
         *                 is incremented/decremented by one row or one column
         */
        void movePosition(int d, Tile map[36][28], SDL_Plotter& g);
        /*
         *  Description: A black square is drawn over Pacman "erasing" him
         *  Return: none
         *  Precondition: g exists
         *  Postcondition: A black square is drawn over Pacman on the SDL Plotter
         */
        void erasePac(SDL_Plotter& g);
        /*
         *  Description: Draws the yellow circle of Pacman and draws Pacman's
         *               mouth based on the state of waka
         *  Return: none
         *  Precondition: g, radius and waka exist
         *  Postcondition: Pacman and his mouth are drawn to the SDL Plotter
         */
        void drawPac(SDL_Plotter& g);

};

#endif // PACMAN_H_INCLUDED
