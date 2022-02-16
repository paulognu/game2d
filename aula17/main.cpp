//watersound https://freesound.org/people/Nox_Sound/sounds/511078/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(1024, 384), "Aula 17 - Water");
    window.setFramerateLimit(60);

    sf::Image icon;
    icon.loadFromFile("../resources/waterBg.png");
    window.setIcon(1024, 384, icon.getPixelsPtr());

    float speed = 0.2f;
    float currentFrame = 0;
    sf::Texture tBg;
    tBg.loadFromFile("../resources/waterBg.png");

    sf::IntRect rBg(0, 0, 1024, 384);
    sf::Sprite sBg(tBg, rBg);

    // sound
    sf::Music waterSound;
    waterSound.openFromFile("../resources/511078__nox-sound__ambiance-waterfall-loop-01.ogg");
    waterSound.setVolume(80);  // 80%
    waterSound.setLoop(true);
    waterSound.play();

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if(currentFrame < 7) {
            currentFrame += speed;
        }else{
            currentFrame = 0;
        }

        rBg.top = 384 * int(currentFrame);
        sBg.setTextureRect(rBg);

        window.clear();

        window.draw(sBg);

        window.display();
    }


    return 0;
}