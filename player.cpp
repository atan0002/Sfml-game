#include "player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

player::player(const sf::Vector2f &position)
{
 setPosition(position);


}

void player::moveplayer(sf::Time &elapsed,sf::View &v,std::vector<std::unique_ptr<Platform>> &p,
         sf::Sprite &s){


    auto bounds = getGlobalBounds();
    float t = elapsed.asSeconds();
    //(bounds.top+bounds.height<bounds_bottom_-50)
 if((bounds.top+bounds.height<bounds_bottom_-50)&& gravity==true){
    //gravity
     collision_p=false;
     //collides = false;
        v_y += elapsed.asSeconds() *  a_y_;
  move(0, std::abs(v_y) * elapsed.asSeconds());

  //jump=false;

}

    if((!(this->getGlobalBounds().top+this->getGlobalBounds().height>bounds_bottom_-30
          )&& !jump &&  !collision_p && !collides ) ){
        v_y += elapsed.asSeconds() *  a_y_;
  move(0, std::abs(v_y) * elapsed.asSeconds());
  //gravity=true;

    }
    else{
        v_y=15;
        jump=true;
        collision_p=true;
        gravity=true;
        collides=true;
    }

/*
  for(auto &el:p)
     {

        if( !(el->getGlobalBounds().intersects(this->getGlobalBounds()))){
         collision_p=false;
        }


}*/


   for(auto &el:p)
    {
       if(el->getGlobalBounds().intersects(this->getGlobalBounds())
               )
        {

           // move(0,-t*v_y);
           //collision_p=true;
           //gravity=false;


             if(this->getGlobalBounds().top+this->getGlobalBounds().height>el->getGlobalBounds().top){

             collision_p=true;
             collides=true;
             v_c=-std::abs(v_c);


             }
              if((el->getGlobalBounds().top+el->getGlobalBounds().height+2)>this->getGlobalBounds().top){
           // collides=true;(el->getPosition().x>this->getPosition().x )&&(el->getPosition().x+55<this->getPosition().x) &&
                 //(el->getPosition().y+16>this->getPosition().y)

               v_c=std::abs(v_c);
               collides=true;
              // collision_p=true;

              }
             move(0,-t*v_c);

        }

    }





    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&(bounds.left>bounds_left_+2)
     ){

 collides = false;
 move(t*-std::abs(v_x),0);
 direction="left";
// v.move(-150,0);
     //zrobic tak zeby z lewej strony sie blokował i nie mogł isc dalej && v.getViewport().left<this->getPosition().x

      //  v.move(t*-std::abs(1.05*v_x),0); && (v.getViewport().left>s.getGlobalBounds().left)
      /*  if(v.getViewport().left>this->getGlobalBounds().left){
            v.move(0,0);
            this->setPosition(v.getViewport().left+getGlobalBounds().width,this->getPosition().y);
        }
*/
        for(auto &el:p)
        {
            if(el->getGlobalBounds().intersects(this->getGlobalBounds()))
            {
                collides=true;
                move(t*std::abs(v_x),0);

            }
        }

    }
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))&&
            this->getGlobalBounds().left+getGlobalBounds().width>s.getGlobalBounds().left+getGlobalBounds().width)
    {
         collides = false;
        move(t*std::abs(v_x),0);
      // v.move(t*std::abs(0.9*v_x),0);
        //v.setCenter(this->getPosition().x,0);
        direction="right";

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
        // &&(getGlobalBounds().top+getGlobalBounds().height)<bounds_bottom_
      // move(0,(-150));
      // jump=true;
    /*   if( (((getGlobalBounds().top+getGlobalBounds().height)>bounds_bottom_))){
           move(0,-150);

          */

        /*if(((getGlobalBounds().top+getGlobalBounds().height)<bounds_bottom_)
              ){
            move(0,-150);

        }*/
        //move(0,-50);(el->getGlobalBounds().top>this->getGlobalBounds().top+getGlobalBounds().height)&&

      for(auto &el:p){


     if( ((el->getGlobalBounds().top<this->getGlobalBounds().top+getGlobalBounds().height)&& collision_p==true ) ||

            ( getGlobalBounds().top+getGlobalBounds().height)>bounds_bottom_-30 ){


//gravity=false;
          //jump=true;
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

void player::drawplayer(sf::RenderWindow &window){



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
