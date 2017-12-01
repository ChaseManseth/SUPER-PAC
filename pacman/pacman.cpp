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
    speed = 1;
    radius = 12;
    score = 0;
    direction = RIGHT;
    nextDir = -1;
    waka = CLOSED_WAKA;
    center = Point(13 * SIZE_TILE + 12,26 * SIZE_TILE + 12);
}

int Pacman::getLives()
{
    return lives;
}
int Pacman::getSpeed()
{
    return speed;
}
int Pacman::getWaka()
{
    return waka;
}
int Pacman::getDirection()
{
    return direction;
}
int Pacman::getState()
{
    return state;
}
int Pacman::getScore()
{
    return score;
}

int Pacman::getR(){
    return r;
}
int Pacman::getNextDir()
{
    return nextDir;
}
int Pacman::getC(){
    return c;
}
Point Pacman::getCenter()
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
void Pacman::setSpeed(int s)
{
    speed = s;
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
    if(map[r][c].getPel().active && !map[r][c].getPel().isEnergizer)
    {
        map[r][c].setPel();

        score += 10;

        cout << " " << score;

        return true;
    }
    else if(map[r][c].getPel().active && map[r][c].getPel().isEnergizer)
    {
        count = -1;
        map[r][c].setPel();

        score += 50;

        cout << " " << score;

        state = SUPERPAC;

        return true;
    }
    return false;

}

void Pacman::movePosition(int d, Tile map[36][28], SDL_Plotter& g)
{

    bool moved = false;

    switch(nextDir)
    {
        case RIGHT: if(map[r][c + 1].isPath()){
                        setCenter(Point(center.x + 1, r * 25 + 12));

                        if(center.x == (c + 1) * 25 + 12)
                        {
                            c++;
                        }

                        setDirection(nextDir);
                        nextDir = -1;
                        moved = true;

                    }
                    else if(r==17&&c==27){
                        setCenter(Point(center.x + 1, center.y));
                        if(center.x >= c * 25 + 12)
                            setCenter(Point(12, center.y));
                            c=0;
                            setDirection(nextDir);
                            nextDir = -1;
                            moved = true;
                    }
                    break;
        case LEFT:  if(map[r][c - 1].isPath()){
                        setCenter(Point(center.x - 1, r * 25 + 12));
                        if(center.x == (c - 1) * 25 + 12)
                        {
                            c--;
                        }
                        setDirection(nextDir);
                        nextDir = -1;
                        moved = true;
                    }
                    else if(r==17&&c==0){
                        setCenter(Point(center.x - 1, center.y));
                        if(center.x <= c * 25 + 12)
                        {
                            setCenter(Point(27 * 25 + 12, center.y));
                            c=27;

                            setDirection(nextDir);
                            nextDir = -1;
                            moved = true;
                        }
                    }
                    break;
        case UP:    if(map[r - 1][c].isPath()){
                       setCenter(Point(c * 25 + 12, center.y-1));
                       if(center.y == (r - 1) * 25 + 12)
                       {
                            r--;
                       }
                       setDirection(nextDir);
                       nextDir = -1;
                       moved = true;

                    }
                    break;
        case DOWN:  if(map[r + 1][c].isPath()){
                        setCenter(Point(c * 25 + 12, center.y+1));
                        if(center.y == (r + 1) * 25 + 12)
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
            case RIGHT: if(map[r][c + 1].isPath()){
                            setCenter(Point(center.x + 1, r * 25 + 12));

                            if(center.x == (c + 1) * 25 + 12)
                            {
                                c++;
                            }

                        }
                        else if(r==17&&c==27){
                            setCenter(Point(center.x + 1, center.y));
                            if(center.x >= c * 25 + 12)
                                setCenter(Point(12, center.y));
                                c=0;
                        }
                        break;
            case LEFT:  if(map[r][c - 1].isPath()){
                            setCenter(Point(center.x - 1, r * 25 + 12));
                            if(center.x == (c - 1) * 25 + 12)
                            {
                                c--;
                            }
                        }
                        else if(r==17&&c==0){
                            setCenter(Point(center.x - 1, center.y));
                            if(center.x <= c * 25 + 12)
                            {
                                setCenter(Point(27 * 25 + 12, center.y));
                                c=27;
                            }
                        }
                        break;
            case UP:    if(map[r - 1][c].isPath()){
                           setCenter(Point(c * 25 + 12, center.y-1));
                           if(center.y == (r - 1) * 25 + 12)
                           {
                                r--;
                           }

                        }
                        break;
            case DOWN:  if(map[r + 1][c].isPath()){
                            setCenter(Point(c * 25 + 12, center.y+1));
                            if(center.y == (r + 1) * 25 + 12)
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
