#include "bullet.h"

bullet::bullet()
{

       if(!tex_bullet.loadFromFile("pocisk_wroga.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }
       setTexture(tex_bullet);


}


void bullet::setting_position(int pos_x,int pos_y){
    sets=sets+1;
  if(sets==1){
    this->setPosition(pos_x,pos_y);
    position_=pos_x;

}

}


void bullet::move_bullet(int direction,sf::Time &elapsed ,sf::Sprite &s){

    float t=elapsed.asSeconds();
    counter_=counter_+1;



    if(direction==1){

        this->move(t*v_x,0);


    }
    if(direction==-1){

        this->move(-t*v_x,0);

    }

    if(position_ +250<this->getPosition().x || position_-250>this->getPosition().x ){

        sets=0;


       set_visible=false;
         this->setPosition(s.getPosition().x,s.getPosition().y);
        shooted=true;




}
}
