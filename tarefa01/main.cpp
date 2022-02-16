#include <SFML/Graphics.hpp>
#include "knight.hpp"
#include "input.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Moving Knight - Tarefa 01");
    window.setFramerateLimit(60);

    Knight knight;
    Input direction;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        knight.move(direction.getDirection());
        
        window.clear(sf::Color::Black);
        window.draw(knight.toSprite());
        window.display();
    }

    return 0;
}