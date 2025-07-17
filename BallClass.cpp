#include<iostream>
#include<cstdlib>
#include<chrono>
#include<thread>
#include "ballClass.h"
int ball:: m_Xball(10);
int ball:: m_Yball(15);
ball::ball()
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
    m_Xball+=rand_x;
    m_Yball+=rand_y;
    ball_movement(rand_x,rand_y);

}
void ball::print_ball()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    m_map[m_Xball][m_Yball]='@';
}
void ball::ball_movement(int movement_x,int movement_y)
{
    bool Is_GameOver=false;
    while(!Is_GameOver)
    {
            m_Xball+=movement_x;
            m_Yball+=movement_y;
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
