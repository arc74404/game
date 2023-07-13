#include "main_functions.hpp"

void
MainFunctions::CloseGame()
{
    Gui::window.close();
}

void
MainFunctions::CloseSetting()
{
}

void
MainFunctions::RestoreGame()
{
    Menu::type_now = Menu::Type::CLOSE;
}

void
MainFunctions::OpenSetting()
{
    Menu::type_now = Menu::Type::SETTINGS;
}

void
MainFunctions::StartNewGame()
{
}
