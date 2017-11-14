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

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include <cmath>

using namespace std;

class Circle {
    private:
        Point center;
        int radius;
        Color color;

    public:
        Circle(Point c, int r, Color col);
        void setCenter(const Point);
        void setRadius(const int);
        void setColor(const Color);

        Point getCenter() const;
        int getRadius() const;
        Color getColor() const;

        void draw(SDL_Plotter& g)const;
};

#endif // CIRCLE_H_INCLUDED
