#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Movimentacao de Personagem");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/fang.png");

    float currentFrame = 0;
    sf::IntRect rect(0, 244, 40, 50);
    sf::Sprite sprite(texture, rect);

    sprite.setPosition(50, 100);
    sprite.setScale(2, 2);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if(sprite.getPosition().x > 0) {
                sprite.move(-3.0, 0.0);
            }

            currentFrame += 0.15;
            if(currentFrame > 6) {
                currentFrame -= 6;
            }
            sprite.setTextureRect(sf::IntRect(40 * int(currentFrame) + 40, 244, -40, 50));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if(sprite.getPosition().x + 75 < 1024) {
                sprite.move(3.0, 0.0);
            }

            currentFrame += 0.15;
            if(currentFrame > 6) {
                currentFrame -= 6;
            }
            sprite.setTextureRect(sf::IntRect(40 * int(currentFrame), 244, 40, 50));            
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }


    return 0;    
}