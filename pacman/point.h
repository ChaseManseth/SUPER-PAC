/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 12/4/2017
* Date Created: 11/1/2017
* Date Last Modified: 11/11/2017
*/

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    double x, y;
    /*
     *  Description: Blank constructor for a Point object
     *  Return: none
     *  Precondition: none
     *  Postcondition: x and y are assigned 0
     */
    Point()
    {
        x = y = 0;
    }
    /*
     *  Description: Constructor for a Point object
     *  Return: none
     *  Precondition: a and b exist
     *  Postcondition: x and y are assigned a and b respectively
     */
    Point(double a, double b)
    {
        x = a;
        y = b;
    }
};

#endif // POINT_H_INCLUDED
