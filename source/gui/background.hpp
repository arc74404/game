#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

class Background
{
private:
    static sf::Texture space_texture;

    static sf::Sprite space_sprite;

    static Background background;

    static std::vector<sf::Sprite> back_additions;

public:
    Background();

    static void draw(sf::RenderWindow& window);

    static void setBoard(float xx, float yy);
};

#endif // BACKGROUND_HPP