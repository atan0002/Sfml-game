#include "monkey.h"

monkey::monkey()
{

       if(!tex_mon.loadFromFile("monkey.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }
       setTexture(tex_mon);
       setPosition(15389,300);

}

void monkey::shoot(sf::Sprite &s){
    if(this->getPosition().x-s.getPosition().x>-200 && this->getPosition().x-s.getPosition().x<200){

        if(!tex_mon2.loadFromFile("monkey2.png")){
            std::cout<<"Load failed"<<std::endl;
            system("pause");
        }

        shoot_=true;
        setTexture(tex_mon2);

    }
    else{




        setTexture(tex_mon);
        shoot_=false;
    }

}

void monkey::counter(sf::Sprite &b){

    if(this->getGlobalBounds().intersects(b.getGlobalBounds())){

        counter_bullets++;
     }
   if(counter_bullets>100){
        dead=true;
    }


}
