#include "SimpleShape.h"

#define PI 3.1415

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

void testCircle(SDL_Renderer* renderer){
    float x, y;
    float r = 100;
    float r2 = 300;
    for(float i = 0; i < 2*PI; i+=0.001){
        x = r * cos(i) + 200;
        y = r2 * sin(i) + 200;
        printf("%f , %f\n", x, y);
        SDL_RenderDrawPoint(renderer, (int)x, (int)y);
    }
}