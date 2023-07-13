#include "button.hpp"

Button::Button() : Button(sf::Vector2f(0, 0))
{
}

Button::Button(sf::Vector2f size) : shape(size)
{
}

void
Button::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);
}

void
Button::processing(sf::Vector2i mouse_position)
{
    sf::Vector2f shape_position = shape.getPosition();

    bool is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    if (condition == Condition::RELEASED)
    {
        condition = Condition::STANDART;
    }

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
            else if (condition == Condition::KEPT)
            {
                condition = Condition::HOLDING;
            }
        }
        else
        {
            if (condition == Condition::KEPT || condition == Condition::HOLDING)
            {
                condition = Condition::RELEASED;
            }
            else if (condition == Condition::STANDART)
            {
                condition = Condition::SELECTED;
            }
        }
    }
    else
    {
        condition = Condition::STANDART;
    }
}

void
Button::setSize(sf::Vector2f size)
{
    shape.setSize(size);
}

Button::Condition
Button::getCondition()
{
    return condition;
}