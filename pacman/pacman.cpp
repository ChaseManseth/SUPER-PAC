#include "pacman.h"

Pacman::Pacman()
{
    lives = 3;
    speed = 1;
    radius = 20;
    points = 0;
    direction = RIGHT;
    center = Point(200,200);
}

int Pacman::getLives()
{
    return lives;
}
int Pacman::getSpeed()
{
    return speed;
}
int Pacman::getDirection()
{
    return direction;
}
int Pacman::getState()
{
    return state;
}
int Pacman::getPoints()
{
    return points;
}
Point Pacman::getCenter()
{
    return center;
}

void Pacman::setLives(int l)
{
    lives = l;
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
void Pacman::setPoints(int p)
{
    points = p;
}
void Pacman::setCenter(Point c)
{
    center = c;
}

void Pacman::movePosition(int d)
{
    switch(getDirection())
    {
        case RIGHT: setCenter(Point(center.x + 1, center.y));
                    break;
        case LEFT:  setCenter(Point(center.x - 1, center.y));
                    break;
        case UP:    setCenter(Point(center.x, center.y - 1));
                    break;
        case DOWN:  setCenter(Point(center.x, center.y + 1));
                    break;
    }
}
void Pacman::erasePac(SDL_Plotter& g)
{
    for(int x = -radius; x <= radius; x++)
    {
        for(int y = -radius; y <= radius; y++)
        {
            if(sqrt(x * x + y * y) <= radius)
            {
                g.plotPixel(center.x + x, center.y + y, 255, 255, 255);
            }
        }
    }
}
void Pacman::drawPac(SDL_Plotter& g, int wakaState)
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
}
void Pacman::drawWaka(SDL_Plotter& g)
{
    for(int x = 0; x <= radius; x++)
    {
        for(int y = 0; y <= radius; y++)
        {
                g.plotPixel(center.x + x, center.y + y, 255, 255, 255);
        }
    }
}
