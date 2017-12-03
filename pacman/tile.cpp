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
int Tile::getGraphicVal() {
    return graphicValue;
}

void Tile::setPel() {
    pel.setActive(false);
}
void Tile::setEnergy()
{
    pel.isEnergizer = true;
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
void Tile::setPel(bool active) {
    pel.setActive(active);
}
void Tile::setGraphicVal(int a) {
    graphicValue = a;
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
                g.plotPixel(col, row, 0, 0, 0);

            }
        }
    }
}

void Tile::drawTile(SDL_Plotter& g, int graphic[31][25][25]) {
    //r = y
    //c = x
    int graphicPos = 0;
    int startX = c * 25;
    int startY = r * 25;

    for(int row = 0; row < 25; row++) {
        for(int col = 0; col < 25; col++) {
                switch(getGraphicVal()) {
                    case 10:    graphicPos = 1;
                                break;
                    case 11:    graphicPos = 2;
                                break;
                    case 12:    graphicPos = 3;
                                break;
                    case 13:    graphicPos = 4;
                                break;
                    case 14:    graphicPos = 5;
                                break;
                    case 15:    graphicPos = 6;
                                break;
                    case 16:    graphicPos = 7;
                                break;
                    case 17:    graphicPos = 8;
                                break;
                    case 18:    graphicPos = 9;
                                break;
                    case 19:    graphicPos = 10;
                                break;
                    case 20:    graphicPos = 11;
                                break;
                    case 21:    graphicPos = 12;
                                break;
                    case 22:    graphicPos = 13;
                                break;
                    case 23:    graphicPos = 14;
                                break;
                    case 24:    graphicPos = 15;
                                break;
                    case 25:    graphicPos = 16;
                                break;
                    case 26:    graphicPos = 17;
                                break;
                    case 27:    graphicPos = 18;
                                break;
                    case 28:    graphicPos = 19;
                                break;
                    case 29:    graphicPos = 20;
                                break;
                    case 30:    graphicPos = 21;
                                break;
                    case 31:    graphicPos = 22;
                                break;
                    case 32:    graphicPos = 23;
                                break;
                    case 33:    graphicPos = 24;
                                break;
                    case 34:    graphicPos = 25;
                                break;
                    case 35:    graphicPos = 26;
                                break;
                    case 36:    graphicPos = 27;
                                break;
                    case 37:    graphicPos = 28;
                                break;
                    case 38:    graphicPos = 29;
                                break;
                    case 39:    graphicPos = 30;
                                break;
                };

                if(graphic[graphicPos][row][col] == 1) {
                    g.plotPixel(col + startX, row + startY, 150,150,255);
                } else {
                    g.plotPixel(col + startX, row + startY, 0,0,0);
                }
        }
    }

     if(pel.active) {
        pel.draw(getCenter(), g);
    }
}
