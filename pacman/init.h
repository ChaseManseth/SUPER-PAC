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
#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include "SDL_Plotter.h"
#include <fstream>
#include <string>
#include "font.h"
#include "pacman.h"

using namespace std;

/*
 *  Description: This function is used to initialize the entire map.
 *      It loads all font letters and number as well as the map tiles and tile graphics.
 *  Return: void
 *  Precondition: It requires a Tile map, SDL_Plotter object, and three int arrays
 *  Postcondition: N/A
 */
void init(Tile map[36][28], SDL_Plotter& g, int nums[10][25][25], int lets[26][25][25], int graphic[31][25][25], int ghosts[4][25][25]) {
    ifstream inMap, inGraphicsVal, inGraphics, inGhosts;
    bool readBool;
    int graphicVal, garb;
    string trash;


    inMap.open("MapTextReference/MAPTEXT.txt");
    inGhosts.open("ghostImages.txt");
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
    for(int i =0; i < 4; i++){
        for(int r = 0; r < 25; r++){
            for(int c = 0; c < 25; c++){
                inGhosts >> ghosts[i][r][c];
            }
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
    inGhosts.close();
}
/*
 *  Description: This function acts as a start menu for the user.
 *  Return: void
 *  Precondition: SDL_Plotter g is valid
 *  Postcondition: User stays on start menu until key is hit
 */
void startMenu(SDL_Plotter& g){

    Mix_Chunk *gEat         = NULL;
    bool hit = false;
    Mix_Chunk *gPowerPellet = NULL;
    gEat = Mix_LoadWAV("wakka_wakka1.wav");
    gPowerPellet = Mix_LoadWAV("power_pellet_eaten.wav");
    for(int x = 0; x < 700; x++)
    {
        for(int y = 0; y < 900; y++)
        {
            g.plotPixel(x, y, 0, 0, 0);
        }
    }
    initLetter();

    drawLetter(g, 11, 16, p);
    g.update();
    Mix_PlayChannel( -1, gEat, 0 );
    g.Sleep(500);
    drawLetter(g, 12, 16, a);
    g.update();
    Mix_PlayChannel( -1, gEat, 0 );
    g.Sleep(500);
    drawLetter(g, 13, 16, c);
    g.update();
    Mix_PlayChannel( -1, gEat, 0 );
    g.Sleep(500);
    drawLetter(g, 14, 16, m);
    g.update();
    Mix_PlayChannel( -1, gEat, 0 );
    g.Sleep(500);
    drawLetter(g, 15, 16, a);
    g.update();
    Mix_PlayChannel( -1, gEat, 0 );
    g.Sleep(500);
    drawLetter(g, 16, 16, n);
    g.update();
    Mix_PlayChannel( -1, gPowerPellet, 0 );
    g.Sleep(500);

    //string s = "hit any key to start";

    drawLetter(g, 4, 20, h);
    drawLetter(g, 5, 20, i);
    drawLetter(g, 6, 20, t);
    drawLetter(g, 8, 20, a);
    drawLetter(g, 9, 20, n);
    drawLetter(g, 10, 20, y);
    drawLetter(g, 12, 20, k);
    drawLetter(g, 13, 20, e);
    drawLetter(g, 14, 20, y);
    drawLetter(g, 16, 20, t);
    drawLetter(g, 17, 20, o);
    drawLetter(g, 19, 20, s);
    drawLetter(g, 20, 20, t);
    drawLetter(g, 21, 20, a);
    drawLetter(g, 22, 20, r);
    drawLetter(g, 23, 20, t);

    g.update();

    g.update();

    Pacman pTemp = Pacman(10,3);
    pTemp.setRadius(35);

    while(!hit)
    {
        if(g.kbhit())
        {
            hit = true;
        }
        for(int i = 0; i < 60; i++)
        {
            pTemp.erasePac(g);

            //handle pacman animation
            if(pTemp.getWaka() == HALF2 && i % 8 == 0)
            {
                pTemp.setWaka(CLOSED_WAKA);
            }
            else if(i % 8 == 0)
            {
                pTemp.setWaka(pTemp.getWaka() + 1);
            }
            if(pTemp.getCenter().x == 650)
            {
                pTemp.setDirection(LEFT);
            }
            else if(pTemp.getCenter().x == 50)
            {
                pTemp.setDirection(RIGHT);
            }

            if(pTemp.getDirection() == RIGHT)
            {
                pTemp.setCenter(Point(pTemp.getCenter().x + 1, pTemp.getCenter().y));
            }
            else
            {
                pTemp.setCenter(Point(pTemp.getCenter().x - 1, pTemp.getCenter().y));
            }
            pTemp.drawPac(g);

            g.update();

            g.Sleep(1);
        }
    }

}

#endif // INIT_H_INCLUDED
