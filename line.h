#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "SDL_Plotter.h"
#include "point.h"
#include "color.h"

class Line{

  private:

        Point p1, p2;
        Color color;
        bool slope(double& m)const;
        bool intercept(double& b)const;

    public:
        Line();

        void setP1(const Point&);
        void setP2(const Point&);
        void setColor(const Color& c);

        Point getP1() const;
        Point getP2() const;
        Color getColor() const;
        void draw(SDL_Plotter& )const;

};

#endif // LINE_H_INCLUDED
