/*
    Copyright 2023 Patricia Antlitz
*/
#pragma once

#include <SFML/Graphics.hpp>

class Hexaflake : public sf::Drawable {
 public:
    Hexaflake(double length, int depth);

    int getLength() { return _length; }
    int getDepth() { return _depth; }

 private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void drawHex(sf::RenderTarget& target, const sf::Vector2f& hexPos,
                double lengthSide, int depth, sf::Color color, sf::RenderStates states) const;
    sf::Color gradientColor(sf::Color startColor, sf::Color endColor, float t) const;

    double _length;
    int _depth;
    sf::Color _startColor;
    sf::Color _endColor;

    static const int hexPoints = 6;
};
