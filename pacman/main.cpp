#include <iostream>
#include "pacman.h"


using namespace std;

int main(int argc, char** argv)
{
    SDL_Plotter g(800,800);
    Pacman pac;

    char key;

    int speed = 1;
    const int MAX_SPEED = 10;

    while(!g.getQuit())
    {
        pac.drawPac(g, 1 /*implement wakastate*/);
        pac.drawWaka(g);
        g.update();
        g.Sleep(10);

        pac.erasePac(g);
        pac.movePosition(pac.getDirection());


        //draw(cout, x1, y1, x2, y2);

        if(g.kbhit())
        {
            key = g.getKey();

            switch(key)
            {
                case RIGHT_ARROW: pac.setDirection(RIGHT);
                                  break;
                case LEFT_ARROW:  pac.setDirection(LEFT);
                                  break;
                case UP_ARROW:    pac.setDirection(UP);
                                  break;
                case DOWN_ARROW:  pac.setDirection(DOWN);
                                  break;
            }
        }
    }






    return 0;
}
