#pragma once
#include "pongClass.h"
class ball:public pong{
protected:
    static int m_XcurrentMove;
    
public:
    static int m_YcurrentMove;
    static int m_Xball;
    static int m_Yball;
    ball();
    ~ball();
    static void ball_launch();
    static void print_ball();
    static void ball_movement();
    static void check_colision();
    static bool const GameOver_Check();
    static void GamePlay();
    static void reset();
};