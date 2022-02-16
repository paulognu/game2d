#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(200, 200), "second game");

    sf::Texture texture;
    texture.loadFromFile("../resources/red.png");

    sf::IntRect carro1Rect(0, 160, 32, 32);
    sf::Sprite carro1(texture, carro1Rect);
    sf::Clock clock;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        if(clock.getElapsedTime().asSeconds() > 0.4f) {
            if(carro1Rect.left == 224) {
                carro1Rect.left = 0;
            }else{
                carro1Rect.left += 32;
            }

            carro1.setTextureRect(carro1Rect);
            clock.restart();
        }

        window.draw(carro1);

        window.display();
    }

    return 0;
}