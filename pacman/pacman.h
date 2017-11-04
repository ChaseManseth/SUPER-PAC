#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include "tile.h"
#include <cmath>


const int UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4;
const int CLOSED_WAKA = 5, HALF_WAKA = 6, FULL_WAKA = 7;

class Pacman
{
    private:
        int lives;
        int r, c;
        Point center;
        int radius;
        int state;
        int speed;
        int points;
        int waka;
        int direction;

    public:
        Pacman(int row, int col);

        int getLives();
        int getState();
        int getWaka();
        int getSpeed();
        int getDirection();
        int getPoints();

        void setLives(int l);
        void setState(int st);
        void setCenter(Point c);
        void setSpeed(int s);
        void setWaka(int w);
        void setDirection(int d);
        void setPoints(int p);

        void movePosition(int d, const Tile map[36][28]);
        void erasePac(SDL_Plotter& g);
        void drawPac(SDL_Plotter& g);

};

#endif // PACMAN_H_INCLUDED
