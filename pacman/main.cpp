#include <iostream>
#include <fstream>
#include "pacman.h"
#include "tile.h"


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
            map[r][c].getPel().setActive();
        }
    }
    for(int r = 0; r < 36; r++)
    {
        for(int c = 0; c < 28; c++)
        {
            map[r][c].drawTile(g);
        }
    }

    Pacman pac(26, 13);
    pac.drawPac(g);

    char key;

    int speed = 1;
    const int MAX_SPEED = 10;

    while(!g.getQuit())
    {
        for(int r = 0; r < 36; r++)
        {
            for(int c = 0; c < 28; c++)
            {
                map[r][c].drawTile(g);
            }
        }
        pac.drawPac(g);
        pac.eat(map);
        g.update();






        //draw(cout, x1, y1, x2, y2);

        if(g.kbhit())
        {
            key = g.getKey();

            switch(key)
            {
                case RIGHT_ARROW: pac.setDirection(RIGHT);
                                  pac.movePosition(pac.getDirection(), map, g);
                                  break;
                case LEFT_ARROW:  pac.setDirection(LEFT);
                                  pac.movePosition(pac.getDirection(), map, g);
                                  break;
                case UP_ARROW:    pac.setDirection(UP);
                                  pac.movePosition(pac.getDirection(), map, g);
                                  break;
                case DOWN_ARROW:  pac.setDirection(DOWN);
                                  pac.movePosition(pac.getDirection(), map, g);
                                  break;
            }
        }
    }






    return 0;
}
