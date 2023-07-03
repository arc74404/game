#include "button.hpp"

Button::Button() : Button(sf::Vector2f(0, 0))
{
    function = nullptr;
}

Button::Button(sf::Vector2f size) : shape(size)
{
    function = nullptr;
}

void
Button::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);
}

void
Button::processing(sf::Vector2i mouse_position, bool is_pressed)
{
    sf::Vector2f shape_position = shape.getPosition();

    if (mouse_position.x > shape_position.x &&
        mouse_position.x < shape_position.x + shape.getSize().x &&
        mouse_position.y > shape_position.y &&
        mouse_position.y < shape_position.y + shape.getSize().y)
    {
        if (is_pressed)
        {
            if (condition == Condition::SELECTED)
            {
                condition = Condition::KEPT;
            }
        }
        else
        {
            if (condition == Condition::KEPT) // отжата внутри
            {
                if (function != NULL)
                {
                    function();
                }
            }
            condition = Condition::SELECTED;
        }
    }
    else
    {
        condition = Condition::STANDART;
    }
}