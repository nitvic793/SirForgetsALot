#include "CannonBall.h"
#include "Settings.h"
#include <iostream>
using namespace std;
sf::Texture CannonBall::Texture;
int CannonBall::count = 0;
CannonBall::CannonBall(sf::Vector2f pos)
{
    if(count==0)
    Texture.loadFromFile("images/cball.png");
    count++;
    cout<<count;
    //system("cls");
    Sprite.setTexture(Texture);
    moving = true;
    Clock.restart();
    Position = pos;
    canDie = false;
    isHit = false;
}

void CannonBall::draw(sf::RenderTarget& window)
{
    if(!isHit)
    window.draw(Sprite);
}

void CannonBall::update(Sir &guy, sf::Time frameTime)
{
    if(moving)
    {
        //cout<<guy.getSprite().getLocalBounds().height<<endl;
        Position.x -= SPEED*frameTime.asSeconds();
        if(Position.x<0)
            moving = false;
        if(Clock.getElapsedTime().asSeconds()>0.4f)
        {
            sf::Vector2f pos = guy.getSprite().getPosition();
            if(Position.x>pos.x && Position.x< pos.x + guy.getSprite().getLocalBounds().width-30.f
               && (pos.y < Position.y && pos.y + guy.getSprite().getLocalBounds().height > Position.y))
            {
                guy.reduceHealth(HITPOINTS);
                cout<<"Hit!\n";
                Clock.restart();
                isHit = true;
            }
        }
        Sprite.setPosition(Position);
    }
    if(!moving || Position.x+200.f < guy.getPosition().x)
        canDie = true;
}
