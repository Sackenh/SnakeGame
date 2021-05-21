//
// Created by Hessel on 3/4/2021.
//
#include <stdlib.h>
#include <iostream>
#include "food.cpp"
#include "snake.cpp"

#ifndef WORLD_CLASS
#define WORLD_CLASS

using namespace std;



class World {
public:
    bool gameState = true;
    bool foodState = true;
    Snake snake;
    Food food;
    int gameScoreCount = 0;

    World(){
        food.setRandomizeLocation();
    }

    void update(){
        if(!foodState){
            foodState = true;
            food.setRandomizeLocation();
        }


        cout << "Current Position: " << snake.location.getX() << ", " << snake.location.getY() << "\n";
        snake.Step();
        cout << "Updated Position: " << snake.location.getX() << ", " << snake.location.getY() << "\n";
    }

    void collision(){ //food and wall collision checker
        if(snake.location.getX() == food.getFoodX() && snake.location.getY() == food.getFoodY()){ //food collision detection
            snake.increaseSnakeLength();
            gameScoreCount += 50;
            cout << "Score: \n" << gameScoreCount;
            foodState = false;
        }

        if(snake.location.getX() == 61 || snake.location.getX() == 0 || snake.location.getY() == 0 || snake.location.getY() == 29) { //border collision detection
            gameState = false;
            cout << "\n GAME OVER! \n";
        }

        snake.shedBody = snake.snakeBody; //body collision detection
        for(int i = 0; i < snake.snakeBody.size(); i++){
            if(snake.shedBody.front().getX() == snake.location.getX() && snake.shedBody.front().getY() == snake.location.getY()){
                gameState = false;

            } else {
                snake.shedBody.pop();
            }
        }
    }
    void generateWorld() {
        for (int i = 0; i < 30; i++) { //set bounds for roof(y)
            for (int j = 0; j < 62; j++) { //set bounds for wall(x)
                if ((j == 0) || (j == 62 - 1)) {
                    cout << "#";
                } else if ((i == 0) || (i == 30 - 1)) {
                    cout << "#";
                } else if(snake.location.getX() == j && snake.location.getY() == i) {
                    cout << "*";
                } else if(food.getFoodX() == j && food.getFoodY() == i) {
                    cout << "@";
                } else if(snake.drawSnakeBody(j, i)) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
        collision();
    }

    void redraw(){
        generateWorld();
    }
};

#endif