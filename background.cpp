#include "background.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>

background::background()
{


}


void background::movebg(sf::View &View,sf::Texture &text,sf::FloatRect &fBounds,sf::Sprite &sp,sf::RenderWindow &window,sf::Vector2f &position){

 /*   //ustawianie i inicjowanie obrazu

 View.setViewport(sf::FloatRect(0.f,0.f,1.5f, 2.1f));
sp.setPosition(fBounds.left, fBounds.top - 100.f + View.getSize().y);

 const sf::Vector2f viewStart(fBounds.left + (fBounds.width / 2), fBounds.top + (fBounds.height / 2));
const sf::Vector2f spriteStart(fBounds.left, fBounds.top);

const sf::Vector2f viewOffset(viewStart - View.getCenter());
 sf::Vector2f spriteOffset;

   spriteOffset.x = floor(viewOffset.x / text.getSize().x) * text.getSize().x+50;

     spriteOffset.y = floor(viewOffset.y / text.getSize().y) * text.getSize().y;
     sp.setPosition(spriteStart - spriteOffset);
//std::cout<<spriteStart.x<<std::endl;
//std::cout<<spriteStart.y<<std::endl;

*/
    window.setView(View);

     // sf::Time elapsed=clock.restart();
    //float time= elapsed.asSeconds();
            // clear the window with black color
    position.x=sp.getPosition().x+200-(window.getSize().x/2);
    if(position.x<0){
        position.x=0;
    }

    View.reset(sf::FloatRect(position.x,position.y,window.getSize().x,window.getSize().y));






}

void background::set_center(sf::View &v,sf::RenderWindow &window,sf::Sprite &s,sf::FloatRect &fBounds){

    sf::Vector2f position(fBounds.width/2,0);
    if(s.getPosition().x+10>window.getSize().x/2){
        position.x=s.getPosition().x+10;

    }
    else{
        position.x=window.getSize().x/4;
    }
    v.setCenter(position);

}
void background::drawbg(sf::RenderWindow &window,sf::View &View,sf::Sprite sp){

    window.setView(View);
    window.draw(sp);

}
