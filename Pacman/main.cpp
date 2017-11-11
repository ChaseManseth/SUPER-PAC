#include <iostream>
#include <fstream>
#include "pacman.h"
#include "tile.h"
#include "ghosts.h"


using namespace std;

int main(int argc, char** argv)
{
    ifstream inData;
    bool readValue;
    SDL_Plotter g(900,700);
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
    pac.drawPac(g);


    char key;

    int speed = 1;
    const int MAX_SPEED = 10;

    while(!g.getQuit())
    {
        for(int i = 0; i < 50; i++)
        {
            for(int r = 0; r < 36; r++)
            {
                for(int c = 0; c < 28; c++)
                {
                    map[r][c].drawTile(g);
                }
            }
            Blinky.move(Blinky.getDir(), map, g);
            Blinky.erase(g, map);
            Blinky.draw(g, map);
            pac.eat(map);
            pac.drawPac(g);
            g.update();






            //draw(cout, x1, y1, x2, y2);

            if(g.kbhit())
            {
                key = g.getKey();

                switch(key)
                {
                    case RIGHT_ARROW: if(map[pac.getR()][pac.getC() + 1].isPath())
                                      {
                                            pac.setDirection(RIGHT);
                                      }

                                      Blinky.target(pac);
                                      break;
                    case LEFT_ARROW:  if(map[pac.getR()][pac.getC() - 1].isPath())
                                      {
                                            pac.setDirection(LEFT);
                                      }

                                      Blinky.target(pac);
                                      break;
                    case UP_ARROW:    if(map[pac.getR() - 1][pac.getC()].isPath())
                                      {
                                            pac.setDirection(UP);
                                      }

                                      Blinky.target(pac);
                                      break;
                    case DOWN_ARROW:  if(map[pac.getR() + 1][pac.getC()].isPath())
                                      {
                                            pac.setDirection(DOWN);
                                      }

                                      Blinky.target(pac);
                                      break;
                }

            }
            pac.movePosition(pac.getDirection(), map, g);

            g.Sleep(100);
        }

}






    return 0;
}
