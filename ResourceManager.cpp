#include "ResourceManager.h"

void ResourceManager::loadImages()
    {
        Image["stage1/c1"].loadFromFile("images/c1.png");
        Image["stage1/c2"].loadFromFile("images/c2.png");
    }
void ResourceManager::loadAudio()
    {

    }
sf::Texture& ResourceManager::getImage(string name)
    {
        return Image[name];
    }
