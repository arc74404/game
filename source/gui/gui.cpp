#include "gui.hpp"

sf::RenderWindow Gui::window;

const sf::Vector2f Gui::ellipse_size = {828.f, 755.f};

float Gui::time = 0;

sf::Clock Gui::clock;

bool Gui::holding_escape = false;

void
Gui::eventHandling()
{
    sf::Event event;
    window.pollEvent(event);
    //////////////////////////////////////////////////////////
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    //////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        if (!holding_escape)
        {
            Menu::escapeAction();
            holding_escape = true;
        }
    }
    else holding_escape = false;
    //////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);

    if (!Menu::Is_open())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Player::changePosition(mouse_position);
        }
    }
    else
    {
        Menu::processing(mouse_position,
                         sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
    //////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
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

        if (Menu::Is_open())
        {
            Menu::draw(window);
        }
        
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