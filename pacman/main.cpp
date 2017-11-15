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

#include <iostream>
#include <fstream>
#include "pacman.h"
#include "tile.h"
#include "ghosts.h"


using namespace std;

int main(int argc, char** argv)
{
    Mix_Chunk *gEat = NULL;
    Mix_Music *gAmbient = NULL;
    ifstream inData;
    bool readValue;
    SDL_Plotter g(900,700);

    //initialize audio functionality
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //initialize sound files
    gEat = Mix_LoadWAV("wakka_wakka1.wav");
    gAmbient = Mix_LoadMUS("ghosts_ambient.wav");

    Tile map[36][28];

    inData.open("mapText.txt");

    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c] = Tile(r, c, true);
        }
    }
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            inData >> readValue;
            map[r][c].setPath(readValue);
        }
    }
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c].drawTile(g);
        }
    }
    Color blink(255,20,20);
    Pacman pac(26,13);
    Ghost Blinky(blink, map);

    Color pink(255,102,178);
    Ghost pinky(pink, map);
    pinky.setR(14);
    pinky.setC(18);
    pinky.setCenter(map[14][16].getCenter());


    pac.drawPac(g);


    char key;

    int speed = 1;
    const int MAX_SPEED = 10;
    Mix_PlayMusic(gAmbient, -1 );

    while(!g.getQuit())
    {
        for(int i = 0; i < 85; i++)
        {
            if(pac.getWaka() == HALF2 && i % 10 == 0)
            {
                pac.setWaka(CLOSED_WAKA);
            }
            else if(i % 10 == 0)
            {
                pac.setWaka(pac.getWaka() + 1);
            }
            pinky.erase(g, map);
            map[pinky.getR()][pinky.getC()].drawTile(g);
            pinky.target(pac);
            pinky.move(map, g);
            pinky.draw(g, map);
            if(pinky.isCollide(map, pac, g))
            {
                g.Sleep(1000);
                Blinky.erase(g, map);
                pinky.erase(g, map);

                Blinky.setR(14);
                Blinky.setC(9);
                Blinky.setCenter(map[14][13].getCenter());

                pinky.setR(14);
                pinky.setC(18);
                pinky.setCenter(map[14][18].getCenter());
            }

            Blinky.erase(g, map);
            map[Blinky.getR()][Blinky.getC()].drawTile(g);
            Blinky.target(pac);
            Blinky.move(map, g);
            Blinky.draw(g, map);
            if(Blinky.isCollide(map, pac, g))
            {
                g.Sleep(1000);
                Blinky.erase(g, map);
                pinky.erase(g, map);

                Blinky.setR(14);
                Blinky.setC(9);
                Blinky.setCenter(map[14][13].getCenter());

                pinky.setR(14);
                pinky.setC(18);
                pinky.setCenter(map[14][18].getCenter());
            }
            if(pac.eat(map))
            {
                Mix_PlayChannel( -1, gEat, 0 );
            }
            pac.drawPac(g);
            g.update();






            //draw(cout, x1, y1, x2, y2);

            if(g.kbhit())
            {
                key = g.getKey();
                pac.erasePac(g);

                switch(key)
                {
                    case RIGHT_ARROW: if(map[pac.getR()][pac.getC() + 1].isPath() && abs(pac.getCenter().y - (pac.getR() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(RIGHT);
                                      }
                                      pac.movePosition(pac.getDirection(), map, g);
                                      Blinky.target(pac);
                                      break;
                    case LEFT_ARROW:  if(map[pac.getR()][pac.getC() - 1].isPath() && abs(pac.getCenter().y - (pac.getR() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(LEFT);
                                      }
                                      pac.movePosition(pac.getDirection(), map, g);
                                      Blinky.target(pac);
                                      break;
                    case UP_ARROW:    if(map[pac.getR() - 1][pac.getC()].isPath() && abs(pac.getCenter().x - (pac.getC() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(UP);
                                      }
                                      pac.movePosition(pac.getDirection(), map, g);
                                      Blinky.target(pac);
                                      break;
                    case DOWN_ARROW:  if(map[pac.getR() + 1][pac.getC()].isPath() && abs(pac.getCenter().x - (pac.getC() * 25 + 12)) <= 4)
                                      {
                                            pac.setDirection(DOWN);
                                      }
                                      pac.movePosition(pac.getDirection(), map, g);
                                      Blinky.target(pac);
                                      break;
                }

            }
            else
            {
                pac.erasePac(g);
                pac.movePosition(pac.getDirection(), map, g);
                Blinky.target(pac);
            }
            g.Sleep(15);
        }

}






    return 0;
}
