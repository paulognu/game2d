#include <SFML/Graphics.hpp>

const int fireWidth = 2;
const int fireHeight = 3;
int firePixelsArray[fireWidth * fireHeight];

void createFireDataStructure() {
    const int numberOfPixels = fireWidth * fireHeight;

    for(int i = 0; i < numberOfPixels; i++) {
        firePixelsArray[i] = 0;
    }
}

void calculateFirePropagation() {

}

void renderFire() {

}

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fogo do Doom!");
    window.setFramerateLimit(60);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();

        window.display();
    }


    return 0;
}