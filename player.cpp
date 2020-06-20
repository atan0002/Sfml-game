#include "player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

player::player(const sf::Vector2f &position)
{
 setPosition(position);
 if(!texture.loadFromFile("ludzik.png")){
     std::cout<<"Load failed"<<std::endl;
     system("pause");
 }
 setTexture(texture);


}

void player::moveplayer(sf::Time &elapsed,std::vector<std::unique_ptr<Platform>> &p, sf::Sprite &s){


    auto bounds = getGlobalBounds();
     t = elapsed.asSeconds();

//warunek sprawdzający czy pozycja gracza jest w polu gracza i czy nie skacze czy nie koliduje z platfromą
//i czy nie ma kolizji podczas kolizji zwiazanych z pojsciem w prawo albo w lewo
//lub gdy pozycja gracza zajduje sie w polu gry i jest wlaczona grawitacja i nie koliduje z innymi przyciskami
//wtedy działa grawitacja
// w innym przypadku włączony jest skok i kolizje
    if((!(this->getGlobalBounds().top+this->getGlobalBounds().height>bounds_bottom_-30
          )&& !jump &&  !collision_p && !collides ) || (gravity&&
            !(this->getGlobalBounds().top+this->getGlobalBounds().height>bounds_bottom_-30) && !collides) ){
        v_y += elapsed.asSeconds() *  a_y_;
 move(0, std::abs(v_y) * elapsed.asSeconds());


    }
    else{

        v_y=10;
        jump=true;
        collision_p=true;

        collides=true;

    }




   for(auto &el:p)
    {
       if(el->getGlobalBounds().intersects(this->getGlobalBounds())
               )
        {


            move(0,-t*v_c);

             if(this->getGlobalBounds().top+this->getGlobalBounds().height>el->getGlobalBounds().top){

             collision_p=true;
             collides=true;
             v_c=-std::abs(v_c);


             }
              if((el->getGlobalBounds().top+el->getGlobalBounds().height+2)>this->getGlobalBounds().top){


               v_c=std::abs(v_c);
               collides=true;


              }



        }

    }




//poruszanie w lewa strone
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(bounds.left>bounds_left_+2)
     ){

 collides = false;
 move(t*-std::abs(v_x),0);
 setTexture(texture3);
 direction=-1;


        for(auto &el:p)
        {
            if(el->getGlobalBounds().intersects(this->getGlobalBounds()))
            {
                collides=true;
                move(t*std::abs(v_x),0);

            }
        }

    }
    //poruszanie w prawo
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))&&
            this->getGlobalBounds().left+getGlobalBounds().width<(s.getGlobalBounds().left+s.getGlobalBounds().width)-600)
    {
         collides = false;
        move(t*std::abs(v_x),0);
 setTexture(texture2);




        direction=1;

        for(auto &el:p)
        {
            if(el->getGlobalBounds().intersects(this->getGlobalBounds()))
            {
                collides=true;
                move(-t*std::abs(v_x),0);
            }


        }


    }



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&(bounds.top>bounds_top_+53)
          &&jump==true )
    {

        collides=false;
      for(auto &el:p){


     if( ((el->getGlobalBounds().top<this->getGlobalBounds().top+getGlobalBounds().height)&& collision_p==true )
      ||  (( getGlobalBounds().top+getGlobalBounds().height)>bounds_bottom_-30)){



collides = true;
      }

     if(collides==true){
         move(0,-150);
         collides=false;
         collision_p=false;

     }

}

 collision_p=false;
collides = false;
gravity=true;
jump=false;



}





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

void player::shoot(){


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
        shoot_=true;

    }

}

void player::display_lifes(sf::RenderWindow &w, int l,sf::Sprite &s){

    sf::Font font;
    if(!font.loadFromFile("arial.ttf")){
        exit(-1);
}
    std::stringstream ss;
       ss << l;
        std::string str = ss.str();



   sf::Text text;
   text.setFont(font);
   text.setCharacterSize(25);
   text.setString(str.c_str());
   text.setPosition(s.getPosition().x+200-(w.getSize().x/2),10);


    w.draw(text);

}

void player::loadtex(){


     if(!texture.loadFromFile("ludzik.png")){
         std::cout<<"Load failed"<<std::endl;
         system("pause");
     }

      if(!texture2.loadFromFile("ludzik_prawo.png")){
          std::cout<<"Load failed"<<std::endl;
          system("pause");
      }

       if(!texture3.loadFromFile("ludzik_lewo.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }


}


