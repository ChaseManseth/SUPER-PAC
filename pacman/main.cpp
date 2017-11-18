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

void rePositionGhosts(SDL_Plotter& g, Ghost& a, Ghost& b, Ghost& c, Ghost& d, Tile map[36][28]);
void releaseGhost(Ghost& a, Tile map[36][28], bool& r);

int main(int argc, char** argv)
{
    Mix_Chunk *gEat = NULL;
    Mix_Music *gAmbient = NULL;
    Mix_Chunk *gDeath = NULL;
    bool releaseCalled = false;
    int numEaten = 0;
    ifstream inData;
    bool readValue;
    SDL_Plotter g(900,700);

    //initialize audio functionality
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    //initialize sound files
    gEat = Mix_LoadWAV("wakka_wakka1.wav");
    gDeath = Mix_LoadWAV("life_lost.wav");
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

            if(map[r][c].isPath() && ((r == 7 && c == 1) ||
                                       (r == 7 && c == 26) ||
                                       (r == 26 && c == 1) ||
                                       (r == 26 && c == 26)))
            {
                map[r][c].setEnergy();
            }
        }
    }
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c].drawTile(g);
        }
    }
    Pacman pac(26,13);

    Color blink(255,20,20);
    Ghost Blinky(blink, map);

    Color pink(255,102,178);
    Ghost pinky(pink, map);

    Color ink(0, 255, 255);
    Ghost inky(ink, map);

    Color cly(255, 165, 0);
    Ghost clyde(cly, map);

    rePositionGhosts(g, Blinky, pinky, inky, clyde, map);

    pac.drawPac(g);


    char key;

    int speed = 1;
    const int MAX_SPEED = 10;
    Mix_PlayMusic(gAmbient, -1 );

    Mix_VolumeMusic(24);

    while(!g.getQuit())
    {
        for(int i = 0; i < 60; i++)
        {
            //handle pacman animation
            if(pac.getWaka() == HALF2 && i % 10 == 0)
            {
                pac.setWaka(CLOSED_WAKA);
            }
            else if(i % 10 == 0)
            {
                pac.setWaka(pac.getWaka() + 1);
            }
            //erase the old position of ghosts
            pinky.erase(g, map);
            map[pinky.getR()][pinky.getC()].drawTile(g);
            Blinky.erase(g, map);
            map[Blinky.getR()][Blinky.getC()].drawTile(g);
            inky.erase(g, map);
            map[inky.getR()][inky.getC()].drawTile(g);
            clyde.erase(g, map);
            map[clyde.getR()][clyde.getC()].drawTile(g);

            //handle ghost movement & collision
            //+ pacman death, death sounds
            pinky.target(pac);
            pinky.move(map, g);
            pinky.draw(g, map);
            if(pinky.isCollide(map, pac, g))
            {
                Mix_PauseMusic();
                Mix_PlayChannel( -1, gDeath, 0 );
                g.Sleep(1500);
                Mix_ResumeMusic();
                rePositionGhosts(g, Blinky, pinky, inky, clyde, map);

            }
            Blinky.target(pac);
            Blinky.move(map, g);
            Blinky.draw(g, map);
            if(Blinky.isCollide(map, pac, g))
            {
                Mix_PauseMusic();
                Mix_PlayChannel( -1, gDeath, 0 );
                g.Sleep(1500);
                Mix_ResumeMusic();
                rePositionGhosts(g, Blinky, pinky, inky, clyde, map);
            }
            inky.target(pac);
            inky.move(map, g);
            inky.draw(g, map);
            if(inky.isCollide(map, pac, g))
            {
                Mix_PauseMusic();
                Mix_PlayChannel( -1, gDeath, 0 );
                g.Sleep(1500);
                Mix_ResumeMusic();
                rePositionGhosts(g, Blinky, pinky, inky, clyde, map);
            }
            clyde.target(pac);
            clyde.move(map, g);
            clyde.draw(g, map);
            if(clyde.isCollide(map, pac, g))
            {
                Mix_PauseMusic();
                Mix_PlayChannel( -1, gDeath, 0 );
                g.Sleep(1500);
                Mix_ResumeMusic();
                rePositionGhosts(g, Blinky, pinky, inky, clyde, map);
            }

            if(pac.eat(map))
            {
                releaseCalled = false;
                numEaten++;
                Mix_PlayChannel( -1, gEat, 0 );
            }

            //releasing ghosts based on pellet eating
            if(numEaten % 24 == 0 && !releaseCalled)
            {
                if(!Blinky.getActive())
                {
                    map[Blinky.getR()][Blinky.getC()].drawTile(g);
                    releaseGhost(Blinky, map, releaseCalled);
                }
                else if(!inky.getActive())
                {
                    map[inky.getR()][inky.getC()].drawTile(g);
                    releaseGhost(inky, map, releaseCalled);
                }
                else if(!pinky.getActive())
                {
                    map[pinky.getR()][pinky.getC()].drawTile(g);
                    releaseGhost(pinky, map, releaseCalled);
                }
                else if(!clyde.getActive())
                {
                    map[clyde.getR()][clyde.getC()].drawTile(g);
                    releaseGhost(clyde, map, releaseCalled);
                }
            }

            pac.drawPac(g);
            g.update();



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

void rePositionGhosts(SDL_Plotter& g, Ghost& a, Ghost& b, Ghost& c, Ghost& d, Tile map[36][28])
{
    a.erase(g, map);
    b.erase(g, map);
    c.erase(g, map);
    d.erase(g, map);

    //blinky
    a.setActive(true);

    a.setR(14);
    a.setC(16);
    a.setCenter(map[14][16].getCenter());

    //pinky
    b.setR(16);
    b.setC(15);
    b.setCenter(map[16][15].getCenter());
    b.setActive(false);

    //inky
    c.setR(16);
    c.setC(14);
    c.setCenter(map[16][14].getCenter());
    c.setActive(false);

    //clyde
    d.setR(16);
    d.setC(16);
    d.setCenter(map[16][16].getCenter());
    d.setActive(false);

}
void releaseGhost(Ghost& a, Tile map[36][28], bool& r)
{
    r = true;
    a.setActive(true);

    a.setR(14);
    a.setC(16);
    a.setCenter(map[14][16].getCenter());
}


