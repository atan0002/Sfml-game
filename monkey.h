#ifndef MONEKY_H
#define MONEKY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class monkey:public sf::Sprite
{
    sf::Texture tex_mon;
    int counter_bullets=0;
    sf::Texture tex_mon2;

public:
    bool dead=false;
    bool shoot_=false;
    bool intersects=false;
    monkey();
    void shoot(sf::Sprite &s);
    void counter(sf::Sprite &b);

};

#endif // MONEKY_H
