#include "gui.hpp"

sf::RenderWindow Gui::window;

const sf::Vector2f Gui::ellipse_size = {828.f, 755.f};

void
Gui::eventHandling()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

    }
}

bool
Gui::windowRendering()
{
    bool window_is_open = window.isOpen();

    if (window_is_open)
    {
        window.clear(sf::Color(176, 163, 79));

        // Background::draw(window);

        Map::draw(window);

        window.display();
    }

    return window_is_open;
}

void
Gui::createWindow()
{
    int lenght = 1500;
    int weight = 900;
    window.create(sf::VideoMode(lenght, weight), "Game");

    Background::setBoard(lenght, weight);

    window.setFramerateLimit(60);
}

sf::Vector2u
Gui::getWindowSize()
{
    return window.getSize();
}