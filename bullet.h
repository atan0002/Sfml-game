#ifndef BULLET_H
#define BULLET_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class bullet:public sf::Sprite
{

int v_x=250;
std::vector<int> position;
double position_;

public:
    bullet();
    void  setting_position(int pos_x,int pos_y);
  void move_bullet(std::string direction,sf::Time &elapsed,sf::Sprite &s);
  bool set_visible=true;





};

#endif // BULLET_H
