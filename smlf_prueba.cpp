#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    sf::RenderWindow window(
        sf::VideoMode({1000, 500}),
        "Nick wilde"
    );

    window.setFramerateLimit(60);

    float y1 = 0.f, y2 = 50.f, y3 = 100.f , speed3 = 5.f, speed2 = 5.f, speed1 = 5.f;
    bool wall1 = 1, wall2 = 1, wall3 = 1;
    sf::CircleShape circle1(50.f);
    circle1.setPosition({200.f,y1});
    
    sf::CircleShape circle2(50.f);
    circle2.setPosition({500.f,y2});

    sf::CircleShape circle3(50.f);
    circle3.setPosition({700.f,y3});

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (wall1) { y1 +=speed1; 
            speed1+= 0.06;}
        else if (!wall1) {
            y1 -=speed1;
            speed1-= 0.1;}
        
        if (y1>400.f) {wall1 = 0;}
        else if (speed1 <= 0) { wall1 = 1;}


        if (wall2) { y2 +=speed2; 
            speed2+= 0.06;}
        else if (!wall2) {
            y2 -=speed2;
            speed2-= 0.1;}
        
        if (y2>400.f) {wall2 = 0;}
        else if (speed2 <= 0) { wall2 = 1;}


      if (wall3) { y3 +=speed3; 
            speed3+= 0.06;}
        else if (!wall3) {
            y3 -=speed3;
            speed3-= 0.1;}
        
        if (y3>400.f) {wall3 = 0;}
        else if (speed3 <= 0) { wall3 = 1;}


        circle1.setPosition({200.f,y1});
        circle2.setPosition({500.f,y2});
        circle3.setPosition({700.f,y3});

        window.clear();
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle3);
        window.display();

    }
}
