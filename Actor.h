#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <map>
#include <string>


using namespace std;
class Actor
{
protected:
    float Speed;
    bool isAttacking;
   float Attack;
    int Health;
    float Xvel,Yvel;
    sf::Vector2f Position;
    map<string,Animation> Animations;
    AnimatedSprite AnimSprite;
    bool isMoving;
    int Direction;
    float JumpSpeed;
public:
    //Actor(int xv,int yv,sf::Vector2f pos,int hlth);
    //virtual void update();
    AnimatedSprite& getSprite(){return AnimSprite;};
};

#endif // ACTOR_H_INCLUDED
