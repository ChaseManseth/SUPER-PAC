#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color {
    int R, G, B;
    /*
     * Description: Constructor, sets values of R, G, and B
     *  to zero.
     * Return: none.
     * Precondition: N/A
     * Postcondition: R, G, and B are all equal to zero.
     */
    Color() {
        R = G = B = 0;
    }

    /*
     * Description: Constructor, sets values of R, G, and B
     *  to zero.
     * Return: none.
     * Precondition: N/A
     * Postcondition: R, G, and B are equal to r, g, and b
     *  respectively.
     */
    Color(int r, int g, int b) {
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED
