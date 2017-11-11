#include "circle.h"

Circle::Circle(Point c, int r, Color col)
{
    center = c;
    radius = r;
    color = col;
}

void Circle::setCenter(const Point p) {
    center = p;
}
void Circle::setRadius(const int r) {
    radius = r;
}
void Circle::setColor(const Color c) {
    color = c;
}

Point Circle::getCenter() const {
    return center;
}
int Circle::getRadius() const {
    return radius;
}
Color Circle::getColor() const {
    return color;
}

void Circle::draw(SDL_Plotter& g)const {
    // x^2 + y ^2 = r^2

    for(int x = -radius; x <= radius; x++) {
        for(int y = -radius; y <= radius; y++) {
            if(sqrt(x * x + y * y) <= radius) {
                g.plotPixel(center.x + x, center.y + y, color.R, color.G, color.B);
                //g.update();
            }
        }
    }
}
