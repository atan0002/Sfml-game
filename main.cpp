#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <background.cpp>
#include <cmath>
#include "background.h"
#include <player.cpp>
#include "player.h"

 int pred=150;



























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

    player pl(sf::Vector2f(100.0,370.0));
    pl.setTexture(texture);
    pl.setSpeed(150,150);
    pl.setAcceleration(0,300);
    pl.setBounds(0,game.getSize().x,0,game.getSize().y);


    //tło

       sf::View            View;
       //(game.getDefaultView());
        sf::FloatRect       fBounds(0.f, 0.f, 1800.f, 1000.f); // arbitrary > view height
        sf::Texture text;
        sf::IntRect         iBounds(fBounds);
         text.setRepeated(true);
         if(!text.loadFromFile("country_field.png")){
             std::cout<<"Load failed"<<std::endl;
             system("pause");
         }

         sf::Sprite sp(text,iBounds);
background bg;

    // create some shapes


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

           if(event.type == sf::Event::KeyReleased){
             pl.setTexture(texture);
           }

        }



 // sf::Time elapsed=clock.restart();
//float time= elapsed.asSeconds();
        // clear the window with black color



game.clear(sf::Color::Black);

//inicjacja tła

 bg.movebg(View,text,fBounds,sp);
 game.clear();
 bg.drawbg(game,View,sp);


pl.moveplayer(elapsed,View);

game.draw(pl);





















        /*if(gracz_bounds.left<0){
            pred=std::abs(pred);

        }*/
        /*if(gracz_bounds.left+gracz_bounds.width>799){
        pred=-std::abs(pred);

        }*/

       game.display();
    }

    return 0;
}


