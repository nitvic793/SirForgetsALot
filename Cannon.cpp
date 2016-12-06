#include "Cannon.h"
sf::Texture Cannon::Texture;
int Cannon::count = 0;
Cannon::Cannon()
{
    if(count==0)
    Texture.loadFromFile("images/cannon.png");
    count++;
    Sprite.setTexture(Texture);
    Position = sf::Vector2f(2000.f,450.f);
    Clock.restart();
}

Cannon::Cannon(sf::Vector2f pos)
{
    if(count==0)
    Texture.loadFromFile("images/cannon.png");
    count++;
    Sprite.setTexture(Texture);
    Position = pos;
    Clock.restart();
}

void Cannon::draw(sf::RenderTarget& window)
{
    window.draw(Sprite);
}

void Cannon::update(vector<CannonBall*> &cBallList, Sir guy)
{
    Sprite.setPosition(Position);
    if(guy.getPosition().x<Position.x && guy.getPosition().x + 700 >= Position.x && Clock.getElapsedTime().asSeconds()>2.f)
    {
        cBallList.push_back(new CannonBall(Position));
        Clock.restart();
    }
}
