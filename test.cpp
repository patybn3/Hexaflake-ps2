/*
    Copyright 2023 Patricia Antlitz
*/
#define BOOST_TEST_MODULE HexaflakeTest
#include <boost/test/included/unit_test.hpp>
#include "hexa.hpp"

BOOST_AUTO_TEST_CASE(testInit) {
    Hexaflake hexa(100, 2);
    BOOST_CHECK_EQUAL(hexa.getDepth(), 2);
    BOOST_CHECK_EQUAL(hexa.getLength(), 100);
}

BOOST_AUTO_TEST_CASE(testDrawing) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake Test");
    Hexaflake hexaflake(100, 2);
    window.draw(hexaflake, sf::RenderStates::Default);
}

BOOST_AUTO_TEST_CASE(testDepthZero) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake Test");
    Hexaflake hexaflake(100, 0);
    window.draw(hexaflake, sf::RenderStates::Default);
}

BOOST_AUTO_TEST_CASE(testBounds) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake Test");
    Hexaflake hexaflake(100, 3);
    window.draw(hexaflake, sf::RenderStates::Default);

    const sf::Vector2u wSize = window.getSize();

    for (size_t x = 0; x < wSize.x; x++) {
        for (size_t y = 0; y < wSize.y; y++) {
            BOOST_REQUIRE_GE(x, 0);
            BOOST_REQUIRE_LE(x, wSize.x);
            BOOST_REQUIRE_GE(y, 0);
            BOOST_REQUIRE_LE(y, wSize.y);
        }
    }
}

BOOST_AUTO_TEST_CASE(testImageTooSmall) {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake Test");
    Hexaflake hexaflake(50, 0);
    window.draw(hexaflake, sf::RenderStates::Default);

    const sf::Vector2u wSize = window.getSize();
    const double radius = 50.0 * 2.0;

    BOOST_CHECK_LE(radius, wSize.x);
    BOOST_CHECK_LE(radius, wSize.y);
}
