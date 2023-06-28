#include "object_rect_data.hpp"

RectData::RectData(sf::Vector2f _coordinate, float _lenght, float _width,
                   float _height)
    : coordinate(_coordinate), lenght(_lenght), width(_width), height(_height)
{
}

RectData::RectData() : RectData(sf::Vector2f(0, 0), 0, 0, 0)
{
}