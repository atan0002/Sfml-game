#ifndef BIRD_H
#define BIRD_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory.h>
#include<algorithm>

class bird: public sf::Sprite
{
    sf::Texture tex;
    std::vector<std::unique_ptr<bird>> birds;
    int v_x=100;
    std::vector<double> position;


public:
    bird();
    bool set_visable=false;

    void move_bird(sf::Time &elapsed);

    void set_position_bird(sf::Sprite &s);
    void set_new_position(sf::Sprite &s);
    void animate_texture(sf::Texture &tex,sf::Texture &tex2,float t);

};

#endif // BIRD_H
