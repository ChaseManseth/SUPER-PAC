#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    int x, y;


    /*
     * Description: Constructor, sets default Point values of
     *  x = y = 0.
     * Return: none.
     * Precondition: N/A
     * Postcondition: x and y both equal zero.
     */
    Point()
    {
        x = y = 0;
    }
    /*
     * Description: Constructor, sets values of x and y to
     *  values of a and b, respectively.
     * Return: none.
     * Precondition: N/A
     * Postcondition: x and y are both equal to a and b
     *  respectively.
     */
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

#endif // POINT_H_INCLUDED
