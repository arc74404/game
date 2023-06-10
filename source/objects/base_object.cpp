#include "base_object.hpp"

BaseObject::BaseObject(sf::Vector2f _coordinate = sf::Vector2f(0, 0))
{
    rectangle_parametrs.coordinate = _coordinate;

    shape.setPosition(_coordinate);
}

BaseObject::BaseObject(float x, float y)
    : BaseObject::BaseObject(sf::Vector2f(x, y))
{
}

BaseObject::Type BaseObject::getType()
{
    return type;
}

void BaseObject::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}