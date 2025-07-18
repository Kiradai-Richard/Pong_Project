#include <iostream>
#include "ballClass.h"
#include<thread>
pong computer(10,1);
ball Ball;
pong player;
int main()
{
    srand((int)time(0));
     Ball.GamePlay();
     //std::thread(computer.computer_algorithm).detach();
}
