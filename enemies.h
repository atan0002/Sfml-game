#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<random>


class enemies:public sf::Sprite
{
    int v_x=100;
    std::vector<int> position;


public:
    enemies();
    bool shoot_=false;
    std::string direction;
    void  move_enemy(sf::Time &elapsed,sf::RenderWindow &w,sf::Texture & t1,sf::Texture &t2);
    void setting_position(sf::Sprite &s);
    void shoot(sf::Sprite &s);

};

#endif // ENEMIES_H
