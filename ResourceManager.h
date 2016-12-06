#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>
using namespace std;

class ResourceManager
{

    //static map<string,sf::Texture> Audio;
public:
    map<string,sf::Texture> Image;
    void loadImages();
    void loadAudio();
    sf::Texture& getImage(string name);
};

#endif // RESOURCEMANAGER_H_
