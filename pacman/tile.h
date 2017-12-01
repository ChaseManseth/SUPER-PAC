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
        int graphicValue;
    public:
        /*
         *  Description: Constructor, takes row col, and isP,
         *   and assigns them to r, c, and isValid, respectively.
         *  Return: n / a
         *  Precondition: none
         *  Postcondition: r, c, and isValid are set to row, col, and isP
         */
        Tile(int row, int col, bool isP);
        /*
         *  Description: Constructor, r and c are set to 0, isValid to true
         *  Return: n / a
         *  Precondition: none
         *  Postcondition: r and c are assigned 0, isValid is assigned true
         */
        Tile();
        /*
         *  Description: Returns r
         *  Return: int
         *  Precondition: none
         *  Postcondition: r is returned
         */
        int getRow();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getCol();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getPosX();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getPosY();
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
        Pellet getPel();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getGraphicVal();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setRow(int row);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setPel();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setEnergy();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setCol(int col);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setPath(bool isP);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setPel(bool active);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setGraphicVal(int a);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        bool isPath();
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void drawTile(SDL_Plotter& g);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void drawTile(SDL_Plotter& g, int graphic[31][25][25]);

};


#endif // TILE_H_INCLUDED
