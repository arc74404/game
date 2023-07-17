#ifndef GUI_HPP
#define GUI_HPP

#include "background.hpp"
#include "data_base.hpp"
#include "main_functions.hpp"
#include "map.hpp"
#include "menu.hpp"
#include "text_button.hpp"

class Gui
{
    friend class MainFunctions;

private:
    static sf::RenderWindow window;

    static const sf::Vector2f ellipse_size;

    static sf::Clock clock;

    static bool holding_escape;

    static TextButton t_button;

    static sf::RectangleShape border_object;

public:
    static float time;

    static void eventHandling();

    static bool windowRendering();

    static void createWindow();
};

#endif // GUI_HPP