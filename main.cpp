#include <iostream>
#include<ctime>
#include "ballClass.h"
int main()
{
    srand((int)time(0));
     ball game;
        game.map_update();
        game.player();
        game.detect_keyboard();
        game.print_ball();
        game.map_print();
    

}
