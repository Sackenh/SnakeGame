#include <iostream>
#include <windows.h>
#include "world.cpp"
#include "food.cpp"
#include "snake.cpp"

using namespace std;

int main() {
    World w;
    Food food;
    Snake snake;
    bool flag = true;
    w.generateWorld();

    cout << "Make a move" << endl;
        loop:do{

            flag = true; //allows new key input to be made
                if (GetAsyncKeyState(0x41) & flag == true) { //used WASD instead of arrow keys, 0x41 stands for A(Left)
                    w.snake.setDirection(-1, 0);
                    w.update();
                    w.redraw();
                    flag = false;
                    goto loop;
                } else if (GetAsyncKeyState(0x57) & flag == true) { //W Key || (Up)
                    w.snake.setDirection(0, -1);
                    w.update();
                    w.redraw();
                    flag = false;
                    goto loop;
                } else if (GetAsyncKeyState(0x53) & flag == true) { //S Key || (Down)
                    w.snake.setDirection(0, 1);
                    w.update();
                    w.redraw();
                    flag = false; //stop infinite iterations
                    goto loop; //jumps to start
                } else if (GetAsyncKeyState(0x44) & flag == true) { //D Key || (Right)
                    w.snake.setDirection(1,0);
                    w.update();
                    w.redraw();
                    flag = false; //stops infinite iterations + infinite movement - might have to create timer to make an automatic movement
                    goto loop; //jumps to start
                }
        }
        while(w.gameState); //loop will run until border collision occurs and when that occurs gameState will be set to false :)
}
