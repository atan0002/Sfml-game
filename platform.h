#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory.h>



class Platform:public sf::Sprite
{


    std::vector<double> pos_1;
    std::vector<double> pos_2;
    double length,quan=0;





public:

    Platform();
    int count=1;

    void setgood_position();
    void rand_position(sf::Sprite &s);
    void set_pos();



};

#endif // PLATFORM_H
