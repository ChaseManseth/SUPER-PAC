#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include <cmath>


const int UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4;
const int WAKA1 = 5, WAKA2 = 6, WAKA3 = 7;

class Pacman
{
    private:
        Point center;
        int lives;
        int radius;
        int state;
        int speed;
        int points;
        int direction;

    public:
        Pacman();

        int getLives();
        int getState();
        int getSpeed();
        int getDirection();
        int getPoints();
        Point getCenter();

        void setLives(int l);
        void setState(int st);
        void setCenter(Point c);
        void setSpeed(int s);
        void setDirection(int d);
        void setPoints(int p);

        void movePosition(int d);
        void erasePac(SDL_Plotter& g);
        void drawPac(SDL_Plotter& g, int a);
        void drawWaka(SDL_Plotter& g);


};

#endif // PACMAN_H_INCLUDED
