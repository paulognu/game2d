#ifndef MARIO_H
#define MARIO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Enemy.hpp"

class Mario {
    private:
        int H;
        int W;
        float dx, dy;
        sf::FloatRect rect;
        bool _onGround;
        sf::Sprite sprite;
        float currentFrame {0};
        std::string* buffer;
        sf::SoundBuffer bSound;
        sf::Sound sound;

    public:
        Mario(sf::Texture& texture, int width, int height);
        void collision(int num);
        void setBuffer(std::string& buffer);
        bool onGround();
        void update(float time, float& offsetX, float& offsetY);
        void draw(sf::RenderWindow& render);

        void intersects(Enemy& enemy);

        void left();
        void right();
        void jump();
};

#endif