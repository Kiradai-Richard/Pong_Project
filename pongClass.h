#pragma once
class pong{
    protected:
    char map[20][30];
    int const height,width,player_size;
    int X_Cord;
    public:
    pong();
    ~pong();
    void map_update();
    void map_print()const;
    void player();
    void pong_movement(int);
    void detect_keyboard();
    bool GameOver();
    
};