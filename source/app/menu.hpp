#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

#include "m_button.hpp"

class Menu
{
private:
    enum class Type;

    static Type type_now;

    static Type type_before;

    static sf::RectangleShape shape;

    static std::vector<mButton> settings;

    static std::vector<mButton> pause_menu;

    static std::vector<mButton> main_menu;

public:
    enum class Type
    {
        CLOSE      = 0,
        MAIN_MENU  = 1,
        SETTINGS   = 2,
        PAUSE_MENU = 3
    };

    static bool Is_open();

    static void draw(sf::RenderWindow& window);

    static void processing(sf::Vector2i mouse_position, bool is_pressed);

    static void escapeAction();

    static void createMenu();

    /////////////////////////////

    static void startNewGame();
    static void continueGame();
};

#endif // MENU_HPP