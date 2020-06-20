#include "enemies.h"

enemies::enemies()
{

       if(!tex_wrog.loadFromFile("wrog.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }
       setTexture(tex_wrog);

}

void enemies::setting_position(){



      int p1=std::rand() % 15089+300;

      this-> setPosition(p1,410);
      pos=p1;

}
void enemies::shoot(sf::Sprite &s){

    if( (this->getPosition().x-s.getPosition().x>-200 && this->getPosition().x-s.getPosition().x<200)){

        shoot_=true;
      }

   else{
        set_pos=false;
        shoot_=false;
    }
}


void enemies::move_enemy(sf::Time &elapsed){


    float t=elapsed.asSeconds();

    move(-t*v_x,0);


    if(this->getGlobalBounds().left<pos-250 && getGlobalBounds().left<pos){

        v_x= -std::abs(v_x);
        setTexture(tex_wrog_prawo);

       //ustawienie kierunku pocisku
       direction=1;


    }
    if((this->getGlobalBounds().left< pos+250)&& getGlobalBounds().left>pos){
       v_x=std::abs(v_x);
       setTexture(tex_wrog_lewo);
    //ustawianie kierunku pocisku
       direction=-1;

    }

 }

void enemies::loadtex(){



       if(!tex_wrog_lewo.loadFromFile("wrog_lewo.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }

          if(!tex_wrog_prawo.loadFromFile("wrog_prawo.png")){
              std::cout<<"Load failed"<<std::endl;
              system("pause");
          }



}
