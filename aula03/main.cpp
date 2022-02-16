#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(320, 480), "car moving by input");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/car.png");

    sf::IntRect rect(0, 0, 200, 120);
    sf::Sprite carro(texture, rect);
    carro.setPosition(60, 300);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();                
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            carro.move(0, -10.0f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            carro.move(0, 10.0f);
        }

        window.clear(sf::Color::White);
        window.draw(carro);
        window.display();
    }

    return 0;
}