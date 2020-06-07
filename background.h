#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>


class background
{
public:
    background();
    void movebg(sf::View &View,sf::Texture &text,sf::FloatRect &fBounds,sf::Sprite &sp,sf::RenderWindow &window,sf::Vector2f &position);
    void drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp);
    void set_center(sf::View &v,sf::RenderWindow &window,sf::Sprite &s,sf::FloatRect &fBounds);

};

#endif // BACKGROUND_H
