#ifndef RECT_DATA_HPP
#define RECT_DATA_HPP

#include <SFML/Graphics.hpp>

struct RectData
{
public:

    float width;             // ширина

    float lenght;            // длина

    float height;            // высота

    sf::Vector2f coordinate; // координата

    RectData(sf::Vector2f _coordinate, float _lenght, float _width, float _height);

    RectData();
};

#endif // RECT_DATA_HPP