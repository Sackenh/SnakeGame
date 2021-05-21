//
// Created by Hessel on 3/4/2021.
//

#include <iostream>

#ifndef POINT_CLASS
#define POINT_CLASS


class Point {
private:
        int xcord;
        int ycord;

public:
    Point(){
        xcord = 31;
        ycord = 15;
    }

    Point(int x, int y){
        xcord = x;
        ycord = y;
    }

    int getX(){
        return xcord;
    }

    int getY(){
        return ycord;
    }
};

#endif