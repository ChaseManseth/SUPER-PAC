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
#include "line.h"
#include "SDL_Plotter.h"
#include <cmath>

using namespace std;

class Circle {
    private:
        Point center;
        int radius;
        Color color;

    public:
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Circle(Point c, int r, Color col);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setCenter(const Point);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setRadius(const int);
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void setColor(const Color);

        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Point getCenter() const;
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        int getRadius() const;
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        Color getColor() const;
        /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
        void draw(SDL_Plotter& g)const;
};

#endif // CIRCLE_H_INCLUDED
