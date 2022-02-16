#include <SFML/Graphics.hpp>
#include <iostream>

float offsetX = 0;
float offsetY = 0;

const int H = 20;
const int W = 87;

std::string tileMap {
    "B                                                                              BBBBBBBB"
    "B                                                                              BBBBBBBB"
    "B                                                                              BBBBBBBB"
    "B                                                                              BBBBBBBB"
    "B                               BBBBBBBBBBBBBBBB                               BBBBBBBB"
    "B                             BB                                               BBBBBBBB"
    "B                                                                              BBBBBBBB"
    "B                  BB                   000                                    BBBBBBBB"
    "B                    BB                                                        BBBBBBBB"
    "B                      BBBB                                                    BBBBBBBB"
    "B                                                                              BBBBBBBB"
    "B      0                        BB                                             BBBBBBBB"
    "B                             BB  BB                                           BBBBBBBB"
    "B                           BB      BB               0 0 0 0 0 0               BBBBBBBB"
    "B            BB           BB          BB                                       BBBBBBBB"
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
};

class Bullet {
    public:
        sf::Sprite projectile;

        Bullet(sf::Texture& image) {
            projectile.setTexture(image);
            projectile.setTextureRect(sf::IntRect(0, 0, 8, 8));
            projectile.setScale(2, 2);

        }

        void update() {
            projectile.setTextureRect(sf::IntRect(0, 0, 8, 8));
            projectile.setScale(2, 2);
        }
};

class Player {
    public:
        float dx, dy;
        sf::FloatRect rect;
        bool onGround;
        sf::Sprite sprite;
        float currentFrame;

        Player(sf::Texture& image) {
            sprite.setTexture(image);
            rect = sf::FloatRect(250, 0, 50, 95);
            // sprite.setTextureRect(rect);
            dx = dy = 0.1f;
            currentFrame = 0;
        }

        void update(float time) {
            rect.left += dx * time;
            collision(0);

            if(onGround == false) {
                dy += 0.0005 * time;
            }

            rect.top += dy * time;
            onGround = false;
            collision(1);

            currentFrame += 0.005 * time;
            if(currentFrame > 4) {
                currentFrame -= 4;
            }

            if(dx > 0) {
                sprite.setTextureRect(sf::IntRect(250 + 53 * int(currentFrame), 0, 53, 100));
            }else if(dx < 0 ) {
                sprite.setTextureRect(sf::IntRect(250 + 53 * int(currentFrame) + 53, 0, -53, 100));
            }

            sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

            dx = 0;
        }

        void collision(int dir) {
            for(int i = rect.top/32; i < (rect.top + rect.height)/32; i++) {
                for(int j = rect.left/32; j < (rect.left + rect.width) / 32; j++) {
                    // if(tileMap[i][j] == "B") {
                    if(tileMap[W * i + j] == 'B') {
                        if((dx > 0) && dir == 0) {
                            rect.left = j*32 - rect.width;
                        }
                        if((dx < 0) && dir == 0) {
                            rect.left = j*32 + 32;
                        }
                        if((dy > 0) && dir == 1) {
                            rect.top = i*32 - rect.height;
                            dy = 0;
                            onGround = true;
                        }
                        if((dy < 0) && dir == 1) {
                            rect.top = i*32 + 32;
                            dy = 0;
                        }

                    }else if(tileMap[W * i + j] == '0') {
                        tileMap[W * i + j] = ' ';
                    }
                }
            }
        }
};

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Aula 25 - Plataform");
    // window.setFramerateLimit(60);

    std::cout << "Tamanho do tileMap: " << tileMap.length() << '\n';

    sf::Texture t, t1;
    t.loadFromFile("../resources/SaraOGATransparent.PNG");
    t1.loadFromFile("../resources/ex10.png");

    float currentFrame = 0;

    Player p(t);
    sf::Clock clock;
    sf::IntRect rect(0, 0, 32, 32);     // tilemap
    sf::Sprite rectangle(t1, rect);     // tilemap

    Bullet b(t);
    std::vector<sf::Sprite> projectiles;
    projectiles.push_back(sf::Sprite(b.projectile));
    bool right {true };
    bool left { false };

    sf::Vector2f playerWeaponRight;
    sf::Vector2f playerWeaponLeft;
    int shootTimer = 0;

    while(window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time /= 700;

        if(time > 20) {
            time = 20;
        }

        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            p.dx = -0.1;
            left = true;
            right = false;            
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            p.dx = 0.1;            
            right = true;
            left = false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if(p.onGround) {
                p.dy = -0.35;
                p.onGround = false;
            }
        }

        // Projectiles
        playerWeaponRight = sf::Vector2f(p.sprite.getPosition().x + 30, p.sprite.getPosition().y + 50);
        playerWeaponLeft = sf::Vector2f(p.sprite.getPosition().x, p.sprite.getPosition().y + 50);
        shootTimer++;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 500) {
            if(right) {
                b.projectile.setPosition(playerWeaponRight);
            }

            if(left) {
                b.projectile.setPosition(playerWeaponLeft);
            }
            
            projectiles.push_back(sf::Sprite(b.projectile));

            shootTimer = 0;
        }

        for(int i = 0; i < projectiles.size(); i++) {
            if(right) {
                projectiles[i].move(0.4f, 0.0f);
            }else if(left) {
                projectiles[i].move(-0.4f, 0.0f);
            }

            if(projectiles[i].getPosition().x > p.sprite.getPosition().x + 30) {
                projectiles[i].move(0.4, 0.0f);
            }
            if(projectiles[i].getPosition().x < p.sprite.getPosition().x) {
                projectiles[i].move(-0.4, 0.0f);
            }

            if(projectiles[i].getPosition().x <= 0 || projectiles[i].getPosition().x > 800) {
                projectiles.erase(projectiles.begin() + i);
            }
        }


        p.update(time);
        // b.update();

        if(p.rect.left > 300) {
            offsetX = p.rect.left - 300;
        }
        offsetY = p.rect.top - 200;

        window.clear();
        window.draw(p.sprite);
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(tileMap[W * i + j] == 'B') {
                    rectangle.setTextureRect(sf::IntRect(0, 0, 32, 32));
                }else if(tileMap[W * i + j] == '0') {
                    rectangle.setTextureRect(sf::IntRect(530, 0, 32, 32));
                }else{
                    continue;
                }
                rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
                window.draw(rectangle);                
            }
        }

        for(int i = 0; i < projectiles.size(); i++) {
            window.draw(projectiles[i]);
        }

        window.display();
    }

    return 0;
}