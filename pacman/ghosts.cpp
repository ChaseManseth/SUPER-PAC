/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 11/29/2017
* Date Created: 11/1/2017
* Date Last Modified: 11/12/2017
*/

#include "ghosts.h"

Ghost::Ghost(){


}
Ghost::Ghost(Color Col, Tile map[36][28]){

    color = Col;
    dir = LEFT;
    r = 16;
    c = 13;
    center = map[r][c].getCenter();
    radius = 12;
    active = false;

}
int Ghost::getDir(){
    return dir;
}
bool Ghost::getActive()
{
    return active;
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
void Ghost::setR(int row)
{
    r = row;
}
void Ghost::setActive(bool b)
{
    active = b;
}
void Ghost::setC(int col)
{
    c = col;
}

bool Ghost::isCollide(Tile map[36][28], Pacman& p, SDL_Plotter& g)
{
    if(r == p.getR() && c == p.getC())
    {
        p.setR(26);
        p.setC(13);

        p.setCenter(map[26][13].getCenter());

        return true;
    }

    if((getCenter().x + 11 >= p.getCenter().x - 11 && getCenter().x - 11 <= p.getCenter().x - 11 && r == p.getR()) || //right
       (getCenter().x - 11 <= p.getCenter().x + 11 && getCenter().x + 11 >= p.getCenter().x + 11 && r == p.getR()) || //left
       (getCenter().y - 11 <= p.getCenter().y + 11 && getCenter().y + 11 >= p.getCenter().y - 11 && c == p.getC()) || //up
       (getCenter().y + 11 >= p.getCenter().y - 11 && getCenter().y - 11 <= p.getCenter().y + 11 && c == p.getC()))   //down
    {
        p.setR(26);
        p.setC(13);

        p.setCenter(map[26][13].getCenter());

        return true;
    }

    return false;
}


bool Ghost::moveUp(Tile map[36][28], SDL_Plotter& g, double& uDist){
    bool flag = false;
    if(map[r - 1][c].isPath()&&dir != DOWN){

        uDist = sqrt(pow(targetC - c,2) + pow(targetR - (r-1),2));
        flag = true;

    }
    return flag;
}

bool Ghost::moveLeft(Tile map[36][28], SDL_Plotter& g, double& lDist){
    bool flag = false;
    if(map[r][c-1].isPath()&&dir != RIGHT){
        lDist = sqrt(pow(targetC - (c-1),2) + pow(targetR - r,2));
        flag = true;
    }
    return flag;
}

bool Ghost::moveDown(Tile map[36][28], SDL_Plotter& g, double& dDist){
    bool flag = false;
    if(map[r + 1][c].isPath()&&dir != UP){
        dDist = sqrt(pow(targetC - c,2) + pow(targetR - (r+1),2));
        flag = true;
    }
    return flag;
}

bool Ghost::moveRight(Tile map[36][28], SDL_Plotter& g, double& rDist){
    bool flag = false;
    if(map[r][c+1].isPath()&&dir != LEFT){
        rDist = sqrt(pow(targetC - (c+1),2) + pow(targetR - r,2));
        flag = true;
    }
    return flag;
}

void Ghost::move(Tile map[36][28], SDL_Plotter& g){
    double u, l, d, ri;
    u = l = d = ri = 1000000;
    bool flag = false;
    queue<int> BlinkyDir;
    BlinkyDir.push(UP);
    BlinkyDir.push(LEFT);
    BlinkyDir.push(DOWN);
    BlinkyDir.push(RIGHT);
    while(!flag){
        if(BlinkyDir.front() == UP){
            if(moveUp(map,g, u)){
                flag = true;
                BlinkyDir.pop();
            }
            else{
                BlinkyDir.pop();
                BlinkyDir.push(UP);
            }
        }
        if(BlinkyDir.front() == LEFT){
            if(moveLeft(map,g, l)){
                flag = true;
                BlinkyDir.pop();
            }
            else{
                BlinkyDir.pop();
                BlinkyDir.push(LEFT);
            }
        }
        if(BlinkyDir.front() == DOWN){
            if(moveDown(map,g, d)){
                flag = true;
                BlinkyDir.pop();
            }
            else{
                BlinkyDir.pop();
                BlinkyDir.push(DOWN);
            }
        }
        if(BlinkyDir.front() == RIGHT){
            if(moveRight(map,g, ri)){
                flag = true;
                BlinkyDir.pop();
            }
            else{
                BlinkyDir.pop();
                BlinkyDir.push(RIGHT);
            }
        }
    }
    if(u < d){
        if(u < ri){
            if(u < l){
                dir = UP;
            }
            else{
                dir = LEFT;
            }
        }
        else{
            if(ri < l){
                dir = RIGHT;
            }
            else{
                dir = LEFT;
            }
        }
    }
    else if(d < ri){
        if(d < l){
            dir = DOWN;
        }
        else{
            dir = LEFT;
        }
    }
    else if(ri < l){
        dir = RIGHT;
    }
    else{
        dir = LEFT;
    }
    if(dir == LEFT && active){
        setCenter(Point(center.x - 1, r * 25 + 12));
        if(center.x == (c - 1) * 25 + 12)
        {
            c--;
        }
    }
    if(dir == RIGHT && active){
        setCenter(Point(center.x + 1, r * 25 + 12));
        if(center.x == (c + 1) * 25 + 12)
        {
            c++;
        }
    }
    if(dir == DOWN && active){
        setCenter(Point(c * 25 + 12, center.y+1));
        if(center.y == (r + 1) * 25 + 12)
        {
            r++;
        }
    }
    if(dir == UP && active){
        setCenter(Point(c * 25 + 12, center.y-1));
        if(center.y == (r - 1) * 25 + 12)
        {
            r--;
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
                g.plotPixel(center.x + x, center.y + y, color.R, color.G, color.B);

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
                g.plotPixel(center.x + x, center.y + y, 0, 0, 0);
            }
        }
    }

}

/*void Ghost::move(Tile map[36][28], SDL_Plotter& g){
    double dist = 9999;
    int d = dir;
    for(int directions = 1; directions <= 4; directions++)
    {
        if(directions == UP && map[r - 1][c].isPath())
        {
            if(dir != DOWN)
            {
                dist = distance(Point(c, r - 1), Point(targetC, targetR));
                d = UP;
            }
        }
        else if(directions == LEFT && map[r][c - 1].isPath())
        {
            if(distance(Point(c - 1, r), Point(targetC, targetR)) < dist && dir != RIGHT)
            {
                dist = distance(Point(c - 1, r), Point(targetC, targetR));
                d = LEFT;
            }
        }
        else if(directions == DOWN && map[r + 1][c].isPath())
        {
            if(distance(Point(c, r + 1), Point(targetC, targetR)) < dist && dir != UP)
            {
                dist = distance(Point(c, r + 1), Point(targetC, targetR));
                d = DOWN;
            }
        }
        else if(map[r][c + 1].isPath())
        {
            if(distance(Point(c + 1, r), Point(targetC, targetR)) < dist && dir != LEFT)
            {
                dist = distance(Point(c + 1, r), Point(targetC, targetR));
                d = RIGHT;
            }
        }
    }
    dir = d;

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
}*/
