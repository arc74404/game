#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "object_rect_data.hpp"

class Player
{
private:
    static float health;

    static sf::RectangleShape shape;

    static sf::Texture texture;

public:

    static const RectData size;
    
    friend sf::RectangleShape setShapeParametrs();

    static void draw(sf::RenderWindow& window);

    static sf::Vector2f getPosition();
};
#endif // PLAYER_HPP