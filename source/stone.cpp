#include "stone.hpp"

Stone Stone::standart_stone(0, 0);

Stone::Stone(sf::Vector2f _coordinate) : BaseObject(_coordinate)
{
    health = 500;

    type = BaseObject::Type::STONE;

    collision_data.height = 100;
    collision_data.lenght = 100;
    collision_data.width  = 30;

    shape.setSize(sf::Vector2f(collision_data.lenght, collision_data.height));

    if (texture.loadFromFile(
            "C:/Users/arsbo/source/repos/game/bin/pictures/stone.png"))
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

sf::RectangleShape
Stone::getBorder()
{
    sf::RectangleShape _shape = standart_stone.shape;

    _shape.setFillColor(sf::Color(0, 0, 0, 0));
    _shape.setOutlineThickness(5);
    _shape.setOutlineColor(sf::Color::Green);

    return _shape;
}