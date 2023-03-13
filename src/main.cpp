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

    // Init clock for deltaTime
    sf::Clock deltaClock;
    while (window.isOpen())
    {
        // Calculate deltaTime
        float deltaTime = deltaClock.restart().asSeconds();

        // Event polling
        handleEvents(window);

        // Update
        shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        // Render
        window.clear(); // Clear old frame
        
        // Draw the frame
        window.draw(shape);
        
        window.display(); // Display the frame
    }

    return 0;
}