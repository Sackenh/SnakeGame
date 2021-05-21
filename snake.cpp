//
// Created by Hessel on 3/4/2021.
//
#include <iostream>
#include "point.cpp"
#include <queue>

using namespace std;

#ifndef SNAKE_CLASS
#define SNAKE_CLASS

class Snake {
public:
    queue<Point> snakeBody;
    queue<Point> shedBody;

    Point Direction;
    Point location;

    int startingLength = 0;

    Snake(){
        for(int i =0; i < startingLength; i++){
            snakeBody.push(location);
        }
    }

    void setDirection(int x, int y){
        Direction = Point(x, y);
    }

    bool drawSnakeBody(int x, int y) {
        shedBody = snakeBody;
        for(int i = 0; i < snakeBody.size(); i++){
            if(shedBody.front().getX() == x && shedBody.front().getY() == y){
                return true;
            } else {
                shedBody.pop();
            }
        }
        return false;
    }

   void Step(){
        snakeBody.pop();

        snakeBody.push(location);
        location = Point(location.getX() + Direction.getX(), location.getY()+ Direction.getY());
    }

    void increaseSnakeLength(){
        snakeBody.push(location);
        location = Point(location.getX() + Direction.getX(), location.getY() + Direction.getY());
    }
};

#endif