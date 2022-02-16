#include "project.hpp"

int start(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Aula 34 - Ryu");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/Ryu.png");

    sf::Clock clock;

    while(window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        time /= 500;

        if(time > 20) {
            time = 20;
        }

        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
            }
        }

        window.clear();

        window.display();
    }

    return 0;
}