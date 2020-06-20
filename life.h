#ifndef LIFE_H
#define LIFE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class life:public sf::Sprite
{
    sf::Texture tex_lod;
public:
    life();
    void set_position();
};

#endif // LIFE_H
