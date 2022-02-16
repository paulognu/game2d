#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char **argv) {
	sf::RenderWindow window(sf::VideoMode(256, 256), "first image");

	sf::Texture texture;
	texture.loadFromFile("../resources/red.png");

	sf::IntRect rect(0, 0, 32, 32);
	sf::Sprite sprite(texture, rect);
	sf::Clock clock;

	sf::IntRect rect2(0, 32, 32, 32);
	sf::Sprite car2(texture, rect2);
	sf::Clock clock2;

	while(window.isOpen()) {
		sf::Event event;

		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if(clock.getElapsedTime().asSeconds() > 0.4f) {
			if(rect.left == 224) {
				rect.left = 0;
			}else{
				rect.left += 32;
			}

			sprite.setTextureRect(rect);
			clock.restart();
		}

		if(clock2.getElapsedTime().asSeconds() > 0.4f) {
			if(rect2.left == 244) {
				rect2.left = 0;
			}else{
				rect2.left += 32;				
			}

			car2.setTextureRect(rect2);
			clock2.restart();
		}

		window.clear();
		//window.draw(sprite);
		window.draw(car2);
		window.display();
	}

	return 0;
}
