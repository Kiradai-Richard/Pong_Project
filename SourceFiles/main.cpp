#include <iostream>
#include "ballClass.h"
#include<thread>
pong computer(10,1);
ball Ball;
pong player;
int main()
{
    while(player.score<5 || computer.score<5)
    {
    srand((int)time(0));
     Ball.GamePlay();
     if(Ball.GameOver_Check())
     {
       Ball.reset();
       computer.reset();
     }
    }
    (player.score>computer.score)?(std::cout<<"Player has won\n"):std::cout<<"Computer has won\n";
    system("pause");
     
}
