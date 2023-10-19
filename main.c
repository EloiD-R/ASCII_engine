#include "engine.h"


int main() {
    // clear screen because else it can create an offset
    system("clear");

    int frameDuration = 1000000 / 30; // For 60 FPS.


    coordinates topLeft1 = {5, 5};
    coordinates topLeft2 = {10, 10};
    coordinates squareVelocity = {1, 1};

    coordinates bottomRight1 = {10, 10};
    coordinates bottomRight2 = {20, 15};

    coordinates point1 = {10, 20};
    coordinates point2 = {20, 20};


    while (true) {

        clearImage();
        drawSquare(topLeft1, bottomRight1, '#', 0);

        drawLine(point1, point2, '#');

        if(bottomRight2.y == TERMINAL_ROWS){
            squareVelocity.y = -1;
        } else if(bottomRight2.x == TERMINAL_COLUMNS){
            squareVelocity.x = -1;
        } else if(topLeft2.y == 0){
            squareVelocity.y = +1;
        } else if(topLeft2.x == 0){
            squareVelocity.x = +1;
        }

        topLeft2.x += squareVelocity.x;
        bottomRight2.x = topLeft2.x + 10;//(bottomRight2.x - topLeft2.x);
        topLeft2.y += squareVelocity.y;
        bottomRight2.y = topLeft2.y + 5;//(bottomRight2.y - topLeft2.y);


        drawSquare(topLeft2, bottomRight2, '@', 1);

        point2.x += 1;
        placePixel(point2, '#');

        display();

        usleep(frameDuration);
    }
}