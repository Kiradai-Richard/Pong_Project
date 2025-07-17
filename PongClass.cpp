#include<iostream>
#include<conio.h>
#include<chrono>
#include<thread>
#include "ballClass.h"
char pong::m_map[20][30];
int const pong::m_height(20);
int const pong::m_width(29);
int const pong::m_player_size(5);
pong::pong()
:m_XCord(10)
{
    for(int i=0;i<m_height;++i)
    {
        for(int j=0;j<30;++j)
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
        for(int j=0;j<30;++j)
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
            for(int j=0;j<30;++j)
            {
                if(m_map[i][j]=='#' || m_map[i][j]=='|' || m_map[i][j]=='@')
                    std::cout <<m_map[i][j];
                 else    
                    std::cout << " ";
            }
            std::cout <<"\n";
        }
}
void pong::player()
{
   
    for(int i=0;i<m_player_size;++i)
    {
        m_map[m_XCord+i][m_width]='|';
    }
}
void pong::pong_movement(int movement)
{
    if((m_XCord==15 && movement==1) || ( m_XCord==0 && movement== -1 ))
       {
        m_XCord=m_XCord;
       }
    else
    {
        m_XCord+=movement;
        if(movement>0)
        {
            m_map[m_XCord+m_player_size-1][m_width]='|'; 
            m_map[m_XCord-1][m_width]=' ';
        }
        else
        {
            m_map[m_XCord][m_width]='|';
            m_map[m_XCord+m_player_size][m_width]=' ';   
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
bool pong::GameOver()
{
    return false;
}