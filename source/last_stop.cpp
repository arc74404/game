#include "last_stop.hpp"

LastStop::LastStop() : color(sf::Color::Yellow), radius(20), circle(radius)
{
    circle.setFillColor(sf::Color(0, 0, 0, 0));

    color.a = 0;
    circle.setOutlineThickness(5);
    circle.setOutlineColor(color);
}

void
LastStop::setCoordinate(sf::Vector2f _coordinate)
{
    coordinate = _coordinate;
}

sf::Vector2f
LastStop::getCoordinate()
{
    return coordinate;
}

void
LastStop::draw(sf::RenderWindow& window, sf::Vector2f _coordinate_in_window)
{
    circle.setPosition(
        _coordinate_in_window -
        sf::Vector2f(circle.getRadius() / 2, circle.getRadius() / 2));

    double time = clock.getElapsedTime().asSeconds();

    if (color.a < 5 * time) color.a = 0;
    else color.a -= 5 * time;
    circle.setOutlineColor(color);

    if (radius < 0.2 * time) radius = 0;
    else radius -= 0.2 * time;

    circle.setRadius(radius);
    // std::cout << radius << '\n';

    window.draw(circle);
}

void
LastStop::showCircle()
{
    color.a = 255;
    radius  = 20;

    clock.restart();
}

void
LastStop::hideCircle()
{
    color.a = 0;
}

bool
LastStop::Is_visible()
{
    return color.a > 0;
}