#include<iostream>
#include<cstdlib>
#include "ballClass.h"
#include<Windows.h>
ball::ball()
:x_ball(10),y_ball(15)
{
    ball_launch();
}
ball::~ball()
{
    std::cout <<"YOU DESTROYED OBJECT 2";
}
void ball::ball_launch()
{
    int rand_x,rand_y;
    rand_x=rand()%3;
    rand_y=rand()%2;
    if(rand_x==2)
    {
        rand_x=-1;
    }
    if(rand_y==0)
    {
        rand_y=-1;
    }
    x_ball+=rand_x;
    y_ball+=rand_y;
    ball_movement(rand_x,rand_y);

}
void ball::print_ball()
{
     Sleep(2000);
    map[x_ball][y_ball]='@';
}
void ball::ball_movement(int movement_x,int movement_y)
{
    bool Is_GameOver=false;
    while(!Is_GameOver)
    {
        
            x_ball+=movement_x;
            y_ball+=movement_y;
            
        
        functions_calls();
    }

}
void ball:: functions_calls()
{
     print_ball();
     player();
     detect_keyboard();
     map_print();
     check_colision();
     map_update();
}
void ball::check_colision()
{

}
