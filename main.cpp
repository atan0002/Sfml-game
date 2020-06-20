#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "background.h"
#include "player.h"
#include "platform.h"
#include <memory>
#include <vector>
#include <algorithm>
#include<cstdlib>
#include "enemies.h"
#include "bullet.h"
#include "bird.h"
#include "life.h"
#include "monkey.h"
#include "startend.h"
#include <map>



 int main() {

   sf::RenderWindow game(sf::VideoMode(800,500), "Dorwij Malpe");

game.setFramerateLimit(60);

   sf::Texture texture;
    if(!texture.loadFromFile("ludzik.png")){
        std::cout<<"Load failed"<<std::endl;
        system("pause");
    }


      sf::Texture tex_plat;
       if(!tex_plat.loadFromFile("platforma.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }


              sf::Texture tex_bullet;
                 if(!tex_bullet.loadFromFile("pocisk_wroga.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }
                 sf::Texture tex;
                 if(!tex.loadFromFile("bird.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }
                 sf::Texture tex_bird;
                 if(!tex_bird.loadFromFile("bird2.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }

                 sf::Texture tex_bull;
                 if(!tex_bull.loadFromFile("pocisk_monkey.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }


                 sf::Texture tex_start;
                 if(!tex_start.loadFromFile("startowy_.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }

                 sf::Texture tex_end;
                 if(!tex_end.loadFromFile("gameover.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }







       bullet b;
        startend s_e;



         std::vector<std::unique_ptr<life>> ice_cream;

         for(int i =0;i<20;i++)
         {
            ice_cream.emplace_back(std::make_unique<life>());

  }

         for(auto &s:ice_cream){
             s->set_position();
         }



       std::vector<std::unique_ptr<bird>> bird_;


       for(int i =0;i<4;i++)
       {
          bird_.emplace_back(std::make_unique<bird>());

}




    std::vector<std::unique_ptr<Platform>> platforms;
   Platform p;
    p.setTexture(tex_plat);
    const int number_of_elements = 120;
    for (int i = 0; i < number_of_elements; i++) {
        auto shape = std::make_unique<Platform>(p);

        platforms.emplace_back(move(shape));

    }











    player pl(sf::Vector2f(10.0,400.0));
    pl.setTexture(texture);
    pl.setSpeed(150,150);
    pl.setAcceleration(0,700);
    pl.setBounds(0,game.getSize().x,0,game.getSize().y);
    pl.loadtex();

    //tło

       sf::View            View;
       View.setViewport(sf::FloatRect(0.f,0.f,1.0f, 1.0f));
       //(game.getDefaultView());
      sf::FloatRect       fBounds(0.f, 0.f, 16089.f, 1000.f); // arbitrary > view height
        sf::Texture text;

        View.reset(sf::FloatRect(0,0,game.getSize().x,game.getSize().y));

         if(!text.loadFromFile("pole1.png")){
             std::cout<<"Load failed"<<std::endl;
             system("pause");
         }

monkey m;

bullet b_mon;
 b_mon.setTexture(tex_bull);


       sf::Sprite sp(text);
background bg;

for(const auto &s:bird_){
    s->set_position_bird(pl);

}

for(const auto &s: platforms){
    s->rand_position(sp);

    s->set_pos();
}


std::vector<std::pair<std::unique_ptr<enemies>,std::unique_ptr<bullet>>> en_bul;

for(unsigned int i=0; i<30;i++){


en_bul.emplace_back(std::make_pair(std::make_unique<enemies>(),std::make_unique<bullet>()));

  }


for(const auto &s: en_bul){
    s.first->setting_position();
    s.first->loadtex();

}

s_e.setting_visable_start(game);




sf::Vector2f position(0,0);




    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Time el=clock2.restart();
    sf::Time el2=clock3.restart();


    while (game.isOpen()) {

        sf::Time elapsed=clock.restart();

        el=clock2.getElapsedTime();
        el2=clock3.getElapsedTime();

        sf::Event event;

        while (game.pollEvent(event)) {


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                game.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
                       {




                          }
           if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
                 {



                     }

           if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::C))
                 {


                    b.setting_position(pl.getPosition().x,pl.getPosition().y+10);
                    b.set_visible=true;

                     }

           if (event.type == sf::Event::MouseButtonPressed){
               sf::Vector2i mouse_pos = sf::Mouse::getPosition(game);
               if(event.mouseButton.button==sf::Mouse::Left){
                   if((mouse_pos.x>183 && mouse_pos.x<351) && (mouse_pos.y>224 && mouse_pos.y<300 )){

                     s_e.set_visable_start=false;
                     s_e.setPosition(20000,40000);

                   }
                   if((mouse_pos.x>320 &&  mouse_pos.x<440)&& (mouse_pos.y>320 && mouse_pos.y<450)){
                      game.close();

                   }


               }
}
           if(event.type == sf::Event::KeyReleased){
             pl.setTexture(texture);


           }

        }



game.clear(sf::Color::Black);




 game.clear();











 //fragment odpowiadajacy za poruszanie tla
 bg.movebg(View,pl,game,position,sp);
 game.draw(sp);

 //petla rysujaca platromy
 for(const auto &s: platforms){
     game.draw(*s);
 }







 for(const auto &s: en_bul){


    s.first->move_enemy(elapsed);
   //if(s.first->dead==false){
    s.first->shoot(pl);
   //}

   if((s.second->getGlobalBounds().intersects(pl.getGlobalBounds()))){

       pl.lifes=pl.lifes-2;

   }


   //warunek odpowiadajacy za sprawdzanie czy gracz jest w poblizu i ustawiajacy widocznosc pocisku
  if(s.first->shoot_==true){
       s.second->set_visible=true;
}



            if(s.second->set_visible==true&& s.first->shoot_==true ){
               s.second->setting_position(s.first->getPosition().x,430);


            s.second->move_bullet(s.first->direction,elapsed,*s.first);

            game.draw(*s.second);

           }








     game.draw(*s.first);

 }



//instrukcje odpowiedzialne za gracza i jego pocisk

if(!s_e.set_visable_end){
pl.moveplayer(elapsed,platforms,sp);
}

game.draw(pl);
pl.shoot();
pl.display_lifes(game,pl.lifes,pl);
b.move_bullet(pl.direction,elapsed,pl);
if(b.set_visible && pl.shoot_){
game.draw(b);

}

//petla odpowiedzialna za obsluge obiektow klasy bird
for(const auto &s:bird_){



if(el.asSeconds()>=5){


s->set_visable=true;
s->set_new_position(pl);
 clock2.restart();
 clock3.restart();
}

if(s->set_visable){

s->move_bird(elapsed);
s->animate_texture(tex,tex_bird,el2.asSeconds());

game.draw(*s);
}

}






//usuwanie wrogow
for(auto it=en_bul.begin();it!=en_bul.end();it++){

    enemies* en=dynamic_cast<enemies*>(it->first.get());

  if(en!=nullptr){
    if((en->getGlobalBounds().intersects(b.getGlobalBounds())) ){
       it=en_bul.erase(it);

    }


  }

}




//kolizja z obiektem klasy ice_cream

for(auto it=ice_cream.begin();it!=ice_cream.end();it++){
    life * l=dynamic_cast<life*>(it->get());
    if(l!=nullptr){

        if(l->getGlobalBounds().intersects(pl.getGlobalBounds())){

            ice_cream.erase(it);
            pl.lifes=pl.lifes+15;
        }


    }



}




//kolizja z obiektami klasy bird
for(auto it=bird_.begin();it!=bird_.end();it++){

    bird* bir=dynamic_cast<bird*>(it->get());
    if(bir!=nullptr){
        if(bir->getGlobalBounds().intersects(pl.getGlobalBounds())){
            it=bird_.erase(it);
            bird_.emplace_back(std::make_unique<bird>());
            pl.lifes=pl.lifes-10;

        }
        if(bir->getGlobalBounds().intersects(b.getGlobalBounds())){

            it=bird_.erase(it);
            bird_.emplace_back(std::make_unique<bird>());

        }



    }



}


//ryswowanie obiektow klasy ice_cream

for(auto &s:ice_cream){
    game.draw(*s);

}





//fragment kodu odpowiedzialny za obsluge obiektu klasy monkey
m.shoot(pl);
if(m.shoot_){

    b_mon.set_visible=true;

}
if(b_mon.set_visible){

    b_mon.setting_position(m.getPosition().x,m.getPosition().y+120);
    b_mon.move_bullet(-1,elapsed,pl);
    game.draw(b_mon);

    if(b_mon.getGlobalBounds().intersects(pl.getGlobalBounds())){

        pl.lifes=pl.lifes-2;

    }
}

m.counter(b);

if(!m.dead){
game.draw(m);
}
if(m.dead){
    game.close();
}



s_e.setting_visable_end(pl.lifes,pl,tex_end);
if((s_e.set_visable_start==true) || s_e.set_visable_end){

game.draw(s_e);

}





       game.display();
    }

    return 0;
}



