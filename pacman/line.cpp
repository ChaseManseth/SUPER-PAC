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

#include "line.h"

Line::Line(Point p11, Point p22)
{
    p1 = p11;
    p2 = p22;
}

Point Line::getP1()
{
    return p1;
}
Point Line::getP2()
{
    return p2;
}

void Line::setP1(Point p)
{
    p1 = p;
}
void Line::setP2(Point p)
{
    p2 = p;
}

bool Line::slope(double& m) const
{
    if(p1.x == p2.x)
    {
        return false;
    }
    else
    {
        m = (p2.y - p1.y) / (p2.x - p1.x);
        return true;
    }
}

bool Line::yIntercept(double& b) const
{
    double m;
    slope(m);
    if((p1.x > 0 && p2.x < 0) || (p1.x < 0 && p2.x > 0) || (m != 0))
    {
        if(slope(m))
        {
            b = p1.y - m * p1.x;
        }
        return true;
    }
    else if(p1.x == p2.x)
    {
        return false;
    }
    else if(p1.x == 0 && p2.x != 0)
    {
        b = p1.y;
        return true;
    }
    else if(p1.x != 0 && p2.x == 0)
    {
        b = p2.y;
        return true;
    }
    else
    {
        return false;
    }
}

void Line::drawLine(SDL_Plotter& g, Color c)
{
    double m;
    double b;
    slope(m);
    yIntercept(b);

    if(p1.x != p2.x)
    {
        if(p1.x > p2.x)
        {
            for(int x = p2.x; x <= p1.x; x++)
            {
                int y = m * x + b;

                g.plotPixel(x, y, c.R, c.G, c.B);
            }
        }
        else
        {
            for(int x = p1.x; x <= p2.x; x++)
            {
                int y = m * x + b;

                g.plotPixel(x, y, c.R, c.G, c.B);

            }
        }
    }
    else
    {
        if(p1.y > p2.y)
        {
            for(int y = p2.y; y <= p1.y; y++)
            {
                g.plotPixel(p1.x, y, c.R, c.G, c.B);
            }
        }
        else
        {
            for(int y = p1.y; y <= p2.y; y++)
            {
                g.plotPixel(p1.x, y, c.R, c.G, c.B);
            }
        }
    }
}
