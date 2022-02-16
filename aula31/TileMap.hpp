#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

class TileMap {
    private:
        int H;
        int W;
        sf::Sprite tile;
    public:
        std::string buffer {""};

        TileMap(sf::Texture& texture, int width, int height);
        void loadFromFile(const std::string filename);
        void draw(sf::RenderWindow& render, float offsetX, float offsetY);
};

#endif