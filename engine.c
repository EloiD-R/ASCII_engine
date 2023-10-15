#include "engine.h"
char image[TERMINAL_COLUMNS][TERMINAL_ROWS];



int placePixel(coordinates coordinates, char character){
    // Convert from double to int.
    int coordinates_x = (int) coordinates.x;
    int coordinates_y = (int) coordinates.y;

    // Actually place the pixel and check if it has valid coordinates.
    if (0 <= coordinates_x && coordinates_x <= TERMINAL_COLUMNS - 1 && 0 <= coordinates_y && coordinates_y <= TERMINAL_ROWS - 1){
        image[coordinates_x][coordinates_y] = character;
    }
}



int display(){
    int index = 0;
    char strImage[TERMINAL_ROWS * TERMINAL_COLUMNS];
    for(int rowsIndex = 0; rowsIndex < TERMINAL_ROWS ; rowsIndex++){
        for(int columnsIndex = 0; columnsIndex < TERMINAL_COLUMNS; columnsIndex++){
            strImage[index++] = image[columnsIndex][rowsIndex];
        }
    }
    strImage[index++] = '\0';
    printf("%s", strImage);
    fflush(stdout);
}




int clearImage(){
    for (int columns = 0; columns < TERMINAL_COLUMNS; columns++) {
        for (int rows = 0; rows < TERMINAL_ROWS; rows++) {
            image[columns][rows] = BACKGROUND_CHARACTER;
        }
    }
}



void drawLine(coordinates point1, coordinates point2, char character) {
    coordinates start = {(int)point1.x, (int)point1.y};
    coordinates end = {(int)point2.x, (int)point2.y};

    while (start.x != end.x || start.y != end.y) {
        placePixel(start, character);

        if (start.x < end.x) {
            start.x++;
        } else if (start.x > end.x) {
            start.x--;
        }

        if (start.y < end.y) {
            start.y++;
        } else if (start.y > end.y) {
            start.y--;
        }
    }
    placePixel(end, character); // Place the last pixel at the end point.
}





void drawSquare(coordinates topLeft, coordinates bottomRight, char character, int filled) {
    coordinates topRight = {(int)bottomRight.x, (int)topLeft.y};
    coordinates bottomLeft = {(int)topLeft.x, (int)bottomRight.y};

    if (!filled) {
        drawLine(topLeft, topRight, character);
        drawLine(topRight, bottomRight, character);
        drawLine(bottomRight, bottomLeft, character);
        drawLine(bottomLeft, topLeft, character);
    } else {
        for (int y = topLeft.y + 1; y < bottomRight.y; y++) {
            for (int x = topLeft.x + 1; x < bottomRight.x; x++) {
                coordinates nextPoint = {x, y};
                placePixel(nextPoint, character);
            }
        }
    }
}



