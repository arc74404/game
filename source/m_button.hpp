#ifndef M_BUTTON_HPP
#define M_BUTTON_HPP

#include <map>
#include <string>

#include "button.hpp"

class mButton : public Button
{
private:
    void (*function)();

    static sf::Texture texture;

    static std::map<std::string, sf::IntRect> patterns;

    sf::Vector2f position_in_menu;

public:
    mButton();

    mButton(sf::Vector2f size);

    static void setTexture(std::string file_name);
    
    void draw(sf::RenderWindow& window) override;

    ///////////////////////////////////////
    void setFunction(void (*_function)(), std::string name_function);

    void work();
};

#endif // M_BUTTON_HPP