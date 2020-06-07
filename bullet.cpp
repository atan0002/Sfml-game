#include "bullet.h"

bullet::bullet()
{


}


void bullet::setting_position(int pos_x,int pos_y){

    this->setPosition(pos_x,pos_y);
    position_=pos_x;
    position.emplace_back(pos_x);


}


void bullet::move_bullet(std::string direction,sf::Time &elapsed ,sf::Sprite &s){

    float t=elapsed.asSeconds();
    if(direction=="right"){

        this->move(t*v_x,0);
       // set_visible=true;

    }
    if(direction=="left"){

        this->move(-t*v_x,0);
       // set_visible=true;
    }
   //for(unsigned int i=0;i<position.size();i++){
    if(position_ +250<this->getPosition().x || position_-250>this->getPosition().x ){
        set_visible=false;
   // }
}
}
