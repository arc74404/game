#ifndef M_BUTTON_HPP
#define M_BUTTON_HPP

#include <map>
#include <string>

#include "button.hpp"

class mButton : public Button
{
private:
    static sf::Texture texture;

    static std::map<std::string, sf::IntRect> patterns;

    std::string name_function;

public:
    mButton();

    mButton(sf::Vector2f size);

    mButton(sf::Vector2f size, std::string _name_function);

    void draw(sf::RenderWindow& window) override;

    void setFunction(void(*_function)(), std::string name_function);

    static void setTexture(std::string file_name);
};

#endif // M_BUTTON_HPP