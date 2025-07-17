#include <iostream>
#include "ballClass.h"
int main()
{
    srand((int)time(0));
     ball player;
        player.map_update();
        player.paddles();
        player.detect_keyboard();
        player.print_ball();
        player.map_print();
    

}
