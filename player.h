#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class player:public sf::Sprite
{
    private:
    float a_x_ = 0;
    float a_y_ = 0;
    int v_x=0;
    int v_y=0;
    float bounds_left_ ;
    float bounds_right_;
    float bounds_top_ ;
    float bounds_bottom_ ;



public:

    player(const sf::Vector2f &position);
    void moveplayer(sf::Time &elapsed,sf::View &v);
    void drawplayer(sf::RenderWindow &window);
    void setAcceleration(float acceleration_x, float acceleration_y);
    void setSpeed(float v_x_, float v_y_);
    void setBounds(const float &left,const float &right,const float &top,const float &bottom);
};

#endif // PLAYER_H
