#include <SFML/Graphics.hpp>
#include <iostream>
#include "carro.hpp"
#include "input.hpp"

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 512), "car moving");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/red.png");

    int carroIndex = 0;

    if(argc > 1) {
        carroIndex = std::stoi(argv[1]);
    }

    Input input;

    Carro carro(texture, carroIndex, 2.5f);
    carro.setPosition(96, 96);
    carro.setScale(2, 2);

    Carro carro2(texture, 3, 10.0f);    
    carro2.setScale(2, 2);

    bool reverse = false;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        InputDirection direction = input.check();
        carro.move(direction);

        
        if((!reverse && carro2.toSprite().getPosition().x > 1024) || (reverse && carro2.toSprite().getPosition().x < -100)) {
            reverse = !reverse;
        }
        carro2.move(reverse ? InputDirection::Left : InputDirection::Right);


        window.clear(sf::Color::White);
        window.draw(carro.toSprite());
        window.draw(carro2.toSprite());
        window.display();
    }

    return 0;
}