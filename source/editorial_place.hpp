#ifndef EDITORIAL_PLACE_HPP
#define EDITORIAL_PLACE_HPP

#include <SFML/Graphics.hpp>

class EditorialPlace
{
private:
    int place_of_cursor_input;

    int first_letter_of_visible_part;

    int lenght_of_visible_part;

    sf::String part_string;

    sf::RectangleShape shape;

    sf::Clock clock;

    float time;

    bool visible;

public:
    EditorialPlace();

    EditorialPlace(int size);

    int getPlace();

    void processing(int pp);

    void draw(sf::RenderWindow& window);

    int getFirst();

    int getLenght();
};

#endif // EDITORIAL_PLACE_HPP