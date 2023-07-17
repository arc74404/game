#include "editorial_place.hpp"

EditorialPlace::EditorialPlace() : EditorialPlace::EditorialPlace(0)
{
}

EditorialPlace::EditorialPlace(int size)
{
    shape.setSize(sf::Vector2f(size / 8, size));
    shape.setFillColor(sf::Color::Blue);

    clock.restart();
    time = 0;

    first_letter_of_visible_part = 0;

    lenght_of_visible_part = 10;

    visible = false;
}

void
EditorialPlace::processing(int pp)
{
    place_of_cursor_input = first_letter_of_visible_part + pp;
    time                  = clock.getElapsedTime().asSeconds();
    if (time >= 0.2)
    {
        sf::Color color = sf::Color::Blue;
        if (visible)
        {
            color.a = 0;
            visible = false;
        }
        else
        {
            color.a = 255;
            visible = true;
        }
        shape.setFillColor(color);
        clock.restart();
    }
}

int
EditorialPlace::getPlace()
{
    return place_of_cursor_input;
}

int
EditorialPlace::getFirst()
{
    return first_letter_of_visible_part;
}

int
EditorialPlace::getLenght()
{
    return lenght_of_visible_part;
}


void
EditorialPlace::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
