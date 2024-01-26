/*
    Copyright 2023 Patricia Antlitz
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include "hexa.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Arguments should be passed as: " << argv[0] << "<side> <depth>" << std::endl;
        return 1;
    }

    double side = std::stod(argv[1]);
    int depth = std::stoi(argv[2]);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake");
    window.setFramerateLimit(60);

    Hexaflake hexagon(side, depth);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(hexagon, sf::RenderStates::Default);
        window.display();
    }

    return 0;
}
