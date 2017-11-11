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
        int score;
        int waka;
        int direction;

    public:
        Pacman(int row, int col);

        int getLives();
        int getState();
        int getWaka();
        int getSpeed();
        int getDirection();
        int getScore();
        Point getCenter();
        int getR();
        int getC();

        void setLives(int l);
        void setState(int st);
        void setCenter(Point c);
        void setSpeed(int s);
        void setWaka(int w);
        void setDirection(int d);
        void setScore(int p);

        void eat(Tile map[36][28]);
        void movePosition(int d, Tile map[36][28], SDL_Plotter& g);
        void erasePac(SDL_Plotter& g);
        void drawPac(SDL_Plotter& g);

};

#endif // PACMAN_H_INCLUDED
