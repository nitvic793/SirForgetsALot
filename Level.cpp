#include "Level.h"
#include "Settings.h"
Level::Level() : initCharacterPosition(DEFAULT_X,DEFAULT_Y)
{
    isDone = false;
    guy.setPosition(initCharacterPosition);
    txtBGParallax.loadFromFile("images/bg.png");
    endTexture.loadFromFile("images/finish.png");
    endSprite.setTexture(endTexture);
    bgParallax.setTexture(txtBGParallax);
    CannonList.push_back(new Cannon());
    CannonList.push_back(new Cannon(sf::Vector2f(900.f,290.f)));
    PlatformList.push_back(new Platform(sf::Vector2f(400.f,350.f),200.f));
    PlatformList.push_back(new Platform(sf::Vector2f(800.f,350.f),200.f));
    PlatformList.push_back(new Platform(sf::Vector2f(1900.f,350.f),200.f));
    PlatformList.push_back(new Platform(sf::Vector2f(2100.f,300.f),200.f));
    PlatformList.push_back(new Platform(sf::Vector2f(2300.f,200.f),500.f));
    CannonList.push_back(new Cannon(sf::Vector2f(2500.f,150.f)));
    PlatformList.push_back(new Platform(sf::Vector2f(2900.f,350.f),200.f));
    CannonList.push_back(new Cannon(sf::Vector2f(3000.f,450.f)));
    CannonList.push_back(new Cannon(sf::Vector2f(3500.f,450.f)));
     PlatformList.push_back(new Platform(sf::Vector2f(3500.f,350.f),200.f));
     CannonList.push_back(new Cannon(sf::Vector2f(3600.f,290.f)));
     PlatformList.push_back(new Platform(sf::Vector2f(3250.f,320.f),200.f));
     endSprite.setPosition(4000.f,260.f);
     sf::Font font;
     //font.loadFromFile("arial.ttf");

    //Text.setPosition(10.f,10.f);
    //Text.setColor(sf::Color::Red);
    //Text.setScale(3.f,3.f);
    //Text.setCharacterSize(10);


}

void Level::drawLevel(sf::RenderTarget& window)
{
    sf::View player_view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    player_view.setCenter(guy.getSprite().getPosition().x+150.f,guy.getSprite().getPosition().y);
    window.setView(player_view);
    bgParallax.draw(window);
    bg.draw(window);
    ground.draw(window);
    //#pragma omp parallel
    for(std::vector<Cannon*>::iterator it = CannonList.begin(); it!=CannonList.end(); ++it)
    {
        if(guy.getPosition().x<(*it)->getPosition().x)
        {
            if(guy.getPosition().x+800>(*it)->getPosition().x)
                (*it)->draw(window);
        }
        else if(guy.getPosition().x-500<(*it)->getPosition().x)
            (*it)->draw(window);

    }
    for(std::vector<Platform*>::iterator it = PlatformList.begin(); it!=PlatformList.end(); ++it)
    {
        (*it)->draw(window);
    }
   // #pragma omp parallel
   if(!isDone)
    for(std::vector<CannonBall*>::iterator it = CannonBallList.begin(); it!=CannonBallList.end(); ++it)
    {
        if(!(*it)->isClearable())
        (*it)->draw(window);
    }
   // window.draw(guy.getShadow());
   endSprite.setScale(0.6f,0.6f);
   window.draw(endSprite);
    window.draw(guy.getSprite());
    window.draw(Text);
}

void Level::update(sf::Time frameTime)
{
    string test = "" + guy.getHealth();
    Text.setString(test);
    if(guy.getHealth()<=0)isDone = true;
    if(guy.getPosition().x-240.f>endSprite.getPosition().x)
        isDone = true;
    if(!isDone)
    {
        guy.update(frameTime,PlatformList);
        bg.update(frameTime.asSeconds(),BGSPEED);
        bgParallax.update(frameTime.asSeconds(),BGSPEED-40.f);

        for(std::vector<Cannon*>::iterator it = CannonList.begin(); it!=CannonList.end(); ++it)
        {
            if(guy.getPosition().x<(*it)->getPosition().x)
            {
                if(guy.getPosition().x+800>(*it)->getPosition().x)
                    (*it)->update(CannonBallList,guy);
            }
            else if(guy.getPosition().x-20<(*it)->getPosition().x)
                (*it)->update(CannonBallList,guy);
            /*if(guy.getPosition().x+800>(*it)->getPosition().x)
            (*it)->update(CannonBallList,guy);*/
        }
        for(std::vector<CannonBall*>::iterator it = CannonBallList.begin(); it!=CannonBallList.end(); ++it)
        {
            if(!(*it)->isClearable())
                (*it)->update(guy,frameTime);
        }
    }

}
