#include "startend.h"

startend::startend()
{

}


void startend::setting_visable_start(sf::RenderWindow &w){

    if(!tex_start.loadFromFile("startowy_.png")){
        std::cout<<"Load failed"<<std::endl;
        system("pause");
    }
    setTexture(tex_start);
    setScale(0.85,0.85);





}


void startend::setting_visable_end(int l,sf::Sprite &s,sf::Texture &tex_end){


    if(l<=0){


        setTexture(tex_end);
        set_visable_end=true;
        setPosition(s.getPosition().x-200,0);




    }





}







