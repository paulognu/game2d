#include <SFML/Graphics.hpp>



int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(320, 480), "animated car moving");
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("../resources/car2.png");

    sf::IntRect rect(0, 0, 250, 140);
    sf::Clock clock;
    sf::Sprite sprite(texture);
    sprite.setPosition(60, 300);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -10.0f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, 10.0f);
        }

        if(clock.getElapsedTime().asSeconds() > 0.2f) {
            if(rect.left == 250) {
                rect.left = 0;
            }else{
                rect.left += 250;
            }

            sprite.setTextureRect(rect);
            clock.restart();
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}