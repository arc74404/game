#include "background.hpp"

sf::Sprite Background::space_sprite;

sf::Texture Background::space_texture;

Background Background::background;

std::vector<sf::Sprite> Background::back_additions;

Background::Background()
{
    if (space_texture.loadFromFile(
            "C:/Users/arsbo/source/repos/game/bin/pictures/cosmos.png"))
    {
        space_sprite.setTexture(space_texture);
    }
    else
    {
        space_sprite.setColor(sf::Color::Red);
    }
}

void
Background::draw(sf::RenderWindow& window)
{
    window.draw(space_sprite);

    for (int i = 0; i < back_additions.size(); ++i)
    {
        window.draw(back_additions[i]);
    }
}

void
Background::setBoard(float xx, float yy)
{
    sf::Vector2f sprite_size =
        sf::Vector2f(space_sprite.getGlobalBounds().width,
                     space_sprite.getGlobalBounds().height);

    space_sprite.setScale(xx / sprite_size.x, yy / sprite_size.y);
}
