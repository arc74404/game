#include "gui.hpp"

sf::RenderWindow Gui::window;

const sf::Vector2f Gui::ellipse_size = {828.f, 755.f};

float Gui::time = 0;

sf::Clock Gui::clock;

bool Gui::holding_escape = false;

TextButton Gui::t_button;

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

    if (Menu::getType() == Menu::Type::CLOSE)
    {
        t_button.processing(mouse_position);

        if (t_button.getCondition() != Button::Condition::STANDART &&
            t_button.getCondition() != Button::Condition::SELECTED)
        {
            sf::Vector2f m_pos = sf::Vector2f(sf::Mouse::getPosition(window).x,
                                              sf::Mouse::getPosition(window).y);

            sf::Vector2f pos_on_map =
                Player::getCentre() - DataBase::Centre() + m_pos;

            // std::cout << pos_on_map.x << " " << pos_on_map.y << '\n';

            int number =
                int(pos_on_map.y / Region::getSize().y) * Map::getSize().y +
                int(pos_on_map.x / Region::getSize().x);

            std::shared_ptr<BaseObject> object;
            if (event.type == sf::Event::TextEntered)
            {
                t_button.editText(event.text.unicode);
            }

            if (t_button.getString() == "stone")
            {
                object = std::make_shared<Stone>(pos_on_map);
                Map::addObject(number, object);
            }
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

    //////////////////////BUILD MODE/////////////////////////

    /////////////////////////////////////////////////////////
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
        ///////////////////////////

        ////////////////////////////

        if (Menu::getType() != Menu::Type::CLOSE)
        {
            Menu::draw(window);
        }
        t_button.draw(window);

        time = clock.getElapsedTime().asSeconds();
        clock.restart();

        window.display();
    }

    return window_is_open;
}

void
Gui::createWindow()
{
    sf::Vector2f window_size = DataBase::WindowSize();

    Background::setBoard(window_size.x, window_size.y);

    t_button.setSize((sf::Vector2f(200, 50)));

    t_button.setPosition(sf::Vector2f(100, 200));

    window.create(sf::VideoMode(window_size.x, window_size.y), "Game");

    window.setFramerateLimit(60);
}
