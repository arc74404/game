#include "map.hpp"

int Map::count_regions_lenght = 10;

int Map::count_regions_width = 5;

std::vector<Region> Map::region_array;

void
Map::createMap()
{
    region_array.resize(count_regions_lenght * count_regions_width, Region());

    for (int i = 0; i < region_array.size(); ++i)
    {

        region_array[i].setTexture("");

        region_array[i].setPositionOnMap(sf::Vector2i(
            i % Map::count_regions_lenght, i / Map::count_regions_lenght));
    }
}

int
getNumberRegion(int x, int y)
{
    return y * Map::count_regions_lenght + x;
}

void
Map::draw(sf::RenderWindow& window)
{
    sf::Vector2f centre = DataBase::Centre();

    sf::Vector2f player_position = Player::getCollisionData().coordinate;

    sf::Vector2f player_position_window =
        sf::Vector2f(centre.x - Player::getCollisionData().lenght / 2,
                     centre.y + Player::getCollisionData().height / 2 -
                         Player::getCollisionData().width);

    static bool was = false;

    for (int i = -2; i <= 2; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            sf::Vector2i region_position =
                sf::Vector2i(int(player_position.x) / Region::getSize().x + i,
                             int(player_position.y) / Region::getSize().y + j);

            int number_region =
                getNumberRegion(region_position.x, region_position.y);

            if (number_region < 0 || number_region >= region_array.size())
                continue;

            sf::Vector2f displacement_vector =
                player_position - region_array[number_region].getPosition();

            sf::Vector2f rectangle_position_region =
                player_position_window - displacement_vector;

            region_array[number_region].setRectanglePosition(
                rectangle_position_region);

            region_array[number_region].drawBase(window);
        }
    }
    for (int i = -2; i <= 2; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            sf::Vector2i region_position =
                sf::Vector2i(int(player_position.x) / Region::getSize().x + i,
                             int(player_position.y) / Region::getSize().y + j);

            int number_region =
                getNumberRegion(region_position.x, region_position.y);

            std::cout << number_region << '\n';

            if (number_region < 0 || number_region >= region_array.size())
                continue;

            sf::Vector2f displacement_vector =
                player_position - region_array[number_region].getPosition();

            sf::Vector2f rectangle_position_region =
                player_position_window - displacement_vector;

            region_array[number_region].drawObjects(window);

            std::cout << number_region << ": "
                      << region_array[number_region].getCountObjects() << '\n';
        }
    }
    was = true;
}

sf::Vector2i
Map::getSize()
{
    return sf::Vector2i(count_regions_lenght, count_regions_width);
}

void
Map::addObject(int number_region, std::shared_ptr<BaseObject> object)
{
    region_array[number_region].addObject(object);
}
