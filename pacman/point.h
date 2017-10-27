#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

struct Point
{
    int x, y;

    Point()
    {
        x = y = 0;
    }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

#endif // POINT_H_INCLUDED
