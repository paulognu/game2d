#include "input.hpp"
#include <iostream>

Input::Input() {

}

InputDirection Input::getDirection() {
    const bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    const bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    const bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    const bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    int result = 0;

    if(up) {
        result += 1;
    }

    if(down) {
        result += 2;
    }

    if(left) {
        result += 4;
    }

    if(right) {
        result += 8;
    }

    switch(result) {
        case 0:
            return InputDirection::Skip;
            break;        
        case 1:
            return InputDirection::Up;
            break;        
        case 5:
            return InputDirection::UpLeft;
            break;        
        case 9:
            return InputDirection::UpRight;
            break;        
        case 2:
            return InputDirection::Down;
            break;        
        case 6:
            return InputDirection::DownLeft;
            break;        
        case 10:
            return InputDirection::DownRight;
            break;        
        case 4:
            return InputDirection::Left;
            break;        
        case 8:
            return InputDirection::Right;
            break;        
    }        

    return InputDirection::Skip;
}