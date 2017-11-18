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

#ifndef PELLET_H_INCLUDED
#define PELLET_H_INCLUDED

#include "point.h"
#include "tile.h"
#include "SDL_Plotter.h"

struct Pellet
{
    int pel[3][3];
    int row, col;
    bool active;
    Pellet(){
        row = col = 0;
        active = true;
    }
    Pellet(int r, int c){
        row = r;
        col = c;
        active = true;
    }
    void draw(Point p, SDL_Plotter& g){
        if(active){
            for(int i = 0; i < 3; i++){
                for(int k = 0; k < 3; k++){
                    g.plotPixel(p.x+i,p.y+k, 255, 255, 255);
                }
            }
        }
        else{
            for(int i = 0; i < 3; i++){
                for(int k = 0; k < 3; k++){
                    g.plotPixel(p.x+i,p.y+k, 0, 0, 0);
                }
            }
        }
    }
    void setActive(bool b){
        active = b;
    }





};

#endif // PELLET_H_INCLUDED
