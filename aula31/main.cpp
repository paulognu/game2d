#include <SFML/Graphics.hpp>
#include "TileMap.hpp"
#include "Mario.hpp"
#include "Enemy.hpp"

const int H = 17;
const int W = 150;
float offsetX {0};
float offsetY {0};

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(400, 250), "Aula 31 - Super Mario Bros", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/Mario.png");

    TileMap tileMap(texture, W, H);
    tileMap.loadFromFile("fase01.tile");

    Mario mario(texture, W, H);
    mario.setBuffer(tileMap.buffer);

    Enemy enemy(texture, W, H, 48 * 16, 13 * 16);
    enemy.setBuffer(tileMap.buffer);

    sf::Clock clock;

    sf::Music music;
    music.openFromFile("../resources/Mario_Theme.ogg");
    music.setLoop(true);
    music.setVolume(60);
    music.play();
    
    while(window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time /= 500;
        if(time > 20) {
            time = 20;
        }

        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mario.left();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            mario.right();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            mario.jump();
        }

        mario.update(time, offsetX, offsetY);
        enemy.update(time, offsetX, offsetY);

        mario.intersects(enemy);

        window.clear(sf::Color(107, 140, 255));
        tileMap.draw(window, offsetX, offsetY);        
        mario.draw(window);
        enemy.draw(window);
        window.display();
    }

    return 0;
}
