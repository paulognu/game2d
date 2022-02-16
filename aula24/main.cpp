#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>

int main(int arc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(580, 420), "Aula 24 - snow");
    window.setFramerateLimit(60);

    // snowflakes
    sf::RectangleShape snow;
    snow.setFillColor(sf::Color::White);
    snow.setSize(sf::Vector2f(3.f, 3.f));

    std::vector<sf::RectangleShape> snows;
    snows.push_back(sf::RectangleShape(snow));

    int snowSpawnTimer = 0;
    float snowSpeed = 1.0f;

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(snowSpawnTimer < 5) {
            snowSpawnTimer++;
        }

        if(snowSpawnTimer >= 5) {
            snow.setPosition((rand() % int(window.getSize().x - snow.getSize().x)), 0.0f);
            snows.push_back(sf::RectangleShape(snow));

            snowSpawnTimer = 0;
        }

        for(int i = 0; i < snows.size(); i++) {
            snows[i].move(0.0f, snowSpeed);

            if(snows[i].getPosition().y > window.getSize().y) {
                snows.erase(snows.begin() + i);
            }
        }


        window.clear();

        for(int i = 0; i < snows.size(); i++) {
            window.draw(snows[i]);
        }

        window.display();
    }

    return 0;
}