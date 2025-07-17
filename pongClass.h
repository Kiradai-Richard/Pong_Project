#pragma once
class pong{
    protected:
    static char m_map[20][30];
    static const int m_height,m_width,m_player_size;
    int m_XCord;
    public:
    pong();
    ~pong();
    static void map_update();
    static void map_print();
    void player();
    void pong_movement(int);
    void detect_keyboard();
    bool GameOver();
    
};