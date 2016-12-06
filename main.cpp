#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Game *gInstance = new Game();
    gInstance->run();
    delete gInstance;
    return 0;
}
