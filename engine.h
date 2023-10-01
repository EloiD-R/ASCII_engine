#ifndef GRAPHICS_ENGINE_ENGINE_H
#define GRAPHICS_ENGINE_ENGINE_H



// Standards libs.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



// In number of chars.
#define TERMINAL_ROWS 49
#define TERMINAL_COLUMNS 190

// Define booleans.
#define true 1
#define false 0

// Background character management.
#ifndef BACKGROUND_CHARACTER
#define BACKGROUND_CHARACTER ' '



typedef struct coordinates coordinates;;
struct coordinates{
    float x;
    float y;
};



int placePixel(coordinates coordinates, char character);
int display();
int clearImage();
void drawLine(coordinates start, coordinates end, char character);



#endif // BACKGROUND_CHARACTER
#endif //GRAPHICS_ENGINE_ENGINE_H
