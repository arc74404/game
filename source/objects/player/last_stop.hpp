#ifndef LAST_STOP_HPP
#define LAST_STOP_HPP

#include <SFML/Graphics.hpp>

class LastStop
{
private:
    sf::CircleShape circle;

    sf::Color color;

    sf::Vector2f coordinate;

    sf::Clock clock;

    float radius;

public:
    LastStop();

    void setCoordinate(sf::Vector2f _coordinate);

    sf::Vector2f getCoordinate();

    void draw(sf::RenderWindow& window, sf::Vector2f _coordinate_in_window);

    void showCircle();

    void hideCircle();

    bool Is_visible();
};
#endif // LAST_STOP_HPP
