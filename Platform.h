#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED
#include <SFML/Graphics.hpp>
class Platform
{
    sf::Texture Texture;
    sf::Sprite Sprite;
    sf::Vector2f Position;
    float Length;
public :
    Platform(sf::Vector2f pos,float len);
    void draw(sf::RenderTarget &window);
    void update();
    sf::Vector2f getPosition(){return Position;}
    float getLength(){return Length;}
    float getHeight(){return Sprite.getTextureRect().height;}
};

#endif // PLATFORM_H_INCLUDED
