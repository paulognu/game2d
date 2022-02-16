#ifndef KNIGHT_H
#define KNIGHT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "input.hpp"

class Knight {
    private:
        float currentFrame = 0.0;
        float velocity = 1.0f;
        float framerate = 0.3f;

        const std::string texture_path = "../resources/Knight.png";
        sf::Texture texture;
        sf::IntRect rect;
        sf::Sprite sprite;
        sf::Clock clock;
        InputDirection last_direction = InputDirection::Down;
        void updateRect(const InputDirection direction);
    public:
        Knight();
        const sf::Sprite& toSprite();
        void setDirection(const InputDirection direction);
        void move(const InputDirection direction);
};

#endif