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
#include <cmath>
#include "SDL_Plotter.h"

struct Pellet
{
    int pel[3][3];
    int row, col;
    bool active, isEnergizer;
    /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
    Pellet(){
        row = col = 0;
        active = false;
    }
    /*
         *  Description:
         *  Return:
         *  Precondition:
         *  Postcondition:
         */
    Pellet(int r, int c, bool energy){
        row = r;
        col = c;
        isEnergizer = energy;
        active = false;
    }
    /*
     *  Description:
     *  Return:
     *  Precondition:
     *  Postcondition:
     */
    void draw(Point p, SDL_Plotter& g){
        if(active && !isEnergizer){
            for(int i = 0; i < 3; i++){
                for(int k = 0; k < 3; k++){
                    g.plotPixel(p.x+i,p.y+k, 255, 255, 255);
                }
            }
        }
        else if(active && isEnergizer)
        {
            for(int x = -8; x <= 8; x++)
            {
                for(int y = -8; y <= 8; y++)
                {
                    if(sqrt(x * x + y * y) <= 8)
                    {
                        g.plotPixel(p.x + x, p.y + y, 255, 255, 255);
                    }
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
    /*
     *  Description:
     *  Return:
     *  Precondition:
     *  Postcondition:
     */
    void setActive(bool b){
        active = b;
    }
    /*
     *  Description:
     *  Return:
     *  Precondition:
     *  Postcondition:
     */
    bool isEner()
    {
        return isEnergizer;
    }





};

#endif // PELLET_H_INCLUDED
