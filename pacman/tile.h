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
         *  Description: Returns c
         *  Return: int
         *  Precondition: none
         *  Postcondition: c is returned
         */
        int getCol();
        /*
         *  Description: Returns posX
         *  Return: int
         *  Precondition: none
         *  Postcondition: posX is returned
         */
        int getPosX();
        /*
         *  Description: Returns posY
         *  Return: int
         *  Precondition: none
         *  Postcondition: posY is returned
         */
        int getPosY();
        /*
         *  Description: Returns the Point object center
         *  Return: Point
         *  Precondition: none
         *  Postcondition: center is returned
         */
        Point getCenter();
        /*
         *  Description: Returns pel
         *  Return: Pellet
         *  Precondition: none
         *  Postcondition: pel is returned
         */
        Pellet getPel();
        /*
         *  Description: Returns graphicValue
         *  Return: int
         *  Precondition: none
         *  Postcondition: graphicValue is returned
         */
        int getGraphicVal();
        /*
         *  Description: Sets the r
         *  Return: void
         *  Precondition: int
         *  Postcondition: r is set to row
         */
        void setRow(int row);
        /*
         *  Description: Sets pel
         *  Return: void
         *  Precondition: none
         *  Postcondition: sets the value of pel to true or false.
         */
        void setPel();
        /*
         *  Description: Sets the tiles pel to energy or to nothing
         *  Return: void
         *  Precondition: none
         *  Postcondition: sets Energy for the tile
         */
        void setEnergy();
        /*
         *  Description: Sets c
         *  Return: void
         *  Precondition: int
         *  Postcondition: sets c to col
         */
        void setCol(int col);
        /*
         *  Description: Sets isValid or isPath
         *  Return: void
         *  Precondition: bool isP
         *  Postcondition: sets isValid to isP
         */
        void setPath(bool isP);
        /*
         *  Description: Sets Pel state
         *  Return: void
         *  Precondition: bool active
         *  Postcondition: sets Pel state to active
         */
        void setPel(bool active);
        /*
         *  Description: Sets the Graphic Value for the tile
         *  Return: void
         *  Precondition: int a
         *  Postcondition: sets graphicValue to a
         */
        void setGraphicVal(int a);
        /*
         *  Description: Checks the isValid boolean and returns it
         *  Return: boolean
         *  Precondition: none
         *  Postcondition: returns the isValid value
         */
        bool isPath();
        /*
         *  Description: Draws the tile
         *  Return: void
         *  Precondition: SDL_Plotter object
         *  Postcondition: Sets a tile blank
         */
        void drawTile(SDL_Plotter& g);
        /*
         *  Description: Draws a tile based on the graphic array
         *  Return: void
         *  Precondition: SDL_Plotter object and 3 dimensional int array
         *  Postcondition: Sets a tile to its corresponding graphic
         */
        void drawTile(SDL_Plotter& g, int graphic[31][25][25]);

};


#endif // TILE_H_INCLUDED
