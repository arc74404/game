#include "m_button.hpp"

sf::Texture mButton::texture;

std::map<std::string, sf::IntRect> mButton::patterns = {
    {"new game",   sf::IntRect(46, 44,  150, 74)},
    {"restore",    sf::IntRect(46, 142, 150, 74)},
    {"settings",   sf::IntRect(46, 234, 150, 74)},
    {"close game", sf::IntRect(46, 330, 150, 74)}
};

void
mButton::setTexture(std::string name_file)
{
    texture.loadFromFile(
        "C:/Users/arsbo/source/repos/game/bin/pictures/main_menu.png");
}

mButton::mButton() : mButton(sf::Vector2f(0, 0))
{
}

mButton::mButton(sf::Vector2f size) : Button::Button(size)
{
    shape.setTexture(&texture);
}

void
mButton::setFunction(void (*_function)(), std::string _name_function)
{
    name_function = _name_function;
    function      = _function;
}

void
mButton::draw(sf::RenderWindow& window)
{

    sf::IntRect rect = patterns[name_function];

    if (condition == Condition::SELECTED)
    {
        rect.left += 172;
    }
    if (condition == Condition::KEPT || condition == Condition::HOLDING)
    {
        rect.left += 342;
    }

    shape.setTextureRect(rect);

    window.draw(shape);
}

void
mButton::work()
{
    function();
}