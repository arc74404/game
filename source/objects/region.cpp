#include "region.hpp"

const sf::Vector2f Region::size = {828 / 2, 755 / 2};

sf::Vector2f
Region::getSize()
{
    return size;
}

Region::Region(sf::Vector2i _position_on_map)
{
    setPositionOnMap(_position_on_map);

    surface.setSize(size);

    createObjects();
}

Region::Region(int x, int y) : Region(sf::Vector2i(x, y))
{
}

Region::Region() : Region(0, 0)
{
}

void
Region::setPositionOnMap(sf::Vector2i _position_on_map)
{

    position_on_map = _position_on_map;

    position.x = position_on_map.x * size.x;

    position.y = position_on_map.y * size.y;
}

sf::Vector2f
Region::getPosition() const
{
    return position;
}

sf::Vector2i
Region::getPositionOnMap() const
{
    return position_on_map;
}

void
Region::createObjects()
{
    object_array.resize(4, nullptr);

    for (int i = 0; i < object_array.size(); ++i)
    {
        object_array[i] =
            std::make_shared<Stone>(rand() % 4 * 100, rand() % 4 * 100);
    }
}

void
Region::draw(sf::RenderWindow& window)
{
    window.draw(surface);

    for (int i = 0; i < object_array.size(); ++i)
    {
        object_array[i]->draw(window);
    }
}

void
Region::setTexture(std::string s)
{
    if (surface_texture.loadFromFile(
            "C:/Users/arsbo/source/repos/game/bin/pictures/grass.jpg"))
    {
        surface.setTexture(&surface_texture);
    }
    else
    {
        std::cout << "ERROR WITH TEXTURE\n";
    }
}

void
Region::setRectanglePosition(sf::Vector2f _position)
{
    surface.setPosition(_position);

    for (int i = 0; i < object_array.size(); ++i)
    {
        object_array[i]->setRectanglePosition(_position);
    }
}