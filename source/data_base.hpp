#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP

#include <SFML/Graphics.hpp>

#include "object_rect_data.hpp"

class DataBase
{
private:
    static sf::Vector2f window_size;

    static sf::Vector2f centre;

    static RectData player_rect_data;

public:
    static void createDataBase();

    static sf::Vector2f WindowSize();

    static sf::Vector2f Centre();

    static RectData PlayerRectData();
};

#endif // DATA_BASE_HPP