#ifndef TEXT_INPUT_HPP
#define TEXT_INPUT_HPP

#include "button.hpp"
#include "editorial_place.hpp"

class TextButton : public Button
{
private:
    sf::Font font;

    sf::Text text;

    sf::String input;

    sf::Cursor cursor;

    EditorialPlace edit_place;

    bool mouse_in_shape;

public:
    TextButton();

    TextButton(sf::Vector2f size);

    void setPosition(sf::Vector2f position) override;

    void editText(sf::Uint32 letter);

    void setSize(sf::Vector2f size) override;

    void processing(sf::Vector2i mouse_position) override;

    sf::String getString();

    void draw(sf::RenderWindow& window) override;
};

#endif // TEXT_INPUT_HPP