#ifndef GHOSTS_H_INCLUDED
#define GHOSTS_H_INCLUDED

#include "pacman.h"
#include "SDL_Plotter.h"
#include "tile.h"
#include "color.h"
#include "point.h"

#include <cmath>

using namespace std;

class Ghost{
    private:
        bool active;
        int dir;
        bool scatter;
        Color color;
        int r, c;
        int radius;
        Point center;
        int targetR;
        int targetC;
    public:
        Ghost();
        Ghost(Color Col, Tile map[36][28]);

        int getDir();
        Point getCenter();
        int getR();
        int getC();
        void setCenter(Point p);
        void setDir(int d);

        void move(Tile map[36][28], SDL_Plotter& g);
        double distance(Point p1, Point p2);
        void target(Pacman pac);
        void draw(SDL_Plotter& g, Tile map[36][28])const;
        void erase(SDL_Plotter& g, Tile map[36][28])const;
};

#endif // GHOSTS_H_INCLUDED
