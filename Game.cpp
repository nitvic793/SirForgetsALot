#include "Game.h"
#include <SFML/System.hpp>
#include "AnimatedSprite.hpp"
#include "Stage.h"
#include "Background.h"
#include "Sir.h"
#include "Level.h"
//#include "ResourceManager.h"
void Game::run()
{
    //Basic Animation
    sf::Texture texture;
    texture.loadFromFile("images/test.png");
    Window.setFramerateLimit(60);
    Window.setVerticalSyncEnabled(true);
    Sir guy;
    Background bg;
    sf::Sprite test;
    test.setTexture(guy.getTexture());
        //AnimatedSprite animSprite(sf::seconds(0.2),true,false);
    sf::Clock frameClock;
    Level newLevel;

    while(Window.isOpen())
    {
        while(Window.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
                Window.close();
            if(Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape)
                Window.close();
        }
        sf::Time frameTime = frameClock.restart();
//        GStage.update(frameTime.asSeconds());
       // guy.update(frameTime);
        newLevel.update(frameTime);

       // bg.update(0.02f);
        /*animSprite.play(testAnim);
        animSprite.move(sf::Vector2f(0.1,0.1f)*frameTime.asSeconds());
        animSprite.update(frameTime);*/
        Window.clear(sf::Color(135,206,255));
        //Window.draw(guy.getShadow());
        //Window.draw(guy.getSprite());
        newLevel.drawLevel(Window);
        //Window.draw(test);
        //Window.draw(spt);
       // GStage.draw(Window);
        //Window.draw(bg.getSprite());
       // Window.draw(animSprite);
        Window.display();

    }
}
