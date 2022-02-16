#include <SFML/Graphics.hpp>
#include <cmath>

const int width = 1024;
const int height = 768;
const int roadW = 2000;
const int segL = 200;
const float camD = 0.84;

void drawQuad(sf::RenderWindow& w, sf::Color c, int x1, int y1, int w1, int x2, int y2, int w2) {
    sf::ConvexShape shape(4);
    shape.setFillColor(c);
    shape.setPoint(0, sf::Vector2f(x1 - w1, y1));
    shape.setPoint(1, sf::Vector2f(x2 - w2, y2));
    shape.setPoint(2, sf::Vector2f(x2 + w2, y2));
    shape.setPoint(3, sf::Vector2f(x1 + w1, y1));
    w.draw(shape);
}

class Line {
    public:
        float x, y, z;  // 3d center of line
        float X, Y, W;  // screen coord
        float curve, spriteX, clip, scale;
        sf::Sprite sprite;

        Line() {
            spriteX = curve = x = y = z = 0;
        }

        void project(int camX, int camY, int camZ) {
            scale = camD / (z - camZ);
            X = (1 + scale * (x - camX)) * width / 2;
            Y = (1 - scale * (y - camY)) * height / 2;
            W = scale * roadW * width / 2;
        }

        void drawSprite(sf::RenderWindow& app) {
            sf::Sprite s = sprite;
            int w = s.getTextureRect().width;
            int h = s.getTextureRect().height;

            float destX = X + scale * spriteX * width / 2;
            float destY = Y + 4;
            float destW = w * W / 266;
            float destH = h * W / 266;

            destX += destW * spriteX; // offsetX
            destY += destH * (-1);    // offsetY

            float clipH = destY + destH - clip;
            if(clipH < 0) {
                clipH = 0;
            }

            if(clipH >= destH) {
                return;
            }

            s.setTextureRect(sf::IntRect(0, 0, w, h - h * clipH / destH));
            s.setScale(destW / w, destH / h);
            s.setPosition(destX, destY);
            app.draw(s);
        }
};

int main(int argc, char **argv) {
    sf::RenderWindow app(sf::VideoMode(width, height), "Outrun Racing!");
    app.setFramerateLimit(60);

    sf::Texture t[50];
    sf::Sprite object[50];
    for(int i = 1; i <= 7; i++) {
        t[i].loadFromFile("../resources/" + std::to_string(i) + ".png");
    }

    float currentFrame = 0;

    sf::Texture bg;
    bg.loadFromFile("../resources/cityNight2.png");
    bg.setRepeated(true);
    sf::Sprite sBackground(bg);
    sBackground.setTextureRect(sf::IntRect(0, 0, 5000, 411));
    sBackground.setPosition(-2000, 0);

    sf::Texture car;
    car.loadFromFile("../resources/carTransparent.png");
    sf::Sprite sCar(car);
    sCar.setTextureRect(sf::IntRect(0, 0, 250, 140));
    sCar.setPosition(350, 550);
    sCar.setScale(1.6, 1.6);

    std::vector<Line> lines;

    for(int i = 0; i < 1600; i++) {
        Line line;
        line.z = i * segL;

        if(i > 300 && i < 700) {
            line.curve = 0.5;
        }

        if(i > 1100) {
            line.curve = -0.7;
        }

        if(i < 300 && i % 20 == 0) {
            line.spriteX = -2.5;
            line.sprite = object[5];
        }

        if(i % 17 == 0) {
            line.spriteX = 2.0;
            line.sprite = object[6];
        }

        if(i > 300 && i % 20 == 0) {
            line.spriteX = -0.7;
            line.sprite = object[4];
        }

        if(i > 800 && i % 20 == 0) {
            line.spriteX = -1.2;
            line.sprite = object[1];
        }

        if(i > 750) {
            line.y = sin(i / 30.0) * 1500;            
        }

        lines.push_back(line);
    }

    int N = lines.size();
    float playerX = 0;
    int pos = 0;
    int H = 1500;

    while(app.isOpen()) {
        sf::Event event;

        while(app.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    app.close();
                    break;
            }
        }

        int speed = 0;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            playerX += 0.1;
            sCar.setTextureRect(sf::IntRect(760, 0, 250, 140));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            playerX -= 0.1;
            sCar.setTextureRect(sf::IntRect(510, 0, 225, 140));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            speed = 200;
            currentFrame += 0.08;
            if(currentFrame > 2) {
                currentFrame -= 2;
            }

            sCar.setTextureRect(sf::IntRect(250 * int(currentFrame), 0, 250, 140));

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sCar.setTextureRect(sf::IntRect(760, 0, 225, 140));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sCar.setTextureRect(sf::IntRect(510, 0, 225, 140));
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            speed = -200;
            currentFrame += 0.08;
            if(currentFrame > 2) {
                currentFrame -= 2;
            }

            sCar.setTextureRect(sf::IntRect(250 * int(currentFrame), 0, 250, 140));
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
            speed *= 3;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            H += 100;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            H -= 100;
        }

        pos += speed;
        while(pos >= N * segL) {
            pos -= N * segL;
        }
        while(pos < 0) {
            pos += N * segL;
        }

        app.clear(sf::Color(105, 205, 4));
        app.draw(sBackground);

        int startPos = pos / segL;
        int camH = lines[startPos].y + H;
        if(speed > 0) {
            sBackground.move(-lines[startPos].curve * 2, 0);
        }
        if(speed < 0) {
            sBackground.move(lines[startPos].curve * 2, 0);
        }

        int maxy = height;
        float x = 0, dx = 0;

        for(int n = startPos; n < startPos + 300; n++) {
            Line& l = lines[n % N];
            l.project(playerX * roadW - x, camH, startPos * segL - (n >= N ? N * segL : 0));
            x += dx;
            dx += l.curve;

            l.clip = maxy;
            if(l.Y >= maxy) {
                continue;
            }

            maxy = l.Y;

            sf::Color grass = (n / 3) % 2 ? sf::Color(16, 200, 16) : sf::Color(0, 154, 0);
            sf::Color rumble = (n / 3) % 2 ? sf::Color(255, 255, 255) : sf::Color(0, 0, 0);
            sf::Color road = (n / 3) % 2 ? sf::Color(107, 107, 107) : sf::Color(105, 105, 105);

            Line p = lines[(n - 1) % N]; // previos line

            drawQuad(app, grass, 0, p.Y, width, 0, l.Y, width);
            drawQuad(app, rumble, p.X, p.Y, p.W * 1.2, l.X, l.Y, l.W * 1.2);
            drawQuad(app, road, p.X, p.Y, p.W, l.X, l.Y, l.W);
        }

        app.draw(sCar);

        // draw objects
        for(int n = startPos + 300; n > startPos; n--)  {
            lines[n % N].drawSprite(app);
        }

        app.display();
    }

    return 0;    
}