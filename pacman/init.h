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
#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>

/*
 *  Description: This function is used to initialize the entire map.
 *      It loads all font letters and number as well as the map tiles and tile graphics.
 *  Return: void
 *  Precondition: It requires a Tile map, SDL_Plotter object, and three int arrays
 *  Postcondition: N/A
 */
void init(Tile map[36][28], SDL_Plotter& g, int nums[10][25][25], int lets[26][25][25], int graphic[31][25][25]) {
    ifstream inMap, inGraphicsVal, inGraphics;
    bool readBool;
    int graphicVal, garb;


    inMap.open("MapTextReference/MAPTEXT.txt");
    inGraphicsVal.open("MapTextReference/WALLS.txt");
    inGraphics.open("MapTextReference/WallGraphics.txt");

    // Create All of the tiles
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c] = Tile(r, c, true);
        }
    }

    // Set specific tiles to isPath to true
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            inMap >> readBool;
            map[r][c].setPath(readBool);
        }
    }

    // Set specific tiles to have and active Pellet
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            inMap >> readBool;
            if(readBool) {
                map[r][c].setPel(true);
            }

            if((r == 26 && c == 1) || (r == 26 && c == 26)
               || (r == 6 && c == 1) || (r == 6 && c == 26))
            {
                map[r][c].setEnergy();
                map[r][c].setPel(true);
            }
        }
    }

    // Set specific tiles to have certain graphic values
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            inGraphicsVal >> graphicVal;
            map[r][c].setGraphicVal(graphicVal);
        }
    }

    // Import all wall graphics
    for(int i = 0; i < 31; i++) {
        inGraphics >> garb;
        for(int j = 0; j < 25; j++) {
            for(int k = 0; k < 25; k++) {
                inGraphics >> graphic[i][j][k];
            }
        }

    }

    // Draw all the wall graphic tiles
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c].drawTile(g, graphic);
        }
    }


    inMap.close();
    inGraphicsVal.close();
    inGraphics.close();
}

#endif // INIT_H_INCLUDED
