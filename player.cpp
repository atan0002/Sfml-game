#include "player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

player::player(const sf::Vector2f &position)
{
 setPosition(position);

}

void player::moveplayer(sf::Time &elapsed,sf::View &v){

    auto bounds = getGlobalBounds();
    float t = elapsed.asSeconds();
    if(bounds.top+bounds.height<50+bounds_bottom_){
    //gravity

        v_y += elapsed.asSeconds() *  a_y_;
  move(0, v_y * elapsed.asSeconds());





    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){


        move(t*-std::abs(v_x),0);
        v.move(t*-std::abs(v_x),0);


    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        move(t*std::abs(v_x),0);
        v.move(t*std::abs(v_x),0);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&((getGlobalBounds().top+getGlobalBounds().height)>bounds_bottom_))
    {

        move(0,-175);



}




}
void player::drawplayer(sf::RenderWindow &window){



}

void player:: setAcceleration(float acceleration_x, float acceleration_y) {
        a_x_ = acceleration_x;
        a_y_ = acceleration_y;
    }

void player:: setSpeed(float v_x_, float v_y_) {
    v_x = v_x_;
    v_y= v_y_;

}


void player::setBounds(const float &left,const float &right,const float &top,const float &bottom)
  {
     bounds_top_ = top;
     bounds_left_ = left;
     bounds_right_ = right;
     bounds_bottom_ = bottom;
  }


