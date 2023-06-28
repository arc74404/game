#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

#include "C:/Users/arsbo/source/repos/game/source/objects/map/object_rect_data.hpp"

#include "last_stop.hpp"

#include "texture_rect_data.hpp"

class TextureRectData;

class Player
{
private:
    enum class Status
    {
        STAY_R = 0,
        STAY_L = 1,
        RUN_R  = 2,
        RUN_L  = 3
    };

    static TextureRectData texture_rect_data;

    static float health;

    static RectData collision_data;

    static sf::RectangleShape shape;

    static sf::Texture texture;

    static LastStop last_stop;

    static sf::Vector2f middle_of_base;

    static Status status;

    static bool is_new_position;

    static bool is_first_show;

public:
    static Player player;

    Player();

    friend void setShapeParametrs();

    friend void updateMiddleBase();

    friend class TextureRectData;

    static void draw(sf::RenderWindow& window);

    static sf::Vector2f getPosition();

    static void changePosition(sf::Vector2i mouse_position);

    static void move(float time);

    static bool Is_moving();

    static RectData getCollisionData();
};
#endif // PLAYER_HPP