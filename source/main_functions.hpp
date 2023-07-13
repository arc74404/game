#ifndef MAIN_FUNCTIONS_HPP
#define MAIN_FUNCTIONS_HPP

#include "gui.hpp"
#include "menu.hpp"

class MainFunctions
{
    friend class Menu;

    friend class Gui;

private:
    static void StartNewGame();

    static void CloseGame();

    static void RestoreGame();

    static void OpenSetting();

    static void CloseSetting();
};

#endif // MAIN_FUNCTIONS_HPP
