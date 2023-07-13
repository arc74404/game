#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

class Button
{
protected:
    enum class Condition;

    sf::RectangleShape shape;

    Condition condition;

    std::string name_function;

public:
    enum class Condition
    {
        STANDART = 0,
        SELECTED = 1,
        KEPT     = 2,
        HOLDING  = 3,
        RELEASED = 4
    };

    Button();

    Button(sf::Vector2f size);

    virtual void processing(sf::Vector2i mouse_position);

    virtual void setSize(sf::Vector2f size);

    virtual void setPosition(sf::Vector2f position);

    virtual void draw(sf::RenderWindow& window) = 0;

    Condition getCondition();
};

#endif // BUTTON_HPP