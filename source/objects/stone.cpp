#include "stone.hpp"

Stone::Stone(sf::Vector2f _coordinate) : BaseObject(_coordinate)
{
    health = 500;

    type = BaseObject::Type::STONE;

    size.height = 100;
    size.lenght = 100;
    size.width  = 30;

    shape.setSize(
        sf::Vector2f(size.lenght, size.height));

    if (texture.loadFromFile("C:/Users/arsbo/source/repos/game/bin/pictures/stone.png"))
    {
        shape.setTexture(&texture);
    }
    else
    {
        std::cout << "download error\n";
    }

    // std::cout << "Stone constructor\n";
}
Stone::Stone(float x, float y) : Stone(sf::Vector2f(x, y))
{
}
