#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Houses");
    window.setFramerateLimit(60);

    sf::Texture t1, t2, t3, t4, t5, t6;
    t1.loadFromFile("../resources/casa1.png");
    t2.loadFromFile("../resources/casa2.png");
    t3.loadFromFile("../resources/casa3.png");
    t4.loadFromFile("../resources/casa4.png");
    t5.loadFromFile("../resources/casa5.png");
    t6.loadFromFile("../resources/casa6.png");

    int choice = 0;
    sf::Clock clock;

    auto cs = [] (const sf::Texture& t) {
        return sf::Sprite(t);
    };
    sf::Sprite s[] = {cs(t1), cs(t2), cs(t3), cs(t4), cs(t5), cs(t6)};

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            choice = 0;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            choice = 1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            choice = 2;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            choice = 3;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
            choice = 4;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
            choice = 5;
        }

        window.clear(sf::Color::White);

        window.draw(s[choice]);

        window.display();
    }

    return 0;
}