#include "TileMap.hpp"

TileMap::TileMap(sf::Texture& texture, int width, int height) {
    tile.setTexture(texture);
    H = height;
    W = width;
}

void TileMap::loadFromFile(std::string filename) {
    std::filebuf fb;
    if(fb.open(&filename[0], std::ios::in)) {
        std::istream fs(&fb);
        std::string tmp {};

        while(getline(fs, tmp)) {
            buffer += tmp;
        };

        fb.close();
    }
}

void TileMap::draw(sf::RenderWindow& render, float offsetX, float offsetY) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int index = W * i + j;            
            switch(buffer[index]) {
                case 'P':
                    tile.setTextureRect(sf::IntRect(143 - 16 * 3, 112, 16, 16));
                    break;                
                case 'k':
                    tile.setTextureRect(sf::IntRect(143, 112, 16, 16));
                    break;                
                case 'c':
                    tile.setTextureRect(sf::IntRect(143 - 16, 112, 16, 16));
                    break;                
                case 't':
                    tile.setTextureRect(sf::IntRect(0, 47, 32, 95 - 47));
                    break;                
                case 'g':
                    tile.setTextureRect(sf::IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));
                    break;                
                case 'G':
                    tile.setTextureRect(sf::IntRect(145, 222, 222 - 145, 255 - 222));
                    break;                
                case 'd':
                    tile.setTextureRect(sf::IntRect(0, 106, 74, 127 - 106));
                    break;                
                case 'w':
                    tile.setTextureRect(sf::IntRect(99, 224, 140 - 99, 255 - 224));
                    break;                
                case 'r':
                    tile.setTextureRect(sf::IntRect(143 - 32, 112, 16, 16));
                    break;                
                case ' ': case '0': 
                    continue;
           }

           tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
           render.draw(tile);
        }        
    }
}