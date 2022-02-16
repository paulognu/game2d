#include "knight.hpp"
#include <iostream>

Knight::Knight() {
    texture.loadFromFile(texture_path);
    rect = sf::IntRect(5 + 32*4 + 32*currentFrame, 48*0, 40, 40);

    sprite = sf::Sprite(texture);
    sprite.setScale(2, 2);

    setDirection(InputDirection::Right);
}

const sf::Sprite& Knight::toSprite() {
    return sprite;
}

void Knight::move(const InputDirection direction) {

    if(clock.getElapsedTime().asSeconds() > framerate && direction != InputDirection::Skip) {
        if(currentFrame == -1) {
            currentFrame = 1;
        }else{
            currentFrame = -1;
        }

        clock.restart();
    }
    
    if(direction == InputDirection::Skip) {
        currentFrame = 0;
    }

    setDirection(direction);

    switch(direction) {
        case InputDirection::Up:
            sprite.move(0.0, -velocity);
            break;
        case InputDirection::Down:
            sprite.move(0.0, velocity);
            break;
        case InputDirection::Left:
            sprite.move(-velocity, 0.0f);
            break;
        case InputDirection::Right:
            sprite.move(velocity, 0.0f);
            break;            
        case InputDirection::UpLeft:
            sprite.move(-velocity/2, -velocity/2);
            break;            
        case InputDirection::UpRight:
            sprite.move(velocity/2, -velocity/2);
            break;            
        case InputDirection::DownLeft:
            sprite.move(-velocity/2, velocity/2);
            break;            
        case InputDirection::DownRight:
            sprite.move(velocity/2, velocity/2);
            break;            
    }
}

void Knight::updateRect(const InputDirection direction) {
    switch(direction) {
        case InputDirection::Up:
            rect.left = 5 + 32 * 4 + 32 * currentFrame;
            rect.top = 48 * 0;            
            break;
        case InputDirection::Down:
            rect.left = 5 + 32 * 4 + 32 * currentFrame;
            rect.top = 48 * 2;
            break;
        case InputDirection::Left:
            rect.left = 5 + 32 * 1 + 32 * currentFrame;
            rect.top = 48 * 1;
            break;
        case InputDirection::Right:
            rect.left = 5 + 32 * 7 + 32 * currentFrame;
            rect.top = 48 * 1;
            break;
        case InputDirection::UpLeft:
            rect.left = 5 + 32 * 1 + 32 * currentFrame;
            rect.top = 48 * 0;
            break;
        case InputDirection::UpRight:
            rect.left = 5 + 32 * 7 + 32 * currentFrame;
            rect.top = 48 * 0;
            break;
        case InputDirection::DownLeft:
            rect.left = 5 + 32 * 1 + 32 * currentFrame;
            rect.top = 48 * 2;
            break;
        case InputDirection::DownRight:
            rect.left = 5 + 32 * 7 + 32 * currentFrame;
            rect.top = 48 * 2;
            break;
        case InputDirection::Skip:
            if(last_direction != InputDirection::Skip) {
                updateRect(last_direction);
            }
            break;
    }

    last_direction = direction;
}

void Knight::setDirection(const InputDirection direction) {    
    updateRect(direction);    
    sprite.setTextureRect(rect);
}