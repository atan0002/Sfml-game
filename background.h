#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class background
{
public:
    background();
    void movebg(sf::View &View,sf::Texture &text,sf::FloatRect &fBounds,sf::Sprite &sp);
    void drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp);


};

#endif // BACKGROUND_H
