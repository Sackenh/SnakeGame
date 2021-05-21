//
// Created by Hessel on 3/4/2021.
//
#include "snake.cpp"
#include <stdlib.h>
#include <time.h>


#ifndef FOOD_CLASS
#define FOOD_CLASS


class Food {
    Point location;
    int randomPointX;
    int randomPointY;
    Snake snake;
public:

    void setRandomizeLocation() {
        srand(time(NULL));
        randomPointX = rand() %60  +1;
        srand(time(NULL));
        randomPointY = rand() %28 +1;
    }

    int getFoodX(){
        return randomPointX;
    }

    int getFoodY() {
        return randomPointY;
    }




};
#endif

