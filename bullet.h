#ifndef BULLET_H
#define BULLET_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class bullet:public sf::Sprite
{

int v_x=250;

double position_;
 sf::Texture tex_bullet;


public:
    bullet();

    void  setting_position(int pos_x,int pos_y);
  void move_bullet(int direction,sf::Time &elapsed,sf::Sprite &s);
  bool set_visible=true;
  int sets=0;
  bool shooted=false;
  int counter_=0;
  int direction=0;



};

#endif // BULLET_H
