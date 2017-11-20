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

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color {
    int R, G, B;

    Color() {
        R = G = B = 0;
    }

    Color(int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
