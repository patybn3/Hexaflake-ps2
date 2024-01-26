/*
    Copyright 2023 Patricia Antlitz
*/
#include <cmath>

#include "hexa.hpp"

Hexaflake::Hexaflake(double length, int depth) : _length(length), _depth(depth) {
    // I ran out of time to do the gradient thing but I was setting the colors up here
    _startColor = sf::Color(128, 0, 128);  // Purple
    _endColor = sf::Color(225, 255, 0);  // Yellow
}

sf::Color Hexaflake::gradientColor(sf::Color startColor, sf::Color endColor, float t) const {
    sf::Uint8 r = static_cast<sf::Uint8>(startColor.r + t * (endColor.r - startColor.r));
    sf::Uint8 g = static_cast<sf::Uint8>(startColor.g + t * (endColor.g - startColor.g));
    sf::Uint8 b = static_cast<sf::Uint8>(startColor.b + t * (endColor.b - startColor.b));
    return sf::Color(r, g, b);
}

void Hexaflake::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // centers the image
    sf::Vector2f position(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    // rotates the whole snowflake
    sf::Transform transform = sf::Transform::Identity;
    transform.rotate(30, position.x, position.y);
    states.transform *= transform;

    float t = static_cast<float>(_depth) / static_cast<float>(hexPoints);
    sf::Color curr = gradientColor(_startColor, _endColor, t);

    drawHex(window, position, _length, _depth, curr, states);
}

void Hexaflake::drawHex(sf::RenderTarget& window, const sf::Vector2f& hexPos, double lengthSide,
                        int depth, sf::Color color, sf::RenderStates states) const {
    if (depth == 0) {
        return;
    }

    if (depth == 1) {
        sf::ConvexShape innerHexagon;
        innerHexagon.setPointCount(hexPoints);
        innerHexagon.setFillColor(color);

        for (int i = 0; i < hexPoints; i++) {
            double angleHex = i * M_PI / 3;
            double xHex = hexPos.x + lengthSide * cos(angleHex);
            double yHex = hexPos.y + lengthSide * sin(angleHex);
            innerHexagon.setPoint(i, sf::Vector2f(xHex, yHex));
        }

        window.draw(innerHexagon, states);

        //// outer hexagons
        for (int i = 0; i < hexPoints; i++) {
            sf::ConvexShape outerHex;
            outerHex.setPointCount(hexPoints);
            outerHex.setFillColor(color);

            double angleRad = i * M_PI / 3;
            double x = hexPos.x + 2 * lengthSide * cos(angleRad);
            double y = hexPos.y + 2 * lengthSide * sin(angleRad);
            sf::Vector2f position(x, y);

            for (int j = 0; j < hexPoints; j++) {
                double angleHex = j * M_PI / 3;
                double xHex = position.x + lengthSide * cos(angleHex);
                double yHex = position.y + lengthSide * sin(angleHex);
                outerHex.setPoint(j, sf::Vector2f(xHex, yHex));
            }

            window.draw(outerHex, states);
        }
    } else {
        for (int i = 0; i < hexPoints; i++) {
            double angleRad = i * M_PI / 3;
            double x = hexPos.x + 2 * lengthSide * cos(angleRad);
            double y = hexPos.y + 2 * lengthSide * sin(angleRad);
            sf::Vector2f position(x, y);

            drawHex(window, position, lengthSide / 3, depth - 1, color, states);
            drawHex(window, hexPos, lengthSide / 3, depth - 1, color, states);
        }
    }
}
