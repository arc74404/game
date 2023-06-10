#include "map.hpp"

int Map::count_regions_lenght = 5;

int Map::count_regions_weight = 10;

std::vector<Region> Map::region_array;

Map Map::map = Map();

Map::Map()
{
    region_array.resize(count_regions_lenght * count_regions_weight);

    for (int i = 0; i < region_array.size(); ++i)
    {
        sf::Vector2i position_on_map;

        position_on_map.x = i % count_regions_lenght;

        position_on_map.y = i / count_regions_lenght;

        region_array[i].setPositionOnMap(position_on_map);

        region_array[i].createObjects();
    }
}

void
Map::draw(sf::RenderWindow& window)
{
    region_array[0].draw(window);
}
