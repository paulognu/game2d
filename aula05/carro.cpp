#include "carro.hpp"

Carro::Carro(sf::Texture& texture, int index, float velocidade) {
    this->index = index;
    rect = sf::IntRect(0, index * heigth, 32, 32);
    sprite = sf::Sprite(texture, rect);
    this->velocidade = velocidade;
}

sf::Sprite Carro::toSprite() {
    switch(direction) {
        case CarroDirection::Up:
            rect.left = 96;
            break;
        case CarroDirection::Down:
            rect.left = 224;
            break;
        case CarroDirection::Left:
            rect.left = 32;
            break;
        case CarroDirection::Right:
            rect.left = 160;
            break;
        case CarroDirection::UpLeft:
            rect.left = 64;
            break;
        case CarroDirection::UpRight:
            rect.left = 128;
            break;
        case CarroDirection::DownLeft:
            rect.left = 0;
            break;
        case CarroDirection::DownRight:
            rect.left = 192;
            break;
    }

    sprite.setTextureRect(rect);
    return sprite;
}

void Carro::up() {
    direction = CarroDirection::Up;
    sprite.move(0, -velocidade);
}

void Carro::down() {
    direction = CarroDirection::Down;
    sprite.move(0, velocidade);
}

void Carro::left() {
    direction = CarroDirection::Left;
    sprite.move(-velocidade, 0);
}

void Carro::right() {
    direction = CarroDirection::Right;
    sprite.move(velocidade, 0);
}

void Carro::upleft() {
    direction = CarroDirection::UpLeft;
    sprite.move(-velocidade, -velocidade);
}

void Carro::upright() {
    direction = CarroDirection::UpRight;
    sprite.move(velocidade, -velocidade);
}

void Carro::downleft() {
    direction = CarroDirection::DownLeft;
    sprite.move(-velocidade, velocidade);
}

void Carro::downright() {
    direction = CarroDirection::DownRight;
    sprite.move(velocidade, velocidade);
}

void Carro::setPosition(const int x, const int y) {
    sprite.setPosition(x, y);
}

void Carro::setScale(const double x, const double y) {
    sprite.setScale(x, y);
}

void Carro::move(InputDirection direction) {
    switch(direction) {
        case InputDirection::Up:
            up();
            break;
        case InputDirection::Down:
            down();
            break;
        case InputDirection::Left:
            left();
            break;
        case InputDirection::Right:
            right();
            break;
        case InputDirection::UpLeft:
            upleft();
            break;
        case InputDirection::UpRight:
            upright();
            break;
        case InputDirection::DownLeft:
            downleft();
            break;
        case InputDirection::DownRight:
            downright();
            break;
    }
}