#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iterator>
using namespace sf;
int main() {


    unsigned int tall = 750, large = 1850;
    sf::RenderWindow window(
        sf::VideoMode({large, tall}),
        "Ball_SMLF" );
    window.setFramerateLimit(60);
    struct balls {
    float y;
    float x;
    float speed;
    bool wall;
    float radius;
    sf::CircleShape circle;
    };
    balls ball[1850];
    for (int i = 0; i < std::size(ball); ++i){
        ball[i].radius = 0.5;
        ball[i].x = (2*ball[i].radius) * i;
        ball[i].y = i * (ball[i].radius*0.8);
        ball[i].wall = 1;
        ball[i].speed = 5.f;
        ball[i].circle = sf::CircleShape(ball[i].radius);
        ball[i].circle.setPosition({ball[i].x,ball[i].y});
    }
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        for (int i = 0; i < std::size(ball); ++i) {
        if (ball[i].wall) { ball[i].y += ball[i].speed; 
            ball[i].speed += 0.06;}
        else if (!(ball[i].wall)) {
           ball[i].y -=ball[i].speed;
            ball[i].speed-= 0.1;}
        if (ball[i].y>(tall-ball[i].radius *2)) {ball[i].wall = 0;}
        else if (ball[i].speed <= 0) {ball[i].wall = 1;}
        ball[i].circle.setPosition({ball[i].x, ball[i].y});
        }
        window.clear();
        for (int i = 0; i < std::size(ball); ++i) {
        window.draw(ball[i].circle);
        }
        window.display();
    }
}
