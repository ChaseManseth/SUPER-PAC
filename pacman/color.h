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

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color {
    int R, G, B;
    /*
         *  Description: Blank constructor for Color
         *  Return: none
         *  Precondition: none
         *  Postcondition: R, G, and B are assigned 0
         */
    Color() {
        R = G = B = 0;
    }
    /*
         *  Description: Constructor for Color
         *  Return: none
         *  Precondition: r, g, and b exist
         *  Postcondition: R, G, and B are assigned r, g, and b respectively
         */
    Color(int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
