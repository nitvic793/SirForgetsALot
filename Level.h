#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Background.h"
#include <SFML/Graphics.hpp>
#include "Sir.h"
#include "include/Ground.h"
#include "Cannon.h"
#include "CannonBall.h"
#include "Platform.h"
#include <vector>
using namespace std;
const float DEFAULT_X = 250.f;
const float DEFAULT_Y = 400.f;

class Level
{
    float xLimit;
    Background bg;
    Background bgParallax;
    sf::Texture txtBGParallax;
    sf::Vector2f initCharacterPosition;
    Sir guy;
    Ground ground;
    vector<Cannon*> CannonList;
    vector<CannonBall*> CannonBallList;
    vector<Platform*> PlatformList;
    bool isDone;
    sf::Sprite endSprite;
    sf::Texture endTexture;
    sf::Text Text;
public :
    Level();
    void drawLevel(sf::RenderTarget&);
    void update(sf::Time frameTime);

};
#endif // LEVEL_H_INCLUDED
