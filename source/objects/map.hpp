#ifndef MAP_HPP
#define MAP_HPP

#include "base_object.hpp"

#include "region.hpp"

class Map
{
private:

    static std::vector<Region> region_array;

    static int count_regions_lenght;

    static int count_regions_weight;

public:
    static void draw(sf::RenderWindow& window);

    static Map map;

    Map();
};

#endif // MAP_HPP