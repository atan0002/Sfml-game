#include "platform.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

Platform::Platform()
{



}

void Platform::setgood_position(){
    for(unsigned int i=0;i<pos_1.size();i++){

        if(pos_1[i]-pos_1[i+1]>-100 && pos_1[i]-pos_1[i+1]<0){

       pos_1[i]=pos_1[i] -90;
        }
       if(pos_1[i]-pos_1[i+1]>0 && pos_1[i]-pos_1[i+1]<100){
             pos_1[i]=pos_1[i] +0;
        }
        if(pos_2[i]-pos_2[i+1]>-151 && pos_2[i]-pos_2[i+1]<0){

       pos_2[i]=pos_2[i] -50;
        }



    }

}

void Platform::rand_position(sf::Sprite &s){


   int size=(s.getGlobalBounds().left+s.getGlobalBounds().width);

     double p1=std::rand() % (size -50);
    double p2=std::rand() % (450-80);

        if(p2<100){
           p2= p2+100;
        }
        pos_1.emplace_back(p1);
        pos_2.emplace_back(p2);

}
void Platform::set_pos(){
    this->setgood_position();

    for(unsigned int i=0; i<pos_1.size();i++){

    for(unsigned int j=0; j<pos_2.size();j++){
        sf::Vector2f position(pos_1[i],pos_2[j]);
    setPosition(position);
    }

    }
}







