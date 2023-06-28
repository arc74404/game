#ifndef TEXTURE_RECT_DATA_HPP
#define TEXTURE_RECT_DATA_HPP

#include <SFML/Graphics.hpp>

#include "player.hpp"

class TextureRectData
{
private:
    sf::IntRect texture_rect;

    std::vector<sf::IntRect> patterns;

    int number_of_pattern;

    sf::Clock clock;

    float time;

public:

    TextureRectData();

    sf::IntRect getTextureRect();
};

#endif // TEXTURE_RECT_DATA_HPP