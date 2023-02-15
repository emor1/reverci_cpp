#include "SimpleShape.h"

void DrawEllipse(int r, int in_x, int in_y, SDL_Renderer* renderer){
    for(int x=-r;x<=r;x++){
        int y = sqrt(r*r-x*x)+0.5;
        int px = x+in_x;
        int py = y-in_y;
        SDL_RenderDrawPoint(renderer, px, py);
        py = in_y - y;
        SDL_RenderDrawPoint(renderer, px, py);
        // py = y+in_y;
        // SDL_RenderDrawPoint(renderer, x, in_y);
    }
}

void draw_circle(SDL_Renderer *renderer, int sx, int sy, int r) {
    int x, y, px, py;

    /* x を基準に点を描画 */
    for( x = -r; x <= r; x++ ) {
       y = sqrt(r*r - x*x) + 0.5;
       px = sx + x;
       py = sy - y;
       SDL_RenderDrawPoint(renderer, px, py);
       py = sy + y;
       SDL_RenderDrawPoint(renderer, px, py);
    }
    /* y を基準に点を描画 */
    for( y = -r; y <=r; y++ ) {
       x = sqrt(r*r - y*y) + 0.5;
       px = sx + x;
       py = sy - y;
       SDL_RenderDrawPoint(renderer, px, py);
       px = sx - x;
       SDL_RenderDrawPoint(renderer, px, py);
    }
}

void fill_circle(SDL_Renderer *renderer, int sx, int sy, int r) {
    int x, y, px, py1, py2;

    for( x = -r; x <= r; x++ ) {
       y = sqrt(r*r - x*x) + 0.5;
       px = sx + x;
       py1 = sy - y;
       py2 = sy + y;
       SDL_RenderDrawLine(renderer, px, py1, px, py2);
    }
}