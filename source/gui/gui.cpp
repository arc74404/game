#include "gui.hpp"

sf::RenderWindow Gui::window;

const sf::Vector2f Gui::ellipse_size = {828.f, 755.f};

float Gui::time = 0;

sf::Clock Gui::clock;

bool Gui::is_mouse_LeftButoon_press = false;

void
Gui::eventHandling()
{
    sf::Event event;

    window.pollEvent(event);

    if (event.type == sf::Event::Closed)
    {
        window.close();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

        Player::changePosition(mouse_position);
    }

    if (Player::Is_moving())
    {
        Player::move(time);
    }
}

bool
Gui::windowRendering()
{
    bool window_is_open = window.isOpen();

    if (window_is_open)
    {
        window.clear(sf::Color(176, 163, 79));

        Map::draw(window);

        Player::draw(window);

        // Background::draw(window);

        time = clock.getElapsedTime().asSeconds();
        clock.restart();

        window.display();
    }

    return window_is_open;
}

void
Gui::createWindow()
{
    int lenght = 1500;
    int weight = 900;

    Background::setBoard(lenght, weight);

    Map::Map();

    window.create(sf::VideoMode(lenght, weight), "Game");

    window.setFramerateLimit(60);
}

sf::Vector2u
Gui::getWindowSize()
{
    return window.getSize();
}