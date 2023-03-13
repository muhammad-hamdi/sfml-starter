#include<SFML/Graphics.hpp>
#include<iostream>

// Handle interrupt events
void handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

int main()
{
    // Create Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // Create a circle shape
    float radius = 50;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(radius, radius);

    // Set fps to 60
    window.setFramerateLimit(60);

    // init clock for deltaTime
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        // Calculate deltaTime
        float deltaTime = deltaClock.restart().asSeconds();

        // events
        handleEvents(window);

        shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        // Clear the canvas
        window.clear();
        
        // Do the drawing here
        window.draw(shape);

        // Display the frame
        window.display();
    }

    return 0;
}