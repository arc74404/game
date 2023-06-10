#include "stone.hpp"

Stone::Stone(sf::Vector2f _coordinate) : BaseObject(_coordinate)
{
    health = 500;

    type = BaseObject::Type::STONE;

    rectangle_parametrs.height = 100;
    rectangle_parametrs.lenght = 100;
    rectangle_parametrs.width  = 30;

    shape.setSize(
        sf::Vector2f(rectangle_parametrs.lenght, rectangle_parametrs.height));

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
