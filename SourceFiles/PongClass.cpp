#include<iostream>
#include<conio.h>
#include<chrono>
#include<thread>
#include "ballClass.h"
char pong::m_map[20][31];
int const pong::m_height(20);
int const pong::m_width(31);
int const pong::m_padSize(5);
pong::pong()
:m_XpadCoord(10),m_YpadCoord(29)
{
    for(int i=0;i<m_height;++i)
    {
        for(int j=0;j<m_width;++j)
        {
            m_map[i][j]=' ';
        }
    }
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
        m_map[m_XpadCoord+i][m_YpadCoord]='|';
    }
}
void pong::pong_movement(int movement)
{
    if((m_XpadCoord==14 && movement==1) || ( m_XpadCoord==0 && movement== -1 )) //m_XpadCoord==14 because the body its 5 tiles long and m_XpadCoord==0 because the first tile is the head
       {
        m_XpadCoord=m_XpadCoord;
       }
    else
    {
        m_XpadCoord+=movement;
        if(movement>0)
        {
            m_map[m_XpadCoord+m_padSize-1][m_YpadCoord]='|'; 
            m_map[m_XpadCoord-1][m_YpadCoord]=' ';
        }
        else
        {
            m_map[m_XpadCoord][m_YpadCoord]='|';
            m_map[m_XpadCoord+m_padSize][m_YpadCoord]=' ';   
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
