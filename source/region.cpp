#include "region.hpp"

sf::Vector2f Region::size = {500, 500};

sf::Vector2f
Region::getSize()
{
    return size;
}

Region::Region(sf::Vector2i _position_on_map)
{
    setPositionOnMap(_position_on_map);

    surface.setSize(size);
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
Region::drawBase(sf::RenderWindow& window)
{
    surface.setOutlineThickness(3);
    surface.setOutlineColor(sf::Color::Green);
    window.draw(surface);
}
void
Region::drawObjects(sf::RenderWindow& window)
{
    for (int i = 0; i < object_array.size(); ++i)
    {
        object_array[i]->draw(window);
    }
}

void
Region::setTexture(std::string s)
{
    if (surface_texture.loadFromFile(
            "C:/Users/arsbo/source/repos/game/bin/pictures/floor.png"))
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
        object_array[i]->setRectanglePosition(object_array[i]->getPosition() -
                                              position + _position);
    }
}

void
Region::addObject(std::shared_ptr<BaseObject> object)
{
    object_array.emplace_back(object);
}

int
Region::getCountObjects()
{
    return object_array.size();
}