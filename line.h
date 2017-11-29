/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 12/4/2017
* Date Created: 11/1/2017
* Date Last Modified: 11/20/2017
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

        /*
         * Description: Constructor, sets p1 and p2 to p11 and p22 respectively
         * Return: none
         * Precondition: p11 and p22 exist
         * Postcondition: Line is set to the points p11 and p22
         */
        Line(Point p11, Point p22);
        /*
         * Description: returns p1
         * Return: Point
         * Precondition: p1 is initialized
         * Postcondition: p1 is returned.
         */
        Point getP1();
        /*
         * Description: returns p2
         * Return: Point
         * Precondition: p2 is initialized
         * Postcondition: p2 is returned.
         */
        Point getP2();
        /*
         * Description: sets p1 to p
         * Return: void
         * Precondition: p1 is initialized
         * Postcondition: p1 is assigned p
         */
        void setP1(Point p);
        /*
         * Description: sets p2 to p
         * Return: void
         * Precondition: p2 is initialized
         * Postcondition: p2 is assigned p
         */
        void setP2(Point p);
        /*
         * Description: returns true if a slope exists
         * Return: boolean
         * Precondition: p1 and p2 exist
         * Postcondition: slope returns true or false, m is assigned
         *                the value of the slope if slope exists
         */
        bool slope(double& m) const;
        /*
         * Description: returns true if a y-intercept exists
         * Return: boolean
         * Precondition: p1 and p2 exist
         * Postcondition: yIntercept returns true or false, b is
         *                assigned the value of the y-intercept if it exists
         */
        bool yIntercept(double& b) const;
        /*
         * Description: draws to the SDL_Plotter
         * Return: void
         * Precondition: SDL_Plotter g is initialized, c exists
         * Postcondition: a line is drawn to the plotter
         */
        void drawLine(SDL_Plotter& g, Color c);

};

#endif // LINE_H_INCLUDED
