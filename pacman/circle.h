#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include <cmath>

using namespace std;

class Circle {
    private:
        Point center;
        int radius;
        Color color;

    public:
        /*
         * Description: Constructor, sets center, radius, and color
         *  to c, r, and col, respectively.
         * Return: N/A
         * Precondition: none
         * Postcondition: center, radius, and color are equal to
         *  c, r, and col, respectively.
         */
        Circle(Point c, int r, Color col);

        /*
         * Description: sets center to p
         * Return: void
         * Precondition: p is initialized.
         * Postcondition: center = p, p is unchanged
         */
        void setCenter(const Point p);

        /*
         * Description: sets radius to r
         * Return: void
         * Precondition: r is initialized
         * Postcondition: radius = r, r is unchanged
         */
        void setRadius(const int r);

        /*
         * Description: sets color to col
         * Return: void
         * Precondition: col is initialized
         * Postcondition:
         */
        void setColor(const Color col);

        /*
         * Description: returns center
         * Return: Point
         * Precondition: center is initialized
         * Postcondition: center is returned.
         */
        Point getCenter() const;

        /*
         * Description: returns radius
         * Return: int
         * Precondition: radius is initialized
         * Postcondition: radius is returned
         */
        int getRadius() const;

        /*
         * Description: returns color
         * Return: Color
         * Precondition: color is initialized
         * Postcondition: color is returned
         */
        Color getColor() const;

        /*
         * Description: draws to the SDL_Plotter
         * Return: void
         * Precondition: SDL_Plotter g is initialized
         * Postcondition: circle is drawn to the plotter
         */
        void draw(SDL_Plotter& g)const;
};

#endif // CIRCLE_H_INCLUDED
