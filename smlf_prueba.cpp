#include <SFML/Graphics.hpp>
int main() {


    constexpr unsigned int tall = 750, large = 1850;    //Size of the window
    sf::RenderWindow window(
        sf::VideoMode({large, tall}),   //Open the window
        "Nick Ball_SMLF" );


    window.setFramerateLimit(60);
    constexpr float timestop = 1.f/60.f;
    sf::Clock clock;                    //Time limit for pysichs
    float time_acumulator = 0.f;

    struct Balls {  //Struct "Balls" whith their properties
    float y;
    float x;
    float speed = 5.f;
    bool wall = 1;  //This look for the touch of a border of the window, i use this afther
    float radius = 25.f;
    sf::CircleShape circle_shape;
    };

    Balls ball[20]; //How much balls to made, and they come from struct "Balls"
    for (int i = 0; i < std::size(ball); ++i){
        ball[i].x = (2*ball[i].radius) * i; //Space between balls (x-axis)
        ball[i].y = i * (ball[i].radius*0.8);   //Space between balls (y-axis)
        ball[i].circle_shape = sf::CircleShape(ball[i].radius); //Radius for each ball (in the "draw", idk)
        ball[i].circle_shape.setPosition({ball[i].x,ball[i].y});}   //Set position for each ball (x and y -axis)

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close(); }   //The close button close the window

        float frametime = clock.restart().asSeconds();  //For time limit, this aply the "freeze" time
        time_acumulator += frametime;

        while (time_acumulator >= timestop) { //This actualy aply the time config, the last thing of this "measures" the cant of freeze time
        
            for (int i = 0; i < std::size(ball); ++i) {
                if (ball[i].wall) { ball[i].y += ball[i].speed; 
                    ball[i].speed += 0.06;}
                else if (!(ball[i].wall)) {
                    ball[i].y -=ball[i].speed;
                    ball[i].speed-= 0.1;}
                if (ball[i].y>(tall-ball[i].radius *2)) {ball[i].wall = 0;}
                else if (ball[i].speed <= 0) {ball[i].wall = 1;}
                    ball[i].circle_shape.setPosition({ball[i].x, ball[i].y});   //Pysichs for each ball
            }
            time_acumulator -=timestop; //this "subtract" the time of "freeze" time
        }
        window.clear();
        for (int i = 0; i < std::size(ball); ++i) {
        window.draw(ball[i].circle_shape);  //Draw the circles in the window
        }
        window.display();   //idk, doesnt work without this
    }
}
