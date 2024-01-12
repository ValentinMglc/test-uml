/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Background
*/

#include "../Include/Background.hpp"

Background::Background(const std::string &path) {
    if (!bgTexture.loadFromFile(path)) {
        throw std::runtime_error("Failed to load background texture from: " + path);
    }
    bgSize = static_cast<sf::Vector2f>(bgTexture.getSize());
    bgSprite.setTexture(bgTexture);
    bgSprite2.setTexture(bgTexture);

    // Initialisation des positions pour créer un effet de défilement continu
    bgX = 0;
    bgX2 = bgSize.x;
}

Background::~Background() {
    // Destructeur
}

void Background::update(float offset) {
    float outBorder = -bgSize.x;
    bgX = (bgX > outBorder) ? (bgX - offset) : bgSize.x;
    bgX2 = (bgX2 > outBorder) ? (bgX2 - offset) : bgSize.x;

    bgSprite.setPosition(bgX, 0);
    bgSprite2.setPosition(bgX2, 0);
}

void Background::render(sf::RenderWindow &window) {
    window.draw(bgSprite);
    window.draw(bgSprite2);
}
