#ifndef STONE_HPP
#define STONE_HPP

#include "base_object.hpp"

class Stone : public BaseObject
{
private:
public:
    Stone(sf::Vector2f _coordinate);

    Stone(float x, float y);
};

#endif // STONE_HPP