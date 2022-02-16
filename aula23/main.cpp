#include <SFML/Graphics.hpp>

const int width = 300;
const int heigth = 400;

void moveUp(sf::RectangleShape& shape, float difficult = 1.2) {
    sf::Vector2f pos = shape.getPosition();

    if(pos.y > 0) {
        shape.setPosition(pos.x, pos.y - difficult);
    } else {
        shape.setPosition(pos.x, 0);
    }
}

void moveDown(sf::RectangleShape& shape, float difficult = 1.2) {
    sf::Vector2f pos = shape.getPosition();

    if(pos.y + 40 < heigth) {
        shape.setPosition(pos.x, pos.y + difficult);
    } else {
        shape.setPosition(pos.x, heigth - 40);
    }
}

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(width, heigth), "Aula 23 - Pong");
    window.setFramerateLimit(30);

    int placarP1 = 0;
    int placarP2 = 0;

    float dx, dy, speed = 5;
    dx = dy = 0;

    float difficult = 20;

    // Rede
    sf::RectangleShape net(sf::Vector2f(1, heigth));
    net.setPosition(sf::Vector2f(width/2, 0));
    net.setOutlineColor(sf::Color::White);

    // Jogador 1
    sf::RectangleShape player1(sf::Vector2f(10, 40));
    player1.setPosition(sf::Vector2f(0, heigth/2-20));
    player1.setFillColor(sf::Color::Blue);

    // Jogador 2
    sf::RectangleShape player2(sf::Vector2f(10, 40));
    player2.setPosition(sf::Vector2f(width-10, heigth/2-20));
    player2.setFillColor(sf::Color::Red);

    // Bola
    sf::RectangleShape ball(sf::Vector2f(10, 10));
    ball.setPosition(sf::Vector2f(100, 100));
    ball.setFillColor(sf::Color::White);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        sf::Vector2f bPos = ball.getPosition();
        sf::Vector2f p1Pos = player1.getPosition();
        sf::Vector2f p2Pos = player2.getPosition();

        if(bPos.y < 0) {
            dy = speed;
        }else if(bPos.y > heigth - 10) {
            dy = -speed;
        }

        // if(bPos.x < 0) {
        //     dx = speed;
        // }else if(bPos.x > width - 10) {
        //     dx = -speed;
        // }

        ball.setPosition(bPos.x + dx, bPos.y + dy);

        // Detect collisions player1
        if(bPos.x < 0) {
            dy = 0;
            dx = 0;
            ball.setPosition(145, 200);
            player2.setPosition(290, 180);
        }
        if(bPos.y >= p1Pos.y && bPos.y <= p1Pos.y + 40) {
            if(bPos.x <= p1Pos.x + 10) {
                dx = speed;
                placarP1 += 100;
            }
        }

        // Detect collisions player2
        if(bPos.x > 290) {
            dy = 0;
            dx = 0;
            ball.setPosition(145, 200);
            player1.setPosition(0, 180);
        }
        if(bPos.y >= p2Pos.y && bPos.y <= p2Pos.y + 40) {
            if(bPos.x > p2Pos.x - 10) {
                dx = -speed;
                placarP2 += 100;
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            moveUp(player1, difficult);
        }
 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            moveDown(player1, difficult);
        }

    
        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        //     moveUp(player2, difficult);
        // }


        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        //     moveDown(player2, difficult);
        // }

        if(bPos.x > 30 && dx > 0) {
            if(p2Pos.y > 0) {
                if(p2Pos.y > bPos.y) {
                    moveUp(player2, difficult);
                }
            }
        }
        if(bPos.x > 30 && dx > 0) {
            if(p2Pos.y < 400 - 40) {
                if(p2Pos.y < bPos.y) {
                    moveDown(player2, difficult);
                }
            }
        }

        if(bPos.x < width-30 && dx < 0) {
            if(p1Pos.y > 0) {
                if(p1Pos.y > bPos.y) {
                    moveUp(player1, difficult);
                }
            }
        }
        if(bPos.x < width-30 && dx < 0) {
            if(p1Pos.y < 400 - 40) {
                if(p1Pos.y < bPos.y) {
                    moveDown(player1, difficult);
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            dy = speed;
            dx = speed;
        }

        window.clear(sf::Color::Black);

        window.draw(net);
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);

        window.display();
    }

    return 0;
}