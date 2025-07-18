#pragma once
class pong{
    protected:
    static char m_map[20][31];
    static const int m_height,m_width,m_padSize;
    const int m_YpadCoord;
    int m_XpadCoord;
    public:
    pong();
    ~pong();
    static void map_update();
    static void map_print();
    void paddles();
    void pong_movement(int);
    void detect_keyboard();
    protected:
       
};