#include "map.hpp"

int Map::count_regions_lenght = 5;

int Map::count_regions_weight = 10;

std::vector<Region> Map::region_array;

Map::Map()
{
    region_array.resize(count_regions_lenght * count_regions_weight, Region());

    for (int i = 0; i < region_array.size(); ++i)
    {

        sf::Vector2i position_on_map;

        position_on_map.x = i % count_regions_lenght;

        position_on_map.y = i / count_regions_lenght;

        region_array[i].setPositionOnMap(position_on_map);

        region_array[i].setTexture("qqw");
    }
}

void
Map::draw(sf::RenderWindow& window)
{
    sf::Vector2f player_position = Player::getPosition();

    sf::Vector2i region_position =
        sf::Vector2i(player_position.x / Region::getSize().x,
                     player_position.y / Region::getSize().y);

    int number_region =
        region_position.y * Map::count_regions_lenght + region_position.x;

    sf::Vector2f displacement_vector =
        player_position - region_array[number_region].getPosition();

    region_array[number_region].setRectanglePosition(
        sf::Vector2f(1500 / 2, 900 / 2) - displacement_vector);

    region_array[number_region].draw(window);
}
