#include "line.h"

Line::Line(){
    p2.x = 1;
    p2.y = 1;
}
bool Line::slope(double&m)const{
    bool hasSlope;

    hasSlope = p1.x != p2.x;

    if(hasSlope){
        m = (p1.y-p2.y)/(p1.x-p2.x);
    }

    return hasSlope;
}
bool Line::intercept(double& b) const{
    bool hasInter;
    double m;

    hasInter = slope(m);
    if(hasInter){
        b = p1.y - m*p1.x;
    }

    return hasInter;
}
void Line::setP1(const Point& p){
    p1 = p;
}
void Line::setP2(const Point& p){
    p2 = p;
}
void Line::setColor(const Color& c){
    color = c;
}
Point Line::getP1() const{
    return p1;
}
Point Line::getP2() const{
    return p2;
}
Color Line::getColor() const{
    return color;
}
void Line::draw(SDL_Plotter& g)const{
    double m, b;
    int delta = 1, y;

    if(slope(m)){
        intercept(b);
        if(p1.x > p2.x){
            delta = -1;
        }
        for(int x = p1.x; x != p2.x + delta; x += delta){
            y = m*x +b;
            g.plotPixel(x,y, color.R, color.G, color.B);
        }
    } else {
        if(p1.y > p2.y){
            delta = -1;
        }
        for(int y = p1.y; y != p2.y + delta; y += delta){
            g.plotPixel(p1.x, y, color.R, color.G, color.B);

        }
    }
}
