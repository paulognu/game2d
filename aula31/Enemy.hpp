#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
    private:
        int H, W;

    public:
        float dx, dy;
        sf::FloatRect rect;
        sf::Sprite sprite;
        float currentFrame;
        std::string* buffer;
        bool life;
        Enemy(sf::Texture& texture, int width, int height, int x, int y);
        void update(float time, float offsetX, float offsetY);
        void collision();
        void setBuffer(std::string& buffer);
        void draw(sf::RenderWindow& render);

};

#endif