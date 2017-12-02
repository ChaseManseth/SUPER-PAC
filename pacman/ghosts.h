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

#ifndef GHOSTS_H_INCLUDED
#define GHOSTS_H_INCLUDED

#include "pacman.h"
#include "SDL_Plotter.h"
#include "tile.h"
#include <queue>
#include "color.h"
#include "point.h"

#include <cmath>

using namespace std;

class Ghost{
    private:
        bool active;
        int dir;
        bool scatter;
        Color color;
        int r, c;
        int radius;
        Point center;
        int targetR;
        int targetC;
    public:
        /*
         *  Description: Sets default Values for a ghost, included
         *   for sending ghosts in a function
         *  Return: n /a
         *  Precondition: none
         *  Postcondition: defaults are set
         */
        Ghost();

        /*
         *  Description: Sets initial values for a ghost.
         *  Return: n / a
         *  Precondition: init has been called before creating the ghost.
         *  Postcondition: initial values are set.
         */
        Ghost(Color Col, Tile map[36][28]);

        /*
         *  Description: returns ghost direction
         *  Return: int
         *  Precondition: none
         *  Postcondition: direction is returned
         */
        int getDir();

        /*
         *  Description: returns the state of the ghost
         *  Return: bool
         *  Precondition: none
         *  Postcondition: returns state of the ghost
         */
        bool getActive();

        /*
         *  Description: returns the center point of the ghost
         *  Return: Point
         *  Precondition: init has been run
         *  Postcondition: Center is returned
         */
        Point getCenter();

        /*
         *  Description: returns row in map
         *  Return: int
         *  Precondition: init has been run
         *  Postcondition: returns Row
         */
        int getR();

        /*
         *  Description: returns Col in map
         *  Return: int
         *  Precondition: init has been run
         *  Postcondition: returns Col
         */
        int getC();

        /*
         *  Description: sets Center
         *  Return: void
         *  Precondition: none
         *  Postcondition: Center = p
         */
        void setCenter(Point p);

        /*
         *  Description: sets Direction
         *  Return: void
         *  Precondition: none
         *  Postcondition: Dir = d
         */
        void setDir(int d);

        /*
         *  Description: sets Active
         *  Return: void
         *  Precondition: none
         *  Postcondition: active = b
         */
        void setActive(bool b);

        /*
         *  Description: sets ghost Color
         *  Return: void
         *  Precondition: none
         *  Postcondition: color = c
         */
        void setColor(Color c);

        /*
         *  Description: sets R
         *  Return: void
         *  Precondition: none
         *  Postcondition: r = row
         */
        void setR(int row);

        /*
         *  Description: sets C
         *  Return: void
         *  Precondition: none
         *  Postcondition: c = col
         */
        void setC(int col);

        /*
         *  Description: Checks to see if a ghost is colliding with Pacman
         *  Return: bool
         *  Precondition: init has been run, pacman is initialized
         *  Postcondition: returns true if a ghost is touching pacman
         */
        bool isCollide(Tile map[36][28], Pacman& p, SDL_Plotter& g);

        /*
         *  Description: makes the ghost target pacman
         *  Return: void
         *  Precondition: pacman and ghost are initialized
         *  Postcondition: Target R and target C are pacmans R and C
         */
        void target(Pacman pac);

        /*
         *  Description: Draws the ghost onto the Plotter
         *  Return: void
         *  Precondition: none
         *  Postcondition: Ghost is drawn to plotter
         */
        void draw(SDL_Plotter& g, Tile map[36][28])const;

        /*
         *  Description: erases the ghost from the plotter
         *  Return: void
         *  Precondition: draw was called before
         *  Postcondition: ghost is no longer on plotter
         */
        void erase(SDL_Plotter& g, Tile map[36][28])const;

        /*
         *  Description: checks if the ghost can move up, and the distance
         *   from the tile with the same C and R-1 to the ghost is sent back
         *  Return: bool, double by ref
         *  Precondition: ghost is active
         *  Postcondition: bool is returned if able to move up, dist is returned
         */
        bool moveUp(Tile map[36][28], SDL_Plotter& g, double& uDist);

        /*
         *  Description: checks if the ghost can move Left, and the distance
         *   from the tile with the same R and C-1 to the ghost is sent back
         *  Return: bool, double by ref
         *  Precondition: ghost is active
         *  Postcondition: bool is returned if able to move left, dist is returned
         */
        bool moveLeft(Tile map[36][28], SDL_Plotter& g, double& lDist);

        /*
         *  Description: checks if the ghost can move Down, and the distance
         *   from the tile with the same C and R+1 to the ghost is sent back
         *  Return: bool, double by ref
         *  Precondition: ghost is active
         *  Postcondition: bool is returned if able to move down, dist is returned
         */
        bool moveDown(Tile map[36][28], SDL_Plotter& g, double& dDist);

        /*
         *  Description: checks if the ghost can move right, and the distance
         *   from the tile with the same R and C+1 to the ghost is sent back
         *  Return: bool, double by ref
         *  Precondition: ghost is active
         *  Postcondition: bool is returned if able to move Right, dist is returned
         */
        bool moveRight(Tile map[36][28], SDL_Plotter& g, double& rDist);

        /*
         *  Description: makes the ghost move in the direction closest to pacman.
         *  Return: void
         *  Precondition: none
         *  Postcondition: ghost's direction is set to be closest to pacman
         */
        void move(Tile map[36][28], SDL_Plotter& g);

        /*
         *  Description: makes the ghost move in the direction furthest from pacman.
         *  Return: void
         *  Precondition: none
         *  Postcondition: ghost's direction is set to be furthest from pacman
         */
        void moveFrightened(Tile map[36][28], SDL_Plotter& g, Pacman pac);

};

#endif // GHOSTS_H_INCLUDED
