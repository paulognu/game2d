#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Red Car");

    sf::Texture t1, t2;
    t1.loadFromFile("../resources/red.png");
    t2.loadFromFile("../resources/bgcar.png");

    sf::IntRect rect(5 * 32, 0, 32, 32);
    sf::Sprite sCar(t1, rect), sBackground(t2);

    float currentFrame = 0.0;
    sCar.setPosition(50, 100);
    sCar.setScale(2, 2);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sCar.move(-0.1, 0);

            rect.left = 1 * 32;
            sCar.setTextureRect(rect);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sCar.move(0.1, 0);

            rect.left = 5 * 32;
            sCar.setTextureRect(rect);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sCar.move(0, -0.1);

            rect.left = 3 * 32;
            sCar.setTextureRect(rect);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sCar.move(0, 0.1);

            rect.left = 7 * 32;
            sCar.setTextureRect(rect);
        }


        window.clear();

        window.draw(sBackground);
        window.draw(sCar);

        window.display();
    }

    return 0;
}