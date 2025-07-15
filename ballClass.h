#pragma once
#include "pongClass.h"
class ball:public pong{
int x_ball,y_ball;
public:
ball();
~ball();
void ball_launch();
void print_ball();
void ball_movement();
void check_colision();
};