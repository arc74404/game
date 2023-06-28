#ifndef MAP_HPP
#define MAP_HPP

#include "base_object.hpp"

#include "region.hpp"

#include "C:/Users/arsbo/source/repos/game/source/objects/player/player.hpp"

class Map
{
private:

    static std::vector<Region> region_array;

    static int count_regions_lenght;

    static int count_regions_weight;

public:
    friend int getNumberRegion(float x, float y);

    static void draw(sf::RenderWindow& window);

    Map();
};

#endif // MAP_HPP