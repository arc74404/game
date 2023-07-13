#include "menu.hpp"

Menu::Type Menu::type_now = Menu::Type::MAIN_MENU;

Menu::Type Menu::type_before;

sf::RectangleShape Menu::shape;

std::vector<mButton> Menu::main_menu;

std::vector<mButton> Menu::settings;

std::vector<mButton> Menu::pause_menu;

Menu::Type
Menu::getType()
{
    return type_now;
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
        m_now->operator[](i).processing(mouse_position);
        if (m_now->operator[](i).getCondition() == Button::Condition::RELEASED)
        {
            m_now->operator[](i).work();
        }
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
    sf::Vector2f menu_size;

    sf::Vector2f window_size = DataBase::WindowSize();

    float procent_x = 80;
    float procent_y = 80;

    menu_size.x = window_size.x * procent_x / 100;
    menu_size.y = window_size.y * procent_y / 100;

    shape.setSize(menu_size);

    shape.setPosition((window_size.x - menu_size.x) / 2,
                      (window_size.y - menu_size.y) / 2);

    shape.setFillColor(sf::Color(56, 90, 25, 200));

    /////////////////////////////////////////////

    mButton::setTexture(
        "C:/Users/arsbo/source/repos/game/bin/pictures/main_menu.png");

    float button_procent = 20;

    mButton standart_button(sf::Vector2f(menu_size.x * button_procent / 100,
                                         menu_size.y * button_procent / 100));

    main_menu.resize(4, standart_button);

    sf::Vector2f menu_position = shape.getPosition();

    float position_procent_x = 20;
    float position_procent_y = 15;

    main_menu[0].setPosition(
        sf::Vector2f(menu_position.x + menu_size.x * position_procent_x / 100,
                     menu_position.y + menu_size.y * position_procent_y / 100));

    main_menu[1].setPosition(sf::Vector2f(
        menu_position.x + menu_size.x * position_procent_x * 3 / 100,
        menu_position.y + menu_size.y * position_procent_y / 100));

    main_menu[2].setPosition(sf::Vector2f(
        menu_position.x + menu_size.x * position_procent_x / 100,
        menu_position.y + menu_size.y * position_procent_y * 4 / 100));

    main_menu[3].setPosition(sf::Vector2f(
        menu_position.x + menu_size.x * position_procent_x * 3 / 100,
        menu_position.y + menu_size.y * position_procent_y * 4 / 100));

    main_menu[0].setFunction(MainFunctions::StartNewGame, "new game");
    main_menu[1].setFunction(MainFunctions::RestoreGame, "restore");
    main_menu[2].setFunction(MainFunctions::OpenSetting, "settings");
    main_menu[3].setFunction(MainFunctions::CloseGame, "close game");
    /////////////////////////////////////////////
}
