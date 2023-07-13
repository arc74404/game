#ifndef MAP_HPP
#define MAP_HPP

#include "base_object.hpp"
#include "data_base.hpp"
#include "player.hpp"
#include "region.hpp"

class Map
{
    friend int getNumberRegion(int x, int y);

private:
    static std::vector<Region> region_array;

    static int count_regions_lenght;

    static int count_regions_width;

public:
    static void addObject(int number_region, std::shared_ptr<BaseObject> object);

    static void draw(sf::RenderWindow& window);

    static void createMap();

    static sf::Vector2i getSize();
};

#endif // MAP_HPP