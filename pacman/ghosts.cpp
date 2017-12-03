/*
* Author: Zachary Steudel, Chase Manseth, Meghan Bibb,
* Will Rhoden, Bailey Stone
* Assignment Title:  Pacman Group Project
* Assignment Description: User can play a faithfully recreated
* version of pacman.
* Due Date: 12/4/2017
* Date Created: 11/1/2017
* Date Last Modified: 12/3/2017
*/

#include "ghosts.h"

Ghost::Ghost(){
    color = Color(255,0,0);
    dir = LEFT;
    r = 16;
    c = 13;
    radius = 12;
    active = false;

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
void Ghost::setColor(Color c)
{
    color = c;
}
void Ghost::setC(int col)
{
    c = col;
}

bool Ghost::isCollide(Tile map[36][28], Pacman& p, SDL_Plotter& g)
{
    bool flag = false;
    if((getCenter().x + 8 >= p.getCenter().x - 8 && getCenter().x - 8 <= p.getCenter().x - 8 && r == p.getR()) || //right
       (getCenter().x - 8 <= p.getCenter().x + 8 && getCenter().x + 8 >= p.getCenter().x + 8 && r == p.getR()) || //left
       (getCenter().y - 8 <= p.getCenter().y + 8 && getCenter().y + 8 >= p.getCenter().y - 8 && c == p.getC()) || //up
       (getCenter().y + 8 >= p.getCenter().y - 8 && getCenter().y - 8 <= p.getCenter().y + 8 && c == p.getC()))   //down
    {
        flag = true;
    }

    return flag;
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
    if(map[r][c-1].isPath()&&dir != RIGHT && (r != 17 || c - 1 != 5)){
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
    if(map[r][c+1].isPath()&&dir != LEFT && (r != 17 || c + 1 != 22)){
        rDist = sqrt(pow(targetC - (c+1),2) + pow(targetR - r,2));
        flag = true;
    }
    return flag;
}

void Ghost::move(Tile map[36][28], SDL_Plotter& g){
    double u, l, d, ri;
    u = l = d = ri = 1000000;
    bool flag = false;
    queue<int> ghostQueue;
    ghostQueue.push(UP);
    ghostQueue.push(LEFT);
    ghostQueue.push(DOWN);
    ghostQueue.push(RIGHT);
    while(!flag){
        if(ghostQueue.front() == UP){
            if(moveUp(map,g, u)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(UP);
            }
        }
        if(ghostQueue.front() == LEFT){
            if(moveLeft(map,g, l)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(LEFT);
            }
        }
        if(ghostQueue.front() == DOWN){
            if(moveDown(map,g, d)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(DOWN);
            }
        }
        if(ghostQueue.front() == RIGHT){
            if(moveRight(map,g, ri)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(RIGHT);
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

void Ghost::moveFrightened(Tile map[36][28], SDL_Plotter& g, Pacman pac)
{
    double u, l, d, ri;
    u = l = d = ri = -1000000;
    bool flag = false;
    queue<int> ghostQueue;
    ghostQueue.push(UP);
    ghostQueue.push(LEFT);
    ghostQueue.push(DOWN);
    ghostQueue.push(RIGHT);
    while(!flag){
        if(ghostQueue.front() == UP){
            if(moveUp(map,g, u)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(UP);
            }
        }
        if(ghostQueue.front() == LEFT){
            if(moveLeft(map,g, l)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(LEFT);
            }
        }
        if(ghostQueue.front() == DOWN){
            if(moveDown(map,g, d)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(DOWN);
            }
        }
        if(ghostQueue.front() == RIGHT){
            if(moveRight(map,g, ri)){
                flag = true;
                ghostQueue.pop();
            }
            else{
                ghostQueue.pop();
                ghostQueue.push(RIGHT);
            }
        }
    }
    if(u > d){
        if(u > ri){
            if(u > l){
                dir = UP;
            }
            else{
                dir = LEFT;
            }
        }
        else{
            if(ri > l){
                dir = RIGHT;
            }
            else{
                dir = LEFT;
            }
        }
    }
    else if(d > ri){
        if(d > l){
            dir = DOWN;
        }
        else{
            dir = LEFT;
        }
    }
    else if(ri > l){
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

void Ghost::draw(SDL_Plotter& g, int ghosts[4][25][25], int n)const{
    int xVal = center.x-12;
    int yVal = center.y-12;
    for(int row = 0; row < 25; row++)
    {
        for(int col = 0; col < 25; col++)
        {
            if(ghosts[n][row][col] == 1){
                g.plotPixel(xVal+col, yVal+row, color.R, color.G, color.B);
            }
            else if(ghosts[n][row][col] == 2){
                g.plotPixel(xVal+col, yVal+row,255,255,255);
            }
        }
    }
}
void Ghost::erase(SDL_Plotter& g, Tile map[36][28])const{
    int xVal = center.x-12;
    int yVal = center.y-12;
    for(int row = 0; row < 25; row++)
    {
        for(int col = 0; col < 25; col++)
        {
            g.plotPixel(xVal+col, yVal+row,0,0,0);
        }
    }
}
