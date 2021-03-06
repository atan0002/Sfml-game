#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platform.h"
#include <sstream>
#include <string>


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
    int v_y2=250;
    int v_c=150;
     sf::String text;
  float t;
      sf::Texture texture;

      sf::Texture texture2;
      sf::Texture texture3;



public:
    int lifes=200;
    int life_monkey=70;
   void display_lifes(sf::RenderWindow &w,int l,sf::Sprite &s);

   bool jump=false;
   bool collision_p=false;
   bool collides = false;
   bool gravity=false;

    player(const sf::Vector2f &position);
    void moveplayer(sf::Time &elapsed,std::vector<std::unique_ptr<Platform>> &p,sf::Sprite &s);

    void setAcceleration(float acceleration_x, float acceleration_y);
    void setSpeed(float v_x_, float v_y_);
    void setBounds(const float &left,const float &right,const float &top,const float &bottom);
    void shoot();
    void loadtex();
    bool shoot_=false;
    int direction=0;
};

#endif // PLAYER_H
