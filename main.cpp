#include <iostream>
#include "pongClass.h"
int main()
{
     pong game;
    while(1)
    {
        game.map_update();
        game.player();
        game.detect_keyboard();
        game.map_print();
    }

}
