#include "enemies.h"

enemies::enemies()
{

}

void enemies::setting_position(sf::Sprite &s){


    int size=(s.getGlobalBounds().left+s.getGlobalBounds().width);

      int p1=std::rand() % 15389+300;
      //int val = Random::get(-10, 10);

      for(unsigned int i=0; i<position.size();i++){
          if(position[i]<position[i+1] +270 && position[i+1]-270>position[i]){
              position[i]=position[i]-270;
          }if(position[i]>0&& position[i]<300){
              position[i]=position[i]+500;
          }
      }

      this-> setPosition(p1,410);
       position.emplace_back(p1);
}
void enemies::shoot(sf::Sprite &s){

    if(this->getPosition().x-s.getPosition().x<200 && this->getPosition().x-s.getPosition().x>0){
        direction="right";
        shoot_=true;
     }
    if(this->getPosition().x-s.getPosition().x>-200 && this->getPosition().x-s.getPosition().x<0){
        direction="left";
        shoot_=true;
     }
    else{
        shoot_=false;
    }


}


void enemies::move_enemy(sf::Time &elapsed,sf::RenderWindow &w,sf::Texture & t1,sf::Texture &t2){

    auto bounds =  getGlobalBounds();
    float t=elapsed.asSeconds();
    //position.emplace_back(400);
   // double p1=400;
    move(-t*v_x,0);
    //setTexture(t1);
    for(unsigned int i=0;i<position.size();i++){
    if(this->getGlobalBounds().left<position[i]-250){

        v_x= -std::abs(v_x);
        setTexture(t2);

    }
    if((this->getGlobalBounds().left< position[i]+250)&& getGlobalBounds().left>position[i]){
       v_x=std::abs(v_x);
       setTexture(t1);
    }
}


    }
