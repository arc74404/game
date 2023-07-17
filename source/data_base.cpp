#include "data_base.hpp"

sf::Vector2f DataBase::window_size;
sf::Vector2f DataBase::centre;

RectData DataBase::player_rect_data;

void
DataBase::createDataBase()
{
    window_size = sf::Vector2f(1500, 900);

    centre.x = window_size.x / 2;
    centre.y = window_size.y / 2;

    player_rect_data.coordinate = sf::Vector2f(0, 0);
    player_rect_data.height     = window_size.y * 0.25;
    player_rect_data.lenght     = player_rect_data.height * 0.6;
    player_rect_data.width      = player_rect_data.height * 0.3;
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

RectData
DataBase::PlayerRectData()
{
    return player_rect_data;
}