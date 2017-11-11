#include "ghosts.h"

Ghost::Ghost(){


}
Ghost::Ghost(Color Col, Tile map[36][28]){

    color = Col;
    dir = LEFT;
    r = 14;
    c = 13;
    center = map[r][c].getCenter();
    radius = 12;


}
int Ghost::getDir(){
    return dir;
}
Point Ghost::getCenter()
{
    return center;
}
int Ghost::getR()
{
    return r;
}
int Ghost::getC()
{
    return c;
}
void Ghost::setCenter(Point p)
{
    center = p;
}
void Ghost::setDir(int d)
{
    dir = d;
}

void Ghost::move(Tile map[36][28], SDL_Plotter& g){
    double dist;
    for(int directions = 1; directions <= 4; directions++)
    {
        if(directions == UP && map[r - 1][c].isPath())
        {
            if(dir != DOWN)
            {
                dist = distance(Point(r - 1, c), Point(targetR, targetC));
                dir = UP;
            }
        }
        else if(directions == LEFT && map[r][c - 1].isPath())
        {
            if(distance(Point(r, c - 1), Point(targetR, targetC)) < dist && dir != RIGHT)
            {
                dist = distance(Point(r, c - 1), Point(targetR, targetC));
                dir = LEFT;
            }
        }
        else if(directions == DOWN && map[r + 1][c].isPath())
        {
            if(distance(Point(r + 1, c), Point(targetR, targetC)) < dist && dir != UP)
            {
                dist = distance(Point(r + 1, c), Point(targetR, targetC));
                dir = DOWN;
            }
        }
        else if(map[r][c + 1].isPath())
        {
            if(distance(Point(r, c + 1), Point(targetR, targetC)) < dist && dir != LEFT)
            {
                dist = distance(Point(r, c + 1), Point(targetR, targetC));
                dir = RIGHT;
            }
        }
    }

    if(dir == UP && map[r - 1][c].isPath())
    {
        setCenter(Point(c * 25 + 12, center.y-1));
        if(center.y == (r - 1) * 25 + 12)
        {
            r--;
        }
    }
    else if(dir == LEFT && map[r][c - 1].isPath())
    {
        setCenter(Point(center.x - 1, r * 25 + 12));
        if(center.x == (c - 1) * 25 + 12)
        {
            c--;
        }
    }
    else if(dir == DOWN && map[r + 1][c].isPath())
    {
        setCenter(Point(c * 25 + 12, center.y+1));
        if(center.y == (r + 1) * 25 + 12)
        {
            r++;
        }
    }
    else if(dir == RIGHT && map[r][c + 1].isPath())
    {
        setCenter(Point(center.x + 1, r * 25 + 12));
        if(center.x == (c + 1) * 25 + 12)
        {
            c++;
        }
    }
}

void Ghost::target(Pacman pac){
    targetC = pac.getC();
    targetR = pac.getR();
}

double Ghost::distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

void Ghost::draw(SDL_Plotter& g, Tile map[36][28])const{
    for(int x = -radius; x <= radius; x++)
    {
        for(int y = -radius; y <= radius; y++)
        {
            if(sqrt(x * x + y * y) <= radius)
            {
                g.plotPixel(map[r][c].getCenter().x + x, map[r][c].getCenter().y + y, color.R, color.G, color.B);

            }
        }
    }

}
void Ghost::erase(SDL_Plotter& g, Tile map[36][28])const{
    for(int x = -radius; x <= radius; x++)
    {
        for(int y = -radius; y <= radius; y++)
        {
            if(sqrt(x * x + y * y) <= radius)
            {
                g.plotPixel(map[r][c].getCenter().x + x, map[r][c].getCenter().y + y, 0, 0, 0);
            }
        }
    }

}







/*if(d == UP && dir != DOWN){
        if(map[r - 1][c].isPath())
        {
            r--;
            flag = true;
        }
        else
        {
            if(move(d + 3, map, g)){
                dir = LEFT;
            }
        }
    }
    else if(d == LEFT && dir != RIGHT){
        if(map[r][c - 1].isPath())
        {
            c--;
            flag = true;
        }
        else
        {
            if(move(d - 1, map, g)){
                dir = DOWN;
            }
        }
    }
    else if(d == DOWN&& dir != UP){
        if(map[r + 1][c].isPath())
        {
            r++;
            flag = true;
        }
        else
        {
            if(move(d - 1, map, g)){
                dir = RIGHT;
            }
        }
    }
    else if(d == RIGHT && dir != LEFT){
        if(map[r][c + 1].isPath())
        {
            c++;
            flag = true;
        }
        else
        {
            if(move(d - 1, map, g)){
                dir = UP;
            }

        }
    }*/
