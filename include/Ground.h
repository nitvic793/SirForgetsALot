#ifndef GROUND_H
#define GROUND_H

#include "../Sir.h"

class Ground
{
    public:
        Ground();
        virtual ~Ground();
        sf::Texture &GetgroundTexture() { return groundTexture; }
        void SetgroundTexture(const sf::Texture &val) { groundTexture = val; }
        sf::Sprite &Getsprite() { return sprite; }
        void Setsprite(const sf::Sprite &val) { sprite = val; }
        void update(sf::Time frameTime,Sir guy);
        void draw(sf::RenderTarget& window);
        void setPosition(sf::Vector2f pos){position = pos;};
    protected:
    private:
        sf::Texture groundTexture;
        sf::Texture mudTexture;
        sf::Sprite sprite;
        sf::Sprite mudSprite;
        sf::Vector2f position;
        sf::Vector2f mudPosition;
        float levelXLimit;
};

#endif // GROUND_H
