#ifndef CANNON_H_INCLUDED
#define CANNON_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Sir.h"
#include "CannonBall.h"
#include <vector>
#include <iostream>
using namespace std;
class Cannon
{
    static sf::Texture Texture;
    static int count;
    sf::Sprite Sprite;
    sf::Vector2f Position;
    sf::Clock Clock;
public :
    Cannon();
    Cannon(sf::Vector2f Pos);
    void setPosition(sf::Vector2f pos){Position = pos;}
    void update(vector<CannonBall*> &cBallList, Sir guy);
    void draw(sf::RenderTarget &window);
    sf::Vector2f getPosition(){return Position;}
};
#endif // CANNON_H_INCLUDED
