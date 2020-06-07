
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <background.cpp>
#include <cmath>
#include "background.h"
#include <player.cpp>
#include "player.h"
#include "platform.h"
#include "memory.h"
#include <vector>
#include <algorithm>
#include<cstdlib>
#include "enemies.h"
#include "bullet.h"



 //int pred=150;



























 int main() {
    // create the window
   sf::RenderWindow game(sf::VideoMode(800,500), "My window");

   //widok i sprite

   sf::Texture texture;
    if(!texture.loadFromFile("ludzik.png")){
        std::cout<<"Load failed"<<std::endl;
        system("pause");
    }
    sf::Texture texture2;
     if(!texture2.loadFromFile("ludzik_prawo.png")){
         std::cout<<"Load failed"<<std::endl;
         system("pause");
     }
     sf::Texture texture3;
      if(!texture3.loadFromFile("ludzik_lewo.png")){
          std::cout<<"Load failed"<<std::endl;
          system("pause");
      }

      sf::Texture tex_plat;
       if(!tex_plat.loadFromFile("platforma.png")){
           std::cout<<"Load failed"<<std::endl;
           system("pause");
       }
     sf::Texture tex_wrog;
        if(!tex_wrog.loadFromFile("wrog.png")){
            std::cout<<"Load failed"<<std::endl;
            system("pause");
        }
        sf::Texture tex_wrog_lewo;
           if(!tex_wrog_lewo.loadFromFile("wrog_lewo.png")){
               std::cout<<"Load failed"<<std::endl;
               system("pause");
           }

           sf::Texture tex_wrog_prawo;
              if(!tex_wrog_prawo.loadFromFile("wrog_prawo.png")){
                  std::cout<<"Load failed"<<std::endl;
                  system("pause");
              }

              sf::Texture tex_bullet;
                 if(!tex_bullet.loadFromFile("pocisk_wroga.png")){
                     std::cout<<"Load failed"<<std::endl;
                     system("pause");
                 }

        std::vector<std::unique_ptr<bullet>>  enemy_bullets;
       bullet b;
       b.setTexture(tex_bullet);



       for (int i = 0; i < 4; i++) {
           auto shape = std::make_unique<bullet>(b);

           enemy_bullets.emplace_back(move(shape));
           std::cout<<"Utworzono pocisk"<<std::endl;
       }


    std::vector<std::unique_ptr<Platform>> platforms;
   Platform p;
    p.setTexture(tex_plat);
    //p.setrand_position(game);
    const int number_of_elements = 150;
    for (int i = 0; i < number_of_elements; i++) {
        auto shape = std::make_unique<Platform>(p);

        platforms.emplace_back(move(shape));
        std::cout<<"Utworzono"<<std::endl;
    }



    player pl(sf::Vector2f(10.0,370.0));
    pl.setTexture(texture);
    pl.setSpeed(150,150);
    pl.setAcceleration(0,700);
    pl.setBounds(0,game.getSize().x,0,game.getSize().y);


    //tło

       sf::View            View;
       View.setViewport(sf::FloatRect(0.f,0.f,1.0f, 1.0f));
       //(game.getDefaultView());
      sf::FloatRect       fBounds(0.f, 0.f, 16089.f, 1000.f); // arbitrary > view height
        sf::Texture text;
        //sf::IntRect         iBounds(fBounds);
        View.reset(sf::FloatRect(0,0,game.getSize().x,game.getSize().y));
       //  text.setRepeated(true);
         if(!text.loadFromFile("pole1.png")){
             std::cout<<"Load failed"<<std::endl;
             system("pause");
         }



       sf::Sprite sp(text);
background bg;

//sf::Sprite back;
//back.setTexture(text);

    // create some shapes
for(const auto &s: platforms){
    s->rand_position(game,sp);
    s->setgood_position();
    s->set_pos();
}

std::vector<std::unique_ptr<enemies>> enemies_;
enemies e;
e.setTexture(tex_wrog);
//e.setting_position(sp);
//e.setPosition(400,450);
const int number = 25;
for (int i = 0; i < number; i++) {
    auto shape = std::make_unique<enemies>(e);

    enemies_.emplace_back(move(shape));
    std::cout<<"Utworzono wroga"<<std::endl;
}

for(const auto &s: enemies_){
    s->setting_position(sp);

}

sf::Vector2f position(0,0);




    sf::Clock clock;
    // run the program as long as the window is open
    while (game.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Time elapsed=clock.restart();
        sf::Event event;

        while (game.pollEvent(event)) {


            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                game.close();
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
                       {

                pl.setTexture(texture2);


                          }
           if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
                 {

               pl.setTexture(texture3);

                     }
           if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
                 {



                     }
           if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::C))
                 {


                    b.setting_position(pl.getPosition().x,430);
                    b.set_visible=true;

                     }

           if(event.type == sf::Event::KeyReleased){
             pl.setTexture(texture);
            // pl.jump=false;

           }

        }



game.clear(sf::Color::Black);

//inicjacja tła
//p.create(pl,game,platforms);

//game.draw(back);
 game.clear();
 bg.movebg(View,text,fBounds,pl,game,position);

 game.draw(sp);

 //game.setView(game.getDefaultView());
 //bg.set_center(View,game,pl,fBounds);
// bg.drawbg(game,View,sp);
 for(const auto &s: platforms){
     game.draw(*s);
 }
 for(const auto &s: enemies_){
    s->move_enemy(elapsed,game,tex_wrog_lewo,tex_wrog_prawo);
    s->shoot(pl);
    /*if(s->shoot_==true){


            b.move_bullet(s->direction,elapsed,*s);
            if(b.set_visible==true){
            game.draw(b);
            }

       }*/
     game.draw(*s);
 }

pl.moveplayer(elapsed,View,platforms,sp);
//e.move_enemy(elapsed,game,tex_wrog_lewo,tex_wrog_prawo);
game.draw(pl);

pl.shoot();
b.move_bullet(pl.direction,elapsed,pl);
if(b.set_visible && pl.shoot_){
game.draw(b);

}





















       game.display();
    }

    return 0;
}



