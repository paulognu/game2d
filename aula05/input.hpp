#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

enum class InputDirection {
    Up,
    Down,
    Left,
    Right,
    UpLeft,
    UpRight,
    DownLeft,
    DownRight,
    Skip
};

class Input {
    public:
        InputDirection check();

};

#endif