#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(800, 400), "Sunset");

    sf::Clock clock;

    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(0, 0);
    quad[0].color = sf::Color::Red;

    quad[1].position = sf::Vector2f(800, 0);
    quad[1].color = sf::Color::Red;

    quad[2].position = sf::Vector2f(800, 400);
    quad[2].color = sf::Color::Yellow;

    quad[3].position = sf::Vector2f(0, 400);
    quad[3].color = sf::Color::Yellow;
    
    sf::VertexArray quad2(sf::Quads, 4);
    quad2[0].position = sf::Vector2f(0, -400);
    quad2[0].color = sf::Color::Blue;

    quad2[1].position = sf::Vector2f(800, -400);
    quad2[1].color = sf::Color::Blue;

    quad2[2].position = sf::Vector2f(800, 0);
    quad2[2].color = sf::Color::Red;

    quad2[3].position = sf::Vector2f(0, 0);
    quad2[3].color = sf::Color::Red;

    sf::Texture t6, t7, t8;
    t6.loadFromFile("../resources/sunsetHouse.png");
    t7.loadFromFile("../resources/sunsetHouse2.png");
    t8.loadFromFile("../resources/smokeTransparent.png");

    sf::IntRect rectSmoke(0, 0, 35, 70)    ;
    sf::Sprite sB6(t6), sB7(t7), sB8(t8, rectSmoke);

    sB6.setPosition(0, -90);
    sB7.setPosition(0, -90);

    // starts
    const int N = 50;
    sf::RectangleShape star[N];
    for(int i = 0; i < N; i++) {
        star[i].setPosition(sf::Vector2f(rand() % 800, rand() % 400));
        star[i].setFillColor(sf::Color::Cyan);
        star[i].setSize(sf::Vector2f(1.0f, 1.0f));
    }

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(clock.getElapsedTime().asSeconds() > 10.0f) {
            quad[2].position.y += 0.05;
            quad[3].position.y += 0.05;
            quad2[2].position.y += 0.005;
            quad2[3].position.y += 0.005;
        }

        if(clock.getElapsedTime().asSeconds() > 60.0f) {
            quad[2].position.y -= 0.05;
            quad[3].position.y -= 0.05;
            quad2[2].position.y -= 0.005;
            quad2[3].position.y -= 0.005;
        }

        window.clear();

        window.draw(quad);
        window.draw(quad2);
        window.draw(sB6);

        if(clock.getElapsedTime().asSeconds() > 20.0f) {
            window.draw(sB7);
        }

        if(clock.getElapsedTime().asSeconds() > 30.0f) {
            if(rectSmoke.left == 210) {
                rectSmoke.left = 0;
            }else{
                rectSmoke.left += 35;
            }

            sB8.setTextureRect(rectSmoke);
            sB8.setPosition(350, 175);
            window.draw(sB8);
        }

        if(clock.getElapsedTime().asSeconds() > 90.0f) {
            for(int i = 0; i < N; i++) {
                window.draw(star[i]);
            }
        }

        if(clock.getElapsedTime().asSeconds() > 180.0f) {
            quad[2].position.y -= 32.0;
            quad[3].position.y -= 32.0;
            quad2[2].position.y -= 3.2;
            quad2[3].position.y -= 3.2;
            for(int i = 0; i < N; i++) {
                star[i].setFillColor(sf::Color::White);
                window.draw(star[i]);
            }
        }



        window.display();
    }


    return 0;
}