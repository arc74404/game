#include "app.hpp"

App::App()
{
    DataBase::createDataBase();

    Map::createMap();

    Gui::createWindow();

    Menu::createMenu();

    Player::createPlayer();
}

void
App::run()
{
    while (Gui::windowRendering())
    {
        Gui::eventHandling();

        if (Player::Is_moving() && Menu::getType() == Menu::Type::CLOSE)
        {
            Player::move(Gui::time);
        }
    }
}