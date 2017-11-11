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
