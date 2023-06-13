#include "player.hpp"

float Player::health = 200;

const RectData Player::size = RectData(sf::Vector2f(0, 0), 30, 60, 100);

sf::RectangleShape
setShapeParametrs();

sf::RectangleShape Player::shape = setShapeParametrs();

sf::RectangleShape
setShapeParametrs()
{
    sf::RectangleShape shape;

    shape.setPosition(1500 / 2 - Player::size.lenght / 2,
                      900 / 2 - Player::size.height / 2);

    shape.setSize(sf::Vector2f(Player::size.lenght, Player::size.height));

    shape.setFillColor(sf::Color::Red);
    return shape;
}

sf::Texture Player::texture;

void
Player::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f
Player::getPosition()
{
    return size.coordinate;
}
