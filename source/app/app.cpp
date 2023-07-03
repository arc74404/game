#include "app.hpp"

App::App()
{
    Gui::createWindow();

    Menu::createMenu();
}

void
App::run()
{
    while(Gui::windowRendering())
    {
        Gui::eventHandling();

        if (Player::Is_moving() && !Menu::Is_open())
        {
            Player::move(Gui::time);
        }
    }
}