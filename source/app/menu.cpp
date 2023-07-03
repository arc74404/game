#include "menu.hpp"

Menu::Type Menu::type_now = Menu::Type::MAIN_MENU;

Menu::Type Menu::type_before;

sf::RectangleShape Menu::shape;

std::vector<mButton> Menu::main_menu;

std::vector<mButton> Menu::settings;

std::vector<mButton> Menu::pause_menu;

bool
Menu::Is_open()
{
    return type_now != Type::CLOSE;
}

void
Menu::draw(sf::RenderWindow& window)
{
    window.draw(shape);

    std::vector<mButton>* m_now = &main_menu;
    if (type_now == Type::SETTINGS) m_now = &settings;
    if (type_now == Type::PAUSE_MENU) m_now = &pause_menu;

    for (int i = 0; i < m_now->size(); ++i)
    {
        m_now->operator[](i).draw(window);
    }

    m_now = nullptr;
}

void
Menu::processing(sf::Vector2i mouse_position, bool is_pressed)
{
    std::vector<mButton>* m_now = &main_menu;
    if (type_now == Type::SETTINGS) m_now = &settings;
    if (type_now == Type::PAUSE_MENU) m_now = &pause_menu;

    for (int i = 0; i < m_now->size(); ++i)
    {
        m_now->operator[](i).processing(mouse_position, is_pressed);
    }

    m_now = nullptr;
}

void
Menu::escapeAction()
{
    if (type_now == Type::CLOSE) type_now = Type::PAUSE_MENU;
    else if (type_now == Type::MAIN_MENU) type_now = Type::SETTINGS;
    else if (type_now == Type::PAUSE_MENU) type_now = Type::CLOSE;
    else if (type_now == Type::SETTINGS) type_now = Type::MAIN_MENU;
}

void
Menu::createMenu()
{
    shape.setSize(sf::Vector2f(1000, 700));
    shape.setPosition(300, 100);
    sf::Color color(56, 90, 25, 120);
    shape.setFillColor(color);

    /////////////////////////////////////////////

    mButton::setTexture(
        "C:/Users/arsbo/source/repos/game/bin/pictures/main_menu.png");

    mButton standart_button(sf::Vector2f(400, 200));

    main_menu.resize(3, standart_button);

    for (int i = 0; i < main_menu.size(); ++i)
    {
        main_menu[i].setPosition(sf::Vector2f(200, i * 300 + 30));
    }

    main_menu[0].setFunction(startNewGame, "new game");
    main_menu[1].setFunction(continueGame, "restore");
    main_menu[2].setFunction(startNewGame, "settings");
    // main_menu[3].setFunction(startNewGame, "end game");

    /////////////////////////////////////////////
}

void
Menu::startNewGame()
{
    type_now = Type::CLOSE;
}
void
Menu::continueGame()
{
    type_now = Type::CLOSE;
}