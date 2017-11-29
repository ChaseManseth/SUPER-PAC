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
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Ghost();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Ghost(Color Col, Tile map[36][28]);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getDir();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool getActive();
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
        void setCenter(Point p);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setDir(int d);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setActive(bool b);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setColor(Color c);
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
        bool isCollide(Tile map[36][28], Pacman& p, SDL_Plotter& g);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        double distance(Point p1, Point p2);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void target(Pacman pac);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void draw(SDL_Plotter& g, Tile map[36][28])const;
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void erase(SDL_Plotter& g, Tile map[36][28])const;
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool moveUp(Tile map[36][28], SDL_Plotter& g, double& uDist);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool moveLeft(Tile map[36][28], SDL_Plotter& g, double& lDist);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool moveDown(Tile map[36][28], SDL_Plotter& g, double& dDist);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool moveRight(Tile map[36][28], SDL_Plotter& g, double& rDist);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void move(Tile map[36][28], SDL_Plotter& g);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void moveFrightened(Tile map[36][28], SDL_Plotter& g, Pacman pac);

};

#endif // GHOSTS_H_INCLUDED
