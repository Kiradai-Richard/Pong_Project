#pragma once
class pong{
    protected:
    static char m_map[20][31];
    static const int m_height,m_width,m_padSize;
    const int m_XpadCoord;
    int m_YpadCoord,m_LastPadTile;
    public:
    pong();
    pong(int,int);
    ~pong();
    static void map_update();
    static void map_print();
    void paddles();
    void pong_movement(int);
    void detect_keyboard();
    static void computer_algorithm();
    void computer_movement(int);
    static void reset();
    public:
        int  score;
       
};