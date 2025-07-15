#include<iostream>
#include<conio.h>
#include "pongClass.h"
pong::pong()
:height(20),width(29),X_Cord(10),player_size(5)
{
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<30;++j)
        {
            map[i][j]=' ';
        }
    }
}
pong::~pong(){
    std::cout <<"YOU DESTROYED OBJECT";
}
void pong::map_update()
{
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<30;++j)
        {
            if(j==15)
            {
                map[i][j]='#';
            }
            else
            {
                map[i][j]=' ';
            }
        }
    }
}
void pong::map_print()const
{
     system("cls");
    for(int i=0;i<height;++i)
    {
        for(int j=0;j<30;++j)
        {
            if(map[i][j]=='#' || map[i][j]=='|' || map[i][j]=='@')
                std::cout <<map[i][j];
            else
                std::cout << " ";
        }
        std::cout <<"\n";
    }
}
void pong::player()
{
   
    for(int i=0;i<player_size;++i)
    {
        map[X_Cord+i][width]='|';
    }
}
void pong::pong_movement(int movement)
{
    if((X_Cord==15 && movement==1) || ( X_Cord==0 && movement== -1 ))
       {
        X_Cord=X_Cord;
       }
    else
    {
        X_Cord+=movement;
        if(movement>0)
        {
            map[X_Cord+player_size-1][width]='|';
            map[X_Cord-1][width]=' ';
        }
        else
        {
            map[X_Cord][width]='|';
            map[X_Cord+player_size][width]=' ';   
        }
    }
}
void pong::detect_keyboard()
{
    int movement=_getch();
    switch (movement)
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