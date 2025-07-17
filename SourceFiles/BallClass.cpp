#include<iostream>
#include<chrono>
#include<thread>
#include "ballClass.h"
int ball:: m_Xball(10);
int ball:: m_Yball(15);
int ball:: m_XcurrentMove(0);
int ball:: m_YcurrentMove(0);
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
    rand_y=rand()%2+1;
   if(rand_x==2)
        rand_x=-1;
    if(rand_y==2)
     {
      rand_y=-1;
     }
    m_XcurrentMove=rand_x;
    m_YcurrentMove=rand_y;
    m_Xball+=rand_x;
    m_Yball+=rand_y;
    ball_movement();
}
void ball::print_ball()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(16));//milliseconds(16)
    m_map[m_Xball][m_Yball]='@';
}
void ball::ball_movement()
{
    while(!GameOver_Check())
    {
            m_Xball+=m_XcurrentMove;
            m_Yball+=m_YcurrentMove;
            print_ball();
            paddles();
            detect_keyboard();
            map_print();
            check_colision();
            map_update();
    }
}
void ball::check_colision()
{
    if(GameOver_Check)
  if( m_map[m_Xball][m_Yball+1]=='|'|| m_map[m_Xball][m_Yball-1]=='|')
  {
        if(m_XcurrentMove==0)
            {
                m_XcurrentMove=m_YcurrentMove;
            }
        m_YcurrentMove*= -1;
        m_Yball+=m_YcurrentMove;

    }
    else if(m_Xball-1 ==0 || m_Xball==m_height-1)
    {
         m_XcurrentMove*= -1;
         m_Xball+=m_XcurrentMove;
    }
}
bool ball::GameOver_Check()
{
    if((m_Yball==0 && m_map[m_Xball][m_Yball]!='|') || (m_Yball==m_YpadCoord && m_map[m_Xball][m_Yball]!='|'))
        return true;
    else
        return false;
}

