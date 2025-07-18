#pragma once
#include "pongClass.h"
class ball:public pong{
static int m_Xball;
static int m_Yball;
static int m_XcurrentMove;
static int m_YcurrentMove;
public:
ball();
~ball();
static void ball_launch();
static void print_ball();
static void ball_movement();
static void check_colision();
static bool GameOver_Check();
void GamePlay();
};