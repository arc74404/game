#include "player.hpp"

TextureRectData Player::texture_rect_data;

float Player::health;

Player::Status Player::status;

bool Player::is_first_show;

bool Player::is_new_position;

RectData Player::collision_data;

sf::Texture Player::texture;

sf::Vector2f Player::middle_of_base;

LastStop Player::last_stop;

sf::RectangleShape Player::shape;

Player Player::player;

void
updateMiddleBase()
{
    float center_offset_multiplier = 1;

    if (Player::status == Player::Status::RUN_R ||
        Player::status == Player::Status::STAY_R)
    {
        center_offset_multiplier = 0.2;
    }
    else if (Player::status == Player::Status::RUN_L ||
             Player::status == Player::Status::STAY_L)
    {
        center_offset_multiplier = 0.6;
    }

    Player::middle_of_base = sf::Vector2f(
        Player::collision_data.coordinate.x +
            Player::collision_data.lenght * center_offset_multiplier,
        Player::collision_data.coordinate.y + Player::collision_data.width);
}

void
setShapeParametrs()
{

    Player::shape.setPosition(1500 / 2 - Player::collision_data.lenght / 2,
                              900 / 2 - Player::collision_data.height / 2);

    Player::shape.setSize(sf::Vector2f(Player::collision_data.lenght,
                                       Player::collision_data.height));

    Player::texture.loadFromFile(
        "C:/Users/arsbo/source/repos/game/bin/pictures/player.png");

    Player::shape.setTexture(&Player::texture);

    // Player::shape.setOutlineThickness(5);

    // Player::shape.setOutlineColor(sf::Color::Red);
}

Player::Player()
{
    collision_data  = RectData(sf::Vector2f(0, 0), 100, 30, 200);
    health          = 200;
    status          = Status::STAY_R;
    is_first_show   = false;
    is_new_position = false;

    setShapeParametrs();
    updateMiddleBase();
}


void
Player::draw(sf::RenderWindow& window)
{
    updateMiddleBase();

    sf::Vector2f centre_in_window =
        sf::Vector2f(window.getSize().x * 0.5, window.getSize().y * 0.5);

    sf::Vector2f centre_on_map =
        sf::Vector2f(collision_data.coordinate.x + collision_data.lenght / 2,
                     collision_data.coordinate.y + collision_data.width -
                         collision_data.height / 2);

    sf::Vector2f stop_coordinate_in_window =
        centre_in_window + last_stop.getCoordinate() - centre_on_map;

    shape.setTextureRect(texture_rect_data.getTextureRect());

    if (last_stop.Is_visible())
    {
        last_stop.draw(window, stop_coordinate_in_window);
    }
    window.draw(shape);
}

sf::Vector2f
Player::getPosition()
{
    return collision_data.coordinate;
}

void
Player::changePosition(sf::Vector2i mouse_position)
{

    sf::Vector2f player_coordinate_shape = {
        1500 / 2 - collision_data.lenght / 2,
        900 / 2 + collision_data.height / 2 - collision_data.width};

    last_stop.setCoordinate(collision_data.coordinate +
                            sf::Vector2f(mouse_position.x, mouse_position.y) -
                            player_coordinate_shape);

    if (last_stop.getCoordinate().x < middle_of_base.x) status = Status::RUN_L;
    else status = Status::RUN_R;

    is_new_position = true;

    is_first_show = true;

    last_stop.hideCircle();

    std::cout << "hide\n";
}

void
Player::move(float time)
{
    updateMiddleBase();

    if (!is_new_position && is_first_show)
    {
        last_stop.showCircle();
        is_first_show = false;

        std::cout << "show\n";
    }
    is_new_position = false;

    sf::Vector2f stop_coordinate = last_stop.getCoordinate();

    sf::Vector2f A = stop_coordinate - middle_of_base;

    sf::Vector2f mover;

    if (A.x == 0)
    {
        mover.x = 0.001;
    }
    else
    {
        mover.x = 1 * 300 / sqrt((A.y * A.y) / (A.x * A.x) + 1);
        mover.y = A.y / A.x * mover.x;
    }

    mover *= time;

    if (A.x < 0)
    {
        mover.x *= -1;
        mover.y *= -1;
    }

    collision_data.coordinate += mover;

    float radius_zone = 2.5;

    if (stop_coordinate.x >= middle_of_base.x - radius_zone &&
        stop_coordinate.x <= middle_of_base.x + radius_zone &&
        stop_coordinate.y <= middle_of_base.y + radius_zone &&
        stop_coordinate.y >= middle_of_base.y - radius_zone)
    {
        if (status == Status::RUN_R) status = Status::STAY_R;
        else if (status == Status::RUN_L) status = Status::STAY_L;
    }
}

bool
Player::Is_moving()
{
    return status == Status::RUN_R || status == Status::RUN_L;
}

RectData
Player::getCollisionData()
{
    return collision_data;
}
