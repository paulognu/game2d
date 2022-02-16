#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& texture, int width, int height, int x, int y) {
    W = width;
    H = height;

    sprite.setTexture(texture);
    rect = sf::FloatRect(x, y, 16, 16);

    dx = 0.05;
    currentFrame = 0;
    life = true;
}

void Enemy::update(float time, float offsetX, float offsetY) {
    rect.left += dx * time;
    collision();

    currentFrame += time * 0.005;
    if(currentFrame > 2) {
        currentFrame -= 2;
    }

    sprite.setTextureRect(sf::IntRect(18 * int(currentFrame), 0, 16, 16));
    if(life == false) {
        sprite.setTextureRect(sf::IntRect(58, 0, 16, 16));
    }

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
}

void Enemy::collision() {
    for(int i = rect.top/16; i < (rect.top + rect.height)/16; i++) {
        for(int j = rect.left/16; j < (rect.left + rect.width)/16; j++) {
            int index = W * i + j;
            switch((*buffer)[index]) {
                case 'P': case '0':
                    if(dx > 0) {
                        rect.left = j * 16 - rect.width;
                        dx *= -1.0;
                    }else if(dx < 0) {
                        rect.left = j * 16 + 16;
                        dx *= -1;
                    }

                    break;
            }
        }
    }
}

void Enemy::setBuffer(std::string& buffer) {
    this->buffer = &buffer;
}

void Enemy::draw(sf::RenderWindow& render) {
    render.draw(sprite);
}