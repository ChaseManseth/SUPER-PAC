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

#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "SDL_Plotter.h"
#include "point.h"
#include "color.h"

class Line
{
    private:
        Point p1, p2;

    public:
        Line(Point p11, Point p22);

        Point getP1();
        Point getP2();

        void setP1(Point p);
        void setP2(Point p);

        bool slope(double& m) const;
        bool yIntercept(double& b) const;

        void drawLine(SDL_Plotter& g, Color c);


};

#endif // LINE_H_INCLUDED
