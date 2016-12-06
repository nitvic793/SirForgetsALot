#ifndef SIR_H_INCLUDED
#define SIR_H_INCLUDED

#include "Actor.h"
#include <vector>
#include "Platform.h"
using namespace std;

class Sir : public Actor
{
    bool isBlocking,isIdle,isFalling;
    bool isWalking;
    int health;
    bool isJumping,reachedScreenLimit;
    sf::Texture tex;
    sf::Texture tex2;
    sf::Texture texArray[5];
    float xLimit;
    float inY;
    sf::Sprite Shadow;
    void updateShadow();
public:
    Sir();
    void update(sf::Time frameTime,vector<Platform*> pList);
    AnimatedSprite &getSprite(){return AnimSprite;}
    sf::Texture& getTexture(){return texArray[0];}
    bool checkCollision(Actor &ac);
    sf::Sprite &getShadow(){return Shadow;}
    void setPosition(const sf::Vector2f& pos){AnimSprite.setPosition(pos);};
    bool hasReachedScreenLimit(){return reachedScreenLimit;}
    void reduceHealth(int byValue){health-=byValue;}
    sf::Vector2f getPosition(){return AnimSprite.getPosition();}
    int getHealth(){return health;}

};


#endif // SIR_H_INCLUDED
