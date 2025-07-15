#pragma once
class pong{
    char map[20][30];
    int height,width,X_Cord,player_size;
    public:
    pong();
    ~pong();
    void map_update();
    void map_print()const;
    void player();
    void pong_movement(int);
    void detect_keyboard();
    
};