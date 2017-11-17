#include "font.h"
#include "tile.h"

void Tile::drawFont(int r, int c, SDL_Plotter& g)
{
    Tile space(r, c, false);
    x = space.getPosX();
    y = space.getPosY();
    col = c*SIZE_TILE;
    row = r*SIZE_TILE;

    for(int yval = 0; yval < 25; yval++){
        for(int xval = 0; xval < 25; xval++){
            if(isPixel()){
                g.plotPixel(x, y, 255, 255, 255);
            }
        }
    }
}
