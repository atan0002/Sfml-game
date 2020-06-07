#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory.h>



class Platform:public sf::Sprite
{

  // std::vector<sf::Sprite> platforms;
    std::vector<double> pos_1;
    std::vector<double> pos_2;
    double length,quan=0;
    bool start_create=false;


public:

    Platform();
    int count=1;
    // std::vector<std::unique_ptr<Platform>> plat;
    void setgood_position();
    void rand_position(sf::RenderWindow &window,sf::Sprite &s);
    void set_pos();

 // void create(sf::Sprite &p,sf::RenderWindow &window,std::vector<std::unique_ptr<Platform>> &plat);

};

#endif // PLATFORM_H
