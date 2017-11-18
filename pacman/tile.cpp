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

#include "tile.h"

Tile::Tile()
{
    r = 0;
    c = 0;
    isValid = true;
}
Tile::Tile(int row, int col, bool isP)
{
   r = row;
   c = col;
   isValid = isP;

   posX = c * SIZE_TILE;
   posY = r * SIZE_TILE;

   center = Point(col * SIZE_TILE + 12, row * SIZE_TILE + 12);
}
int Tile::getRow()
{
    return r;
}
int Tile::getCol()
{
    return c;
}
int Tile::getPosX()
{
    return posX;
}
int Tile:: getPosY()
{
    return posY;
}
Point Tile::getCenter()
{
    return center;
}

Pellet Tile::getPel(){
    return pel;
}

void Tile::setPel() {
    pel.setActive(false);
}

void Tile::setRow(int row)
{
    r = row;
    posY = r * SIZE_TILE;
}
void Tile::setCol(int col)
{
    c = col;
    posX = c * SIZE_TILE;
}
void Tile::setPath(bool isP)
{
    isValid = isP;
}

bool Tile::isPath()
{
    return isValid;
}
void Tile::drawTile(SDL_Plotter& g)
{
    for(int col = c * SIZE_TILE; col < c * SIZE_TILE + SIZE_TILE; col++)
    {
        for(int row = r * SIZE_TILE; row < r * SIZE_TILE + SIZE_TILE; row++)
        {
            if(isPath())
            {
                pel.draw(getCenter(), g);
                g.plotPixel(col, row, 0, 0, 0);
            }
            else if(!isPath())
            {
                g.plotPixel(col, row, 150, 150, 255);

            }
        }
    }
}
