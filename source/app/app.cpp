#include "app.hpp"

App::App()
{
    Gui::createWindow();
}

void
App::run()
{
    while(Gui::windowRendering())
    {
        Gui::eventHandling();
    }
}