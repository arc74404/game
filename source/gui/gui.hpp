#ifndef GUI_HPP
#define GUI_HPP

#include "background.hpp"

#include "C:/Users/arsbo/source/repos/game/source/objects/map/map.hpp"

class Gui
{
private:
    static sf::RenderWindow window;

    static const sf::Vector2f ellipse_size;

    static sf::Clock clock;

    static float time;

    static bool is_mouse_LeftButoon_press;

public:
    static void eventHandling();
    
    static sf::Vector2u getWindowSize();

    static bool windowRendering();

    static void createWindow();
};

#endif // GUI_HPP