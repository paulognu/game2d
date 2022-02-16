#ifndef CARRO_H
#define CARRO_H

#include <SFML/Graphics.hpp>
#include "input.hpp"

enum class CarroDirection {
    Up,
    Down,
    Left,
    Right,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight   
};

class Carro {
    private:        
        sf::Sprite sprite;
        sf::IntRect rect;
        int index;
        const int width = 32;
        const int heigth = 32;
        float velocidade = 0.0f;
        CarroDirection direction = CarroDirection::Right;

    public:
        Carro(sf::Texture &texture, int index, float velocidade);

        sf::Sprite toSprite();

        void setPosition(const int x, const int y);
        void setScale(const double x, const double y);

        void up();
        void down();
        void left();
        void right();
        void upleft();
        void upright();
        void downleft();
        void downright();
        void move(InputDirection direction);
};

#endif