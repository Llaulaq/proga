#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "HALLO!!!");


    sf::RectangleShape rect1(sf::Vector2f(250, 50));
    rect1.setPosition(125, 350);
    rect1.setRotation(10);

    rect1.setFillColor(sf::Color(255, 163, 148));
    rect1.setOutlineThickness(10);
    rect1.setOutlineColor(sf::Color(221,204,255));


    sf::CircleShape shape1(50);
    shape1.setPosition(100, 150);
    
    shape1.setFillColor(sf::Color(102, 82, 143));
    shape1.setOutlineThickness(10);
    shape1.setOutlineColor(sf::Color(189, 166, 192));


    sf::CircleShape shape2(50);
    shape2.setPosition(300, 100);
    shape2.setScale(1, 2);

    shape2.setFillColor(sf::Color(102, 82, 143));
    shape2.setOutlineThickness(10);
    shape2.setOutlineColor(sf::Color(189, 166, 192));


    sf::Font font;
    font.loadFromFile("Inter_28pt-Bold.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Heeeeelp!!!");
    text.setCharacterSize(36);
    text.setFillColor(sf::Color(17, 63, 255));
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setRotation(-25);
    text.setPosition(20, 100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(250,234,221));

        window.draw(shape1);
        window.draw(shape2);
        window.draw(rect1);
        window.draw(text);

        window.display();
    }
    return 0;
}