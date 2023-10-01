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



void drawLine(struct coordinates point1, struct coordinates point2, char character) {
    coordinates start = {(int)point1.x, (int)point1.y};
    coordinates end = {(int)point1.x, (int)point1.y};

    for(int index = 0; index < TERMINAL_COLUMNS; index++) {
        placePixel(end, character);
        if(end.x < point2.x){
            end.x++;
        }
        if(end.y < point2.y){
            end.y++;
        }
    }
}
