#include "life.h"

life::life()
{

     if(!tex_lod.loadFromFile("lod.png")){
         std::cout<<"Load failed"<<std::endl;
         system("pause");
     }
     setTexture(tex_lod);


}
void life::set_position(){

    double y=rand()% (400+10);
    double x=std::rand() % 15389+300;
setPosition(x,y);

}
