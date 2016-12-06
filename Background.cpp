#include "Background.h"
#include "Settings.h"
#include <cstdlib>
#include "ResourceManager.h"
#include <iostream>

using namespace std;

Background::Background()
{
    Texture.loadFromFile("images/mountain.png");
    Sprite.setTexture(Texture);
    Position.x = -400.f;
    Position.y = -200.f;
    Sprite.setPosition(Position);
    isJumping = false;
    jumpSpeed = -40.f;

}

void Background::update(float deltaTime, float bgMoveSpeed)
{
    if(isJumping)
    {
        Yvel = Yvel+GRAVITY;
        if(Yvel>=-jumpSpeed)
        {
            Position = (sf::Vector2f(Position.x,inY));
            isJumping = false;
        }
        else
        {
            Position = (sf::Vector2f(Position.x, Position.y+ Yvel));

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Position.x += bgMoveSpeed*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Position.x -=bgMoveSpeed*deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
       /* if(!isJumping)
        {
            isJumping = true;
            Yvel = jumpSpeed;
            inY = Position.y;
        }*/

    }
    Sprite.setPosition(Position);
}

void Background::draw(sf::RenderTarget& window)
{
    //cout<<window.getView().getCenter().x<<" "<<window.getView().getSize().x;
    //system("cls");
    while(Sprite.getPosition().x<window.getView().getCenter().x + window.getView().getSize().x)
    {
        window.draw(Sprite);
        Sprite.move(Sprite.getTextureRect().width,0);
    }

}

void Background::setTexture(sf::Texture &tex)
{
    Sprite.setTexture(tex);
}

void Background::setPosition(sf::Vector2f pos)
{
    Position = pos;
    Sprite.setPosition(Position);
}
