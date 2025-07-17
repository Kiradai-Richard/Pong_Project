#pragma once
#include "pongClass.h"
class ball:public pong{
static int m_Xball;
static int m_Yball;
public:
ball();
~ball();
void ball_launch();
static void print_ball();
void ball_movement(int,int);
static void check_colision();
void functions_calls();
};