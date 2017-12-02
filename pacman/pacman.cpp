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

#include "pacman.h"
#include "tile.h"
#include <iostream>
#include <cstdlib>

Pacman::Pacman(int row, int col)
{
    state = NORMAL;
    r = row;
    c = col;
    lives = 3;
    radius = 12;
    score = 0;
    direction = RIGHT;
    nextDir = -1;
    waka = CLOSED_WAKA;
    center = Point(c * SIZE_TILE + MID_PIXEL_OF_TILE,
                   r * SIZE_TILE + MID_PIXEL_OF_TILE);
}

int Pacman::getLives() const
{
    return lives;
}
int Pacman::getWaka()  const
{
    return waka;
}
int Pacman::getDirection()  const
{
    return direction;
}
int Pacman::getState() const
{
    return state;
}
int Pacman::getScore() const
{
    return score;
}

int Pacman::getR() const
{
    return r;
}
int Pacman::getNextDir() const
{
    return nextDir;
}
int Pacman::getC() const
{
    return c;
}
Point Pacman::getCenter() const
{
    return center;
}

void Pacman::setLives(int l)
{
    lives = l;
}
void Pacman::setWaka(int w)
{
    waka = w;
}
void Pacman::setNextDir(int d)
{
    nextDir = d;
}
void Pacman::setState(int st)
{
    state = st;
}
void Pacman::setDirection(int d)
{
    direction = d;
}
void Pacman::setScore(int p)
{
    score = p;
}
void Pacman::setCenter(Point c)
{
    center = c;
}
void Pacman::setR(int row)
{
    r = row;
}
void Pacman::setC(int col)
{
    c = col;
}
bool Pacman::eat(Tile map[36][28], int& count)
{
    bool foo = false;
    if(map[r][c].getPel().active && !map[r][c].getPel().isEnergizer)
    {
        map[r][c].setPel();

        score += 10;

        foo = true;
    }
    else if(map[r][c].getPel().active && map[r][c].getPel().isEnergizer)
    {
        count = -1;

        map[r][c].setPel();

        score += 50;

        state = SUPERPAC;

        foo = true;
    }
    return foo;

}

void Pacman::movePosition(int d, Tile map[36][28], SDL_Plotter& g)
{
    bool moved = false;

    switch(nextDir)
    {
        //moves pacman right one tile (25 pixels)
        case RIGHT: if(map[r][c + 1].isPath()){
                        setCenter(Point(center.x + 1, r * SIZE_TILE + MID_PIXEL_OF_TILE));

                        if(center.x == (c + 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                        {
                            c++;
                        }

                        setDirection(nextDir);
                        nextDir = -1;
                        moved = true;

                    }
                    //moves pacman through the "tunnel"
                    else if(r==17&&c==27){
                        setCenter(Point(center.x + 1, center.y));
                        if(center.x >= c * SIZE_TILE + MID_PIXEL_OF_TILE)
                            setCenter(Point(MID_PIXEL_OF_TILE, center.y));
                            c=0;
                            setDirection(nextDir);
                            nextDir = -1;
                            moved = true;
                    }
                    break;
                    //moves pacman left one tile (25 pixels)
        case LEFT:  if(map[r][c - 1].isPath()){
                        setCenter(Point(center.x - 1, r * SIZE_TILE +
                                        MID_PIXEL_OF_TILE));

                        if(center.x == (c - 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                        {
                            c--;
                        }
                        setDirection(nextDir);
                        nextDir = -1;
                        moved = true;
                    }
                    //moves pacman through the "tunnel"
                    else if(r==17&&c==0){
                        setCenter(Point(center.x - 1, center.y));
                        if(center.x <= c * SIZE_TILE + MID_PIXEL_OF_TILE)
                        {
                            setCenter(Point(27 * SIZE_TILE + MID_PIXEL_OF_TILE,
                                            center.y));
                            c=27;

                            setDirection(nextDir);
                            nextDir = -1;
                            moved = true;
                        }
                    }
                    break;
                    //moves pacman up one tile (25 pixels)
        case UP:    if(map[r - 1][c].isPath()){
                       setCenter(Point(c * SIZE_TILE +
                                       MID_PIXEL_OF_TILE, center.y-1));

                       if(center.y == (r - 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                       {
                            r--;
                       }
                       setDirection(nextDir);
                       nextDir = -1;
                       moved = true;

                    }
                    break;
                    //moves pacman down one tile (25 pixels)
        case DOWN:  if(map[r + 1][c].isPath()){
                        setCenter(Point(c * SIZE_TILE + MID_PIXEL_OF_TILE,
                                        center.y+1));

                        if(center.y == (r + 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                        {
                            r++;
                        }
                        setDirection(nextDir);
                        nextDir = -1;
                        moved = true;
                    }
                    break;
    }

    if(!moved)
    {
        switch(getDirection())
        {
            //moves pacman right one tile (25 pixels)
            case RIGHT: if(map[r][c + 1].isPath()){
                            setCenter(Point(center.x + 1, r *
                                            SIZE_TILE + MID_PIXEL_OF_TILE));

                            if(center.x == (c + 1) * SIZE_TILE +MID_PIXEL_OF_TILE)
                            {
                                c++;
                            }

                        }
                        //moves pacman through the "tunnel"
                        else if(r==17&&c==27){
                            setCenter(Point(center.x + 1, center.y));
                            if(center.x >= c * SIZE_TILE + MID_PIXEL_OF_TILE)
                                setCenter(Point(MID_PIXEL_OF_TILE, center.y));
                                c=0;
                        }
                        break;
                        //moves pacman left one tile (25 pixels)
            case LEFT:  if(map[r][c - 1].isPath()){
                            setCenter(Point(center.x - 1,
                                            r * SIZE_TILE + MID_PIXEL_OF_TILE));

                            if(center.x == (c - 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                            {
                                c--;
                            }
                        }
                        //moves pacman through the "tunnel"
                        else if(r==17&&c==0){
                            setCenter(Point(center.x - 1, center.y));
                            if(center.x <= c * SIZE_TILE + MID_PIXEL_OF_TILE)
                            {
                                setCenter(Point(27 * SIZE_TILE +
                                                MID_PIXEL_OF_TILE, center.y));
                                c=27;
                            }
                        }
                        break;
                        //moves pacman up one tile (25 pixels)
            case UP:    if(map[r - 1][c].isPath()){
                           setCenter(Point(c * SIZE_TILE +
                                           MID_PIXEL_OF_TILE, center.y-1));

                           if(center.y == (r - 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                           {
                                r--;
                           }

                        }
                        break;
                        //moves pacman up down tile (25 pixels)
            case DOWN:  if(map[r + 1][c].isPath()){
                            setCenter(Point(c * SIZE_TILE +
                                            MID_PIXEL_OF_TILE, center.y+1));

                            if(center.y == (r + 1) * SIZE_TILE + MID_PIXEL_OF_TILE)
                            {
                                r++;
                            }
                        }
                        break;
        }
    }

    moved = true;
}

void Pacman::erasePac(SDL_Plotter& g)
{
    for(int x = -radius; x <= radius; x++)
    {
        for(int y = -radius; y <= radius; y++)
        {
            if(sqrt(x * x + y * y) <= radius)
            {
                g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
            }
        }
    }
}

void Pacman::drawPac(SDL_Plotter& g)
{
    for(int x = -radius; x <= radius; x++)
    {
        for(int y = -radius; y <= radius; y++)
        {
            if(sqrt(x * x + y * y) <= radius)
            {
                g.plotPixel(center.x + x, center.y + y, 255, 238, 0);
            }
        }
    }

    if(direction == UP && waka != CLOSED_WAKA)
    {
        if(waka == HALF2 || waka == HALF_WAKA)
        {
            for(double y = -radius; y <= 0; y++)
            {
                double leftLineX = (-1 / 4.0) * y;
                double rightLineX = (1 / 4.0) * y;
                for(double x = -3; x <= 3; x++)
                {
                    if(x <= leftLineX && x >= rightLineX)
                    {
                        g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
                    }
                }
            }
        }
        else
        {
            for(double y = -radius; y <= 0; y++)
            {
                double leftLineX = (-5 / 6.0) * y;
                double rightLineX = (5 / 6.0) * y;
                for(double x = -10; x <= 10; x++)
                {
                    if(x <= leftLineX && x >= rightLineX)
                    {
                        g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
                    }
                }
            }
        }
    }
    else if(direction == RIGHT && waka != CLOSED_WAKA)
    {
        if(waka == HALF2 || waka == HALF_WAKA)
        {
            for(int y = center.y - 3; y <= center.y + 3; y++)
            {
                Line l = Line(center, Point(center.x + radius, y));

                l.drawLine(g, Color(0, 0, 0));
            }
        }
        else
        {
            for(int y = center.y - 10; y <= center.y + 10; y++)
            {
                Line l = Line(center, Point(center.x + radius, y));

                l.drawLine(g, Color(0, 0, 0));
            }
        }
        g.plotPixel(center.x + 12, center.y, 0, 0, 0);
    }
    else if(direction == LEFT && waka != CLOSED_WAKA)
    {
        if(waka == HALF2 || waka == HALF_WAKA)
        {
            for(int y = center.y - 3; y <= center.y + 3; y++)
            {
                Line l = Line(center, Point(center.x - radius, y));

                l.drawLine(g, Color(0, 0, 0));
            }
        }
        else
        {
            for(int y = center.y - 10; y <= center.y + 10; y++)
            {
                Line l = Line(center, Point(center.x - radius, y));

                l.drawLine(g, Color(0, 0, 0));
            }
        }
        g.plotPixel(center.x - 12, center.y, 0, 0, 0);
    }
    else if(direction == DOWN && waka != CLOSED_WAKA)
    {
        if(waka == HALF2 || waka == HALF_WAKA)
        {
            for(double y = radius; y >= 0; y--)
            {
                double leftLineX = (-1 / 4.0) * y;
                double rightLineX = (1 / 4.0) * y;
                for(double x = -3; x <= 3; x++)
                {
                    if(x >= leftLineX && x <= rightLineX)
                    {
                        g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
                    }
                }
            }
        }
        else
        {
            for(double y = radius; y >= 0; y--)
            {
                double leftLineX = (-5 / 6.0) * y;
                double rightLineX = (5 / 6.0) * y;
                for(double x = -10; x <= 10; x++)
                {
                    if(x >= leftLineX && x <= rightLineX)
                    {
                        g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
                    }
                }
            }
        }
    }

}
