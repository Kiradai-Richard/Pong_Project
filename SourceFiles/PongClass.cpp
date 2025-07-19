#include<iostream>
#include<conio.h>
#include<chrono>
#include<thread>
#include<cmath>
#include "ballClass.h"
extern ball Ball;
extern pong computer;
extern pong player;
char pong::m_map[20][31];
int const pong::m_height(20);
int const pong::m_width(31);
int const pong::m_padSize(5);
pong::pong()
:m_YpadCoord(10),m_XpadCoord(29),score(0)
{
    srand((int)time(0));
    for(int i=0;i<m_height;++i)
    {
        for(int j=0;j<m_width;++j)
        {
            m_map[i][j]=' ';
        }
    }
}
pong::pong(int x, int y)
:m_YpadCoord(x),m_XpadCoord(y),score(0)
{
srand((int)time(0));
}
pong::~pong(){
    std::cout <<"YOU DESTROYED OBJECT";
}
void pong::map_update()
{
    for(int i=0;i<m_height;++i)
    {
        for(int j=0;j<m_width;++j)
        {
            if(j==15)
            {
                m_map[i][j]='#';
            }
            else
            {
                m_map[i][j]=' ';
            }
        }
    }
}
    void pong::map_print()
{

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        system("cls");
        for(int i=0;i<m_height;++i)
        {
            for(int j=0;j<m_width;++j)
            {
                if(m_map[i][j]=='#' || m_map[i][j]=='|' || m_map[i][j]=='@')
                    std::cout <<m_map[i][j];
                 else    
                    std::cout << " ";
            }
            std::cout <<"\n";
        }
}
void pong::paddles()
{
   
    for(int i=0;i<m_padSize;++i)
    {
       m_map[m_YpadCoord+i][m_XpadCoord]='|';//m_map[m_YpadCoord+i][m_XpadCoord]='|'
        if(i==m_padSize-1)
        {
            m_LastPadTile=m_YpadCoord+i;
        }
    }
}
void pong::pong_movement(int movement)
{
    if((m_YpadCoord==14 && movement==1) || ( m_YpadCoord==0 && movement== -1 )) //m_YpadCoord==14 because the body its 5 tiles long and m_XpadCoord==0 because the first tile is the head
       {
        m_YpadCoord=m_YpadCoord;
       }
    else
    {
        m_YpadCoord+=movement;
        if(movement>0)
        {
            m_map[m_YpadCoord+m_padSize-1][m_XpadCoord]='|'; 
            m_map[m_YpadCoord-1][m_XpadCoord]=' ';
        }
        else
        {
            m_map[m_YpadCoord][m_XpadCoord]='|';
            m_map[m_YpadCoord+m_padSize][m_XpadCoord]=' ';   
        }
    }
}
void pong::detect_keyboard()
{
    int current_movement,upcoming_movement;
    if(_kbhit())
    {
        upcoming_movement=_getch();
    }
    current_movement=upcoming_movement;
    switch (current_movement)
    {
    case 'w':
        pong_movement(-1);
        break;
    case 's':
        pong_movement(1);
        break;
    default :
        break;
    }
}
void pong::computer_algorithm()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(32));
    if(Ball.m_YcurrentMove == -1)
    {
        if( Ball.m_Xball< computer.m_YpadCoord)
        {
       
            computer.computer_movement(-1);
        }
        else if(Ball.m_Xball > computer.m_YpadCoord-4)
        {
            computer.computer_movement(1);
        }
    }
    else
        {
            //surprinsgly important
        }
} 
void pong::computer_movement(int movement)
{
     std::this_thread::sleep_for(std::chrono::milliseconds(16));
     computer.pong_movement(movement);
}
void pong::reset()
{
     for(int i=0;i<m_height;++i)
    {
        for(int j=0;j<m_width;++j)
        {
            if(j==15)
            {
                m_map[i][j]='#';
            }
            else
            {
                m_map[i][j]=' ';
            }
        }
    }
    player.m_YpadCoord=10;
    computer.m_YpadCoord=10;
}

