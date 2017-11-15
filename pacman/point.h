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

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    double x, y;

    Point()
    {
        x = y = 0;
    }

    Point(double a, double b)
    {
        x = a;
        y = b;
    }
};

#endif // POINT_H_INCLUDED
