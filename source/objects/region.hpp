#ifndef REGION_HPP
#define REGION_HPP


#include "base_object.hpp"
#include "stone.hpp"

class Region
{
private:
    sf::Vector2f position;

    sf::Vector2i position_on_map;

    static const sf::Vector2f size;

    std::vector<std::shared_ptr<BaseObject>> object_array;
    
    sf::Texture surface_texture;

    sf::RectangleShape surface;

    void createObjects();

public:

    Region(sf::Vector2i _position_on_map);

    Region(int x, int y);

    Region();

    sf::Vector2f getPosition() const;

    sf::Vector2i getPositionOnMap() const;

    void setPositionOnMap(sf::Vector2i _position_on_map);

    void setRectanglePosition(sf::Vector2f _position);

    void setTexture(std::string s);

    static sf::Vector2f getSize();

    void draw(sf::RenderWindow& window);
};

#endif // REGION_HPP