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

bool Ghost::move(int d, Tile map[36][28], SDL_Plotter& g){
    bool flag = false;
    if(d == UP && dir != DOWN){
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
    }
    return flag;
}

void Ghost::target(Pacman pac){
    targetC = pac.getC();
    targetR = pac.getR();
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
