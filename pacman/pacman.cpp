#include "pacman.h"
#include "tile.h"
#include <iostream>
#include <cstdlib>

Pacman::Pacman(int row, int col)
{
    r = row;
    c = col;
    lives = 3;
    speed = 1;
    radius = 12;
    score = 0;
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
int Pacman::getScore()
{
    return score;
}

int Pacman::getR(){
    return r;
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
void Pacman::eat(Tile map[36][28]){
    if(map[r][c].getPel().active){
        map[r][c].setPel();

        score+=500;

        cout << score;
    }

}

void Pacman::movePosition(int d, Tile map[36][28], SDL_Plotter& g)
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
                        if(center.x >= (c + 1) * 25 + 12)
                        {
                            setCenter(Point(12, center.y-1));
                            c=0;
                            map[r][c].drawTile(g);
                            map[r + 1][c].drawTile(g);
                        }
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
                        if(center.x <= (c - 1) * 25 + 12)
                        {
                            setCenter(Point(27 * 25 + 12, center.y-1));
                            c=27;
                            map[r][c].drawTile(g);
                            map[r - 1][c].drawTile(g);
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
