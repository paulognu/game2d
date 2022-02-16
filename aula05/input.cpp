#include "input.hpp"

InputDirection Input::check() {
    const bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    const bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    const bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    const bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    int direcao = 0;

    if(up) {
        direcao += 1;
    }

    if(down) {
        direcao += 2;
    }

    if(left) {
        direcao += 4;
    }

    if(right) {
        direcao += 8;
    }

    switch(direcao) {            
        case 1:
            return InputDirection::Up;
        case 5:
            return InputDirection::UpLeft;
        case 9:
            return InputDirection::UpRight;
        case 2:
            return InputDirection::Down;
        case 6:
            return InputDirection::DownLeft;
        case 10:
            return InputDirection::DownRight;
        case 4:
            return InputDirection::Left;
        case 8:
            return InputDirection::Right;
    }


    return InputDirection::Skip;
}