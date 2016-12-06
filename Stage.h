#ifndef STAGE_H_INCLUDED
#define STAGE_H_INCLUDED

#include "Background.h"
#include <iostream>
using namespace std;
class Stage
{
    Background ForeGround[3];
    Background BGround[3];
public:
    Stage()
    {
        float y = 400.f;
        for(int i=0;i<3;++i)
        {
            float x = i*500 + rand()%500;
            ForeGround[i].setPosition(sf::Vector2f(x,y));
            x = i*500 + rand()%500;
            BGround[i].setPosition(sf::Vector2f(x,y));
            cout<<x<<" "<<y<<endl;
        }
    }
    void draw(sf::RenderTarget &window);
    void update(float deltaTime);

};
#endif // STAGE_H_INCLUDED
