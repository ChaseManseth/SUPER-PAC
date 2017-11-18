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

#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include "SDL_Plotter.h"
#include "point.h"
#include "pellet.h"

using namespace std;

const int SIZE_TILE = 25;

class Tile
{
    private:
        int r, c;
        int posX, posY;
        Point center;
        bool isValid;
        Pellet pel;
    public:
        Tile(int row, int col, bool isP);
        Tile();
        int getRow();
        int getCol();
        int getPosX();
        int getPosY();
        Point getCenter();
        Pellet getPel();

        void setRow(int row);
        void setPel();
        void setEnergy();
        void setCol(int col);
        void setPath(bool isP);

        bool isPath();
        void drawTile(SDL_Plotter& g);


};


#endif // TILE_H_INCLUDED
