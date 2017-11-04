#include "pacman.h"
#include "tile.h"

Pacman::Pacman(int row, int col)
{
    r = row;
    c = col;
    lives = 3;
    speed = 1;
    radius = 12;
    points = 0;
    direction = RIGHT;
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
int Pacman::getPoints()
{
    return points;
}

void Pacman::setLives(int l)
{
    lives = l;
}
void Pacman::setWaka(int w)
{
    waka = w;
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

void Pacman::movePosition(int d, const Tile map[36][28])
{
    switch(getDirection())
    {
        case RIGHT:
                    setCenter(Point(center.x + 1, center.y));
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
}
