#ifndef STARTEND_H
#define STARTEND_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class startend:public sf::Sprite
{

    sf::Texture tex_start;
    //sf::Texture tex_end;

public:
    startend();
     bool set_visable_start=true;
     bool set_visable_end=false;
     void setting_visable_start(sf::RenderWindow &w);
     void setting_visable_end(int l,sf::Sprite &s,sf::Texture &tex);


};

#endif // STARTEND_H
