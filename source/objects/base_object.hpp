#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "object_rect_data.hpp"

#include <iostream>

class BaseObject
{
protected:
    enum class Type;

    Type type;

    float health;//прочность или здоровье

    RectData rectangle_parametrs;

    sf::Texture texture;

    sf::RectangleShape shape;

public:
    BaseObject(sf::Vector2f _coordinates);

    BaseObject(float x, float y);

    enum class Type
    {
        STONE = 0, // комень
        TREE = 1, // дерево
        BUSH = 2  // куст
    };

    void draw(sf::RenderWindow& window);

    Type getType();
};

#endif // BASE_OBJECT_HPP