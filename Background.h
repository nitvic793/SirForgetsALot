#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

class Background
{
    float speed,Yvel,inY;
    sf::Texture Texture;
    sf::Sprite Sprite;
    sf::Vector2f Position;
    bool isJumping;
    float jumpSpeed;
public:
    Background();
    void update(float deltaTime, float bgMoveSpeed);
    void setTexture(sf::Texture& tex);
    void setPosition(sf::Vector2f pos);
    sf::Sprite& getSprite()
    {
        return Sprite;
    }
    void draw(sf::RenderTarget& window);
};
#endif // BACKGROUND_H_INCLUDED
