#include "Platform.h"

Platform::Platform(sf::Vector2f Pos, float len)
{
    Position = Pos;
    Length = len;
    Texture.loadFromFile("images/plat2.png");
    Sprite.setTexture(Texture);
    Sprite.setPosition(Position);
}

void Platform::draw(sf::RenderTarget &window)
{
    Sprite.setPosition(Position);
    while(Sprite.getPosition().x< Position.x + Length)
    {
        window.draw(Sprite);
        Sprite.move(Sprite.getTextureRect().width,0);
    }
}

void Platform::update()
{
//Not needed
}
