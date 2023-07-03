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
    
    void (*function)();

public:
    enum class Condition
    {
        STANDART = 0,
        SELECTED = 1,
        KEPT     = 2
    };

    Button();

    Button(sf::Vector2f size);

    void setPosition(sf::Vector2f position);

    void processing(sf::Vector2i mouse_position, bool is_pressed);

    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // BUTTON_HPP