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
        Ghost();
        Ghost(Color Col, Tile map[36][28]);

        int getDir();
        bool getActive();
        Point getCenter();
        int getR();
        int getC();
        void setCenter(Point p);
        void setDir(int d);
        void setActive(bool b);
        void setR(int row);
        void setC(int col);

        bool isCollide(Tile map[36][28], Pacman& p, SDL_Plotter& g);
        //void move(Tile map[36][28], SDL_Plotter& g);
        double distance(Point p1, Point p2);
        void target(Pacman pac);
        void draw(SDL_Plotter& g, Tile map[36][28])const;
        void erase(SDL_Plotter& g, Tile map[36][28])const;

        bool moveUp(Tile map[36][28], SDL_Plotter& g, double& uDist);
        bool moveLeft(Tile map[36][28], SDL_Plotter& g, double& lDist);
        bool moveDown(Tile map[36][28], SDL_Plotter& g, double& dDist);
        bool moveRight(Tile map[36][28], SDL_Plotter& g, double& rDist);
        void move(Tile map[36][28], SDL_Plotter& g);

};

#endif // GHOSTS_H_INCLUDED
