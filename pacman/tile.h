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
        void setCol(int col);
        void setPath(bool isP);

        bool isPath();
        void drawTile(SDL_Plotter& g);


};


#endif // TILE_H_INCLUDED
