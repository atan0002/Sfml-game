#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<random>
#include <iostream>


class enemies:public sf::Sprite
{
    int v_x=100;
    std::vector<int> position;
     sf::Texture tex_wrog;
     double pos;
     sf::Texture tex_wrog_lewo;

    sf::Texture tex_wrog_prawo;

public:
    enemies();

    bool shoot_=false;
    int direction=0;

    void  move_enemy(sf::Time &elapsed);
    void setting_position();
    void shoot(sf::Sprite &s);
    int counter=0;
    bool set_pos=true;
    void loadtex();

};

#endif // ENEMIES_H
