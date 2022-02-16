#include "Mario.hpp"

Mario::Mario(sf::Texture& texture, int width, int height) {
    sprite.setTexture(texture);
    rect = sf::FloatRect(100, 180, 16, 16);
    W = width;
    H = height;

    dx = dy = 0.1;
    currentFrame = 0;

    bSound.loadFromFile("../resources/Jump.ogg");
    sound = sf::Sound(bSound);
}

void Mario::collision(int num) {
    for(int i = rect.top/16; i < (rect.top + rect.height)/16; i++) {
        for(int j = rect.left/16; j < (rect.left + rect.width)/16; j++) {
            int index = W * i + j;
            switch((*buffer)[index]) {
                case 'P': case 'k': case '0': case 'r': case 't':
                    if(dy > 0 && num == 1) {
                        rect.top = i * 16 - rect.height;
                        dy = 0;
                        _onGround = true;
                    }
                    if(dy < 0 && num == 1) {
                        rect.top = i * 16 + 16;
                        dy = 0;
                    }
                    if(dx > 0 && num == 0) {
                        rect.left = j * 16 - rect.width;
                    }
                    if(dx < 0 && num == 0) {
                        rect.left = j * 16 + 16;
                    }
                    break;
                case 'c':
                    // buffer[index] = ' ';
                    break;
            }
        }
    }
}

bool Mario::onGround() {
    return _onGround;
}

void Mario::setBuffer(std::string& buffer) {
    this->buffer = &buffer;
}

void Mario::update(float time, float& offsetX, float& offsetY) {
    rect.left += dx * time;
    collision(0);

    if(_onGround == false) {
        dy += 0.0005 * time;
    }

    rect.top += dy * time;
    _onGround = false;
    collision(1);

    currentFrame += time * 0.005;
    if(currentFrame > 3) {
        currentFrame -= 3;
    }

    if(dx > 0) {
        sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
    }
    if(dx < 0) {
        sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));
    }

    sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

    dx = 0;

    if(rect.left > 200) {
        offsetX = rect.left - 200;
    }
}

void Mario::draw(sf::RenderWindow& render) {
    render.draw(sprite);
}

void Mario::left() {
    dx = -0.1;
}

void Mario::right() {
    dx = 0.1;
}

void Mario::jump() {
    if(_onGround) {
        dy = -0.27;
        _onGround = false;
        sound.play();
    }
}

void Mario::intersects(Enemy& enemy) {
    if(rect.intersects(enemy.rect)) {
        if(enemy.life) {
            if(dy > 0) {
                enemy.dx = 0;
                dy = -0.2;
                enemy.life = false;
            }else{
                sprite.setColor(sf::Color::Red);
            }
        }
    }
}