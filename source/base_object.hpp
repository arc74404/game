#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

#include "object_rect_data.hpp"

class BaseObject
{
protected:

    enum class Type;

    Type type;

    float health; // прочность или здоровье

    RectData collision_data;

    static sf::Texture texture;

    sf::RectangleShape shape;

public:
    static int count;

    BaseObject(sf::Vector2f _coordinates);

    BaseObject(float x, float y);

    enum class Type
    {
        STONE = 0, // комень
        TREE  = 1, // дерево
        BUSH  = 2  // куст
    };

    void draw(sf::RenderWindow& window);

    Type getType();

    void setRectanglePosition(sf::Vector2f _position);

    sf::Vector2f getPosition();
};

#endif // BASE_OBJECT_HPP