#include "bird.h"

bird::bird()
{

    if(!tex.loadFromFile("bird.png")){
        std::cout<<"Load failed"<<std::endl;
        system("pause");
    }
    setTexture(tex);

}


void bird::set_position_bird(sf::Sprite &s){




       double y=rand()% (400+10);



setPosition(s.getPosition().x+1000,y);
position.emplace_back(y);



}


void bird::move_bird(sf::Time &elapsed){


  this->move(-elapsed.asSeconds()*v_x,0);






}



void bird::set_new_position(sf::Sprite &s){
    double y=rand()% (400+10);
    if(getPosition().x-s.getPosition().x<-400){
        setPosition(s.getPosition().x+800,y);

    }


}



void bird::animate_texture(sf::Texture &tex, sf::Texture &tex2, float t){


    if(t>0 && 2<t){
        setTexture(tex);
    }
    if(t>2 && t<6){
        setTexture(tex2);

    }
    else{
        setTexture(tex);
    }



}












