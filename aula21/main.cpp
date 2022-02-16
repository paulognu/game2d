#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(800, 350), "Aula 21 - Wind PowerPlan");
    window.setFramerateLimit(24);

    sf::VertexArray quad(sf::Quads, 4);

    quad[0].position = sf::Vector2f(0, 0);
    quad[0].color = sf::Color::Yellow;

    quad[1].position = sf::Vector2f(800, 0);
    quad[1].color = sf::Color::Yellow;

    quad[2].position = sf::Vector2f(800, 400);
    quad[2].color = sf::Color::Red;

    quad[3].position = sf::Vector2f(0, 400);
    quad[3].color = sf::Color::Red;

    sf::RectangleShape base;
    base.setSize(sf::Vector2f(4, 90));
    base.setFillColor(sf::Color::Black);
    base.setPosition(sf::Vector2f(200, 200));

    sf::RectangleShape base1;
    base1.setSize(sf::Vector2f(4, 90));
    base1.setFillColor(sf::Color::Black);
    base1.setPosition(sf::Vector2f(300, 200));

    sf::RectangleShape base2;
    base2.setSize(sf::Vector2f(4, 90));
    base2.setFillColor(sf::Color::Black);
    base2.setPosition(sf::Vector2f(500, 200));

    sf::RectangleShape base3;
    base3.setSize(sf::Vector2f(4, 90));
    base3.setFillColor(sf::Color::Black);
    base3.setPosition(sf::Vector2f(600, 200));

    sf::RectangleShape ground;
    ground.setSize(sf::Vector2f(800, 300));
    ground.setPosition(sf::Vector2f(0, 290));
    ground.setFillColor(sf::Color(30, 30, 30));

    sf::Texture t6;
    t6.loadFromFile("../resources/windPowerplant.png");
    
    sf::Sprite sB6(t6), sB7(t6), sB8(t6), sB9(t6);

    sB6.setPosition(301, 200);
    sB6.setOrigin(40, 40);

    sB7.setPosition(501, 200);
    sB7.setOrigin(40, 40);

    sB8.setPosition(601, 200);
    sB8.setOrigin(40, 40);

    sB9.setPosition(201, 200);
    sB9.setOrigin(40, 40);

    sf::Clock clock;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(clock.getElapsedTime().asSeconds() > 0.5f) {
            sB6.rotate(5);
        }
        sB7.rotate(5);
        sB8.rotate(3);
        sB9.rotate(4);

        if(clock.getElapsedTime().asSeconds() > 0.501f) {
            clock.restart();
        }

        window.clear(sf::Color::White);

        window.draw(quad);
        window.draw(ground);
        window.draw(base);
        window.draw(base1);
        window.draw(base2);
        window.draw(base3);
        window.draw(sB6);
        window.draw(sB7);
        window.draw(sB8);
        window.draw(sB9);

        window.display();
    }


    return 0;
}