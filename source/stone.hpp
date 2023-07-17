#ifndef STONE_HPP
#define STONE_HPP

#include "base_object.hpp"

class Stone : public BaseObject
{
private:

    static Stone standart_stone;

public:
    Stone(sf::Vector2f _coordinate);

    Stone(float x, float y);

    static sf::RectangleShape getBorder();
};

#endif // STONE_HPP