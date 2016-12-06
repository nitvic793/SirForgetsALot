#include "Ground.h"
#include "../Settings.h"
#include <iostream>
using namespace std;
Ground::Ground()
{
    //ctor
    groundTexture.loadFromFile("images/ground.jpg");
    mudTexture.loadFromFile("images/mud.jpg");
    sprite.setTexture(groundTexture);
    mudSprite.setTexture(mudTexture);
    mudSprite.setScale(0.5f,0.5f);
    sprite.scale(0.69f,0.60f);
    position.x = -650.f;
    position.y = 450.f;
    mudPosition = position;
    mudPosition.y = 500.f;
    sprite.setPosition(position);
    mudSprite.setPosition(mudPosition);
    levelXLimit = 8000.f;
}

Ground::~Ground()
{
    //dtor
}

void Ground::draw(sf::RenderTarget &window)
{
   // cout<<window.getView().getViewport().left;
    //system("cls");
    mudSprite.setPosition(mudPosition);
    while(mudSprite.getPosition().x<levelXLimit)
    {
        window.draw(mudSprite);
        while(mudSprite.getPosition().y<HEIGHT)
        {
            window.draw(mudSprite);
            mudSprite.move(0,mudSprite.getLocalBounds().height*mudSprite.getScale().y);
        }
        mudSprite.setPosition(mudSprite.getPosition().x,mudPosition.y);
        mudSprite.move(mudSprite.getLocalBounds().width*mudSprite.getScale().x,0);

    }
    sprite.setPosition(position);
    while(sprite.getPosition().x<levelXLimit)
    {
        window.draw(sprite);
        sprite.move(sprite.getTextureRect().width*sprite.getScale().x,0);
    }

}

void Ground::update(sf::Time frameTime, Sir guy)
{
    //Not needed!
}
