#include "background.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

background::background()
{


}

void background::movebg(sf::View &View,sf::Texture &text,sf::FloatRect &fBounds,sf::Sprite &sp){

    //ustawianie i inicjowanie obrazu

 View.setViewport(sf::FloatRect(0.f,0.f,1.9f, 1.7f));
 sp.setPosition(fBounds.left, fBounds.top - 1000.f + View.getSize().y);

 const sf::Vector2f viewStart(fBounds.left + (fBounds.width / 2), fBounds.top + (fBounds.height / 2));
const sf::Vector2f spriteStart(fBounds.left, fBounds.top);

const sf::Vector2f viewOffset(viewStart - View.getCenter());
 sf::Vector2f spriteOffset;

   spriteOffset.x = floor(viewOffset.x / text.getSize().x) * text.getSize().x+722;

      spriteOffset.y = floor(viewOffset.y / text.getSize().y) * text.getSize().y;
      sp.setPosition(spriteStart - spriteOffset);









}
void background::drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp){
    window.setView(View);
   window.draw(sp);

}
