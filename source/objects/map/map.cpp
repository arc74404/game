#include "map.hpp"

int Map::count_regions_lenght = 20;

int Map::count_regions_weight = 10;

std::vector<Region> Map::region_array;

Map::Map()
{
    region_array.resize(count_regions_lenght * count_regions_weight, Region());

    for (int i = 0; i < region_array.size(); ++i)
    {
        region_array[i].createObjects();

        region_array[i].setTexture("");

        region_array[i].setPositionOnMap(sf::Vector2i(
            i % Map::count_regions_lenght, i / Map::count_regions_lenght));

        std::cout << region_array[i].getPositionOnMap().x << " "
                  << region_array[i].getPositionOnMap().y << '\n';
    }
}

int
getNumberRegion(float x, float y)
{
    return y * Map::count_regions_lenght + x;
}

void
Map::draw(sf::RenderWindow& window)
{
    sf::Vector2f centre = {1500 / 2, 900 / 2};

    sf::Vector2f player_position = Player::getPosition();

    sf::Vector2f player_position_window =
        sf::Vector2f(centre.x - Player::getCollisionData().lenght / 2,
                     centre.y + Player::getCollisionData().height / 2 - Player::getCollisionData().width);

    static bool was = false;

    for (int i = -4; i <= 4; ++i)
    {
        for (int j = -3; j <= 2; ++j)
        {
            sf::Vector2i region_position =
                sf::Vector2i(int(player_position.x) / Region::getSize().x + i,
                             int(player_position.y) / Region::getSize().y + j);

            if (region_position.x < 0 || region_position.y < 0 ||
                region_position.x >= Map::count_regions_lenght ||
                region_position.y >= Map::count_regions_weight)
            {
                continue;
            }

            int number_region =
                getNumberRegion(region_position.x, region_position.y);

            sf::Vector2f displacement_vector =
                player_position - region_array[number_region].getPosition();

            sf::Vector2f rectangle_position_region =
                player_position_window - displacement_vector;

            region_array[number_region].setRectanglePosition(
                rectangle_position_region);

            if (!was)
            {
                std::cout << rectangle_position_region.x << " "
                          << rectangle_position_region.y << '\n';
            }

            region_array[number_region].draw(window);
        }
    }
    was = true;
}
