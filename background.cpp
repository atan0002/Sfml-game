#include "background.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

background::background()
{


}


void background::movebg(sf::View &View,sf::Sprite &sp,sf::RenderWindow &window,sf::Vector2f &position,sf::Sprite &s){

    window.setView(View);

    if(sp.getGlobalBounds().left+sp.getGlobalBounds().width<s.getGlobalBounds().left +s.getGlobalBounds().width){

    position.x=sp.getPosition().x+200-(window.getSize().x/2);
    if(position.x<0){
        position.x=0;
    }


    View.reset(sf::FloatRect(position.x,position.y,window.getSize().x,window.getSize().y));

}

}


void background::drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp){

    window.setView(View);
    window.draw(sp);

}
