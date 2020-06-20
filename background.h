#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class background
{
public:
    background();
    void movebg(sf::View &View,sf::Sprite &sp,sf::RenderWindow &window,sf::Vector2f &position,
                sf::Sprite &s);
    void drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp);


};

#endif // BACKGROUND_H
