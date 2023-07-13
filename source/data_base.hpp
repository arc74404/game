#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP

#include <SFML/Graphics.hpp>

class DataBase
{
private:
    static sf::Vector2f window_size;

	static sf::Vector2f centre;

public:
    static void createDataBase();

    static sf::Vector2f WindowSize();
	static sf::Vector2f Centre();
};

#endif // DATA_BASE_HPP