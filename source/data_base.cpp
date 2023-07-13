#include "data_base.hpp"

sf::Vector2f DataBase::window_size;
sf::Vector2f DataBase::centre;

void
DataBase::createDataBase()
{
    window_size = sf::Vector2f(1500, 900);

    centre.x = window_size.x / 2;
    centre.y = window_size.y / 2;
}

sf::Vector2f
DataBase::WindowSize()
{
    return window_size;
}

sf::Vector2f
DataBase::Centre()
{
    return centre;
}