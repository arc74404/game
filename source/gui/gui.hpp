#ifndef GUI_HPP
#define GUI_HPP

#include "C:/Users/arsbo/source/repos/game/source/app/menu.hpp"
#include "C:/Users/arsbo/source/repos/game/source/objects/map/map.hpp"

#include "background.hpp"

class Gui
{
private:
    static sf::RenderWindow window;

    static const sf::Vector2f ellipse_size;

    static sf::Clock clock;

    static bool holding_escape;

public:
    static float time;
    
    static void eventHandling();

    static sf::Vector2u getWindowSize();

    static bool windowRendering();

    static void createWindow();
};

#endif // GUI_HPP