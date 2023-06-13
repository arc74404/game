#include "base_object.hpp"

BaseObject::BaseObject(sf::Vector2f _coordinate = sf::Vector2f(0, 0))
{
    size.coordinate = _coordinate;

    shape.setPosition(_coordinate);
}

BaseObject::BaseObject(float x, float y)
    : BaseObject::BaseObject(sf::Vector2f(x, y))
{
}

BaseObject::Type
BaseObject::getType()
{
    return type;
}

void
BaseObject::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void
BaseObject::setRectanglePosition(sf::Vector2f _position)
{
    shape.setPosition(_position);
}