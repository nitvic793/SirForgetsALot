#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>

class Game
{
    sf::RenderWindow Window;
    sf::Event Event;
public:
    Game() : Window(sf::VideoMode(1366,768),"Sir ForgetsaLot")
    {

    }
    void run();
};
#endif // GAME_H_INCLUDED
