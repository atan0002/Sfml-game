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

        if(pos_1[i]>pos_1[i+1] && pos_1[i+1]+70<pos_1[i]){

       pos_1[i]=pos_1[i] -100;
        }
        if(pos_2[i]>pos_2[i+1] && pos_2[i+1]+70<pos_2[i]){

       pos_2[i]=pos_2[i] -100;
        }



    }

}

void Platform::rand_position(sf::RenderWindow &window,sf::Sprite &s){


   int size=(s.getGlobalBounds().left+s.getGlobalBounds().width);

     double p1=std::rand() % (size -50);
    double p2=std::rand() % (window.getSize().y - 70);

        if(p2<100){
           p2= p2+100;
        }
        pos_1.emplace_back(p1);
        pos_2.emplace_back(p2);

}
void Platform::set_pos(){

    for(unsigned int i=0; i<pos_1.size();i++){

    for(unsigned int j=0; j<pos_2.size();j++){
        sf::Vector2f position(pos_1[i],pos_2[j]);
    setPosition(position);
    }

    }
}

/*
void Platform::create(sf::Sprite &p,sf::RenderWindow &window,std::vector<std::unique_ptr<Platform>> &plat){

   length=window.getSize().x;
   quan=4;
  //(p.getGlobalBounds().left+p.getGlobalBounds().width)+10<count*length
   start_create=true;
    if((p.getGlobalBounds().left+p.getGlobalBounds().width)+10<count*length){
       /* for (int i = 0; i < quan; i++) {
            auto shape = std::make_unique<Platform>(pla);

            plat.emplace_back(shape);
            std::cout<<"Utworzono"<<std::endl;
        }

        std::cout<<p.getGlobalBounds().left+p.getGlobalBounds().width<<std::endl;
        for(unsigned int i=0;i<pos_1.size();i++){
            pos_1[i]=pos_1[i]+count*length;
          //   pos_2[i]=pos_2[i]+count*length;
        }
        for(unsigned int i=0;i<pos_1.size();i++){
            plat[i]->setPosition(pos_1[i],pos_2[i]);
        }
       /* for(const auto &s:plat){
            window.draw(*s);
        }
    }



}

*/







