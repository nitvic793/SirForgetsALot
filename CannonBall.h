#ifndef CANNONBALL_H_INCLUDED
#define CANNONBALL_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Sir.h"
class CannonBall
{
    static sf::Texture Texture;
    static int count;
    sf::Sprite Sprite;
    sf::Vector2f Position;
    bool moving;
    sf::Clock Clock;
    bool canDie;
    bool isHit;
public:
    CannonBall(sf::Vector2f pos);
    void setPosition(sf::Vector2f pos){Position = pos;}
    void update(Sir &guy,sf::Time frameTime);
    void draw(sf::RenderTarget& window);
    const bool& isMoving(){return moving;}
    const bool& isClearable(){return canDie;}
};
#endif // CANNONBALL_H_INCLUDED
