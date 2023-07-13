#include "text_button.hpp"

TextButton::TextButton() : TextButton(sf::Vector2f(0, 0))
{
}

TextButton::TextButton(sf::Vector2f size) : Button(size)
{
    font.loadFromFile("C:/Users/arsbo/source/repos/game/bin/arial.ttf");

    text.setFont(font);
    text.setColor(sf::Color::Black);
    text.setCharacterSize(size.y * 0.98);

    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::Magenta);
}

void
TextButton::setSize(sf::Vector2f size)
{
    Button::setSize(size);

    text.setCharacterSize(size.y * 0.98);
}

void
TextButton::editText(sf::Uint32 letter)
{
    if (letter == 8)
    {
        if (!input.isEmpty())
        {
            input.erase(input.getSize() - 1, 1);
        }
    }
    else
    {
        input += letter;
    }
}

void
TextButton::setPosition(sf::Vector2f position)
{
    shape.setPosition(position);

    text.setPosition(position);
}

void
TextButton::draw(sf::RenderWindow& window)
{
    sf::Cursor::Type type_cursor;

    if (!mouse_in_shape)
    {
        type_cursor = sf::Cursor::Type::Arrow;
    }
    else
    {
        type_cursor = sf::Cursor::Type::Text;
    }

    cursor.loadFromSystem(type_cursor);

    window.setMouseCursor(cursor);
    window.draw(shape);

    sf::String extra_str = input.substring(edit_place.getFirst(),
                                           edit_place.getLenght());

    text.setString(extra_str);

    window.draw(text);
}

sf::String
TextButton::getString()
{
    return input;
}

void
TextButton::processing(sf::Vector2i mouse_position)
{
    sf::Vector2f shape_position = shape.getPosition();

    bool is_pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    int place = edit_place.getPlace();

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
        mouse_in_shape = true;
    }
    else
    {
        if (is_pressed)
        {
            condition = Condition::STANDART;
        }
        mouse_in_shape = false;
    }

    edit_place.processing(place);
}