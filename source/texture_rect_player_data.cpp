#include "texture_rect_player_data.hpp"

TextureRectPlayerData::TextureRectPlayerData()
    : texture_rect(), number_of_pattern(0), time(0)
{
    patterns.resize(9);

    patterns[0] = sf::IntRect(17, 17, 106, 153);

    
    patterns[1] = sf::IntRect(17 + 126, 17, 106, 153);
    patterns[2] = sf::IntRect(17 + 235, 17, 106, 153);
    patterns[3] = sf::IntRect(387, 17, 106, 153);
    patterns[4] = sf::IntRect(510, 17, 106, 153);
    patterns[5] = sf::IntRect(633, 17, 106, 153);
    patterns[6] = sf::IntRect(764, 17, 106, 153);
    patterns[7] = sf::IntRect(886, 17, 106, 153);
    patterns[8] = sf::IntRect(1005, 17, 106, 153);
}

sf::IntRect
TextureRectPlayerData::getTextureRect()
{
    time = clock.getElapsedTime().asSeconds();

    if (Player::status == Player::Status::STAY_R ||
        Player::status == Player::Status::STAY_L)
    {
        texture_rect      = patterns[0];
        number_of_pattern = 0;

        if (Player::status == Player::Status::STAY_L)
        {
            texture_rect.left += texture_rect.width;
            texture_rect.width *= -1;
        }
    }

    else if (Player::status == Player::Status::RUN_R ||
             Player::status == Player::Status::RUN_L)
    {
        if (time >= 0.1)
        {
            number_of_pattern++;

            if (number_of_pattern > 8) number_of_pattern = 3;

            texture_rect = patterns[number_of_pattern];

            if (Player::status == Player::Status::RUN_L)
            {
                texture_rect.left += texture_rect.width;
                texture_rect.width *= -1;
            }

            clock.restart();
        }
    }

    return texture_rect;
}