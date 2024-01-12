/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Button
*/

#include "../Include/Button.hpp"

namespace Menu {

    Button::Button(const std::string &path, int posX, int posY)
        : Image(path, posX, posY) {
    }

    bool Button::isPressed(const sf::Vector2f &mousePos) {
        if (getSprite().getGlobalBounds().contains(mousePos)) {
            getSprite().setColor(sf::Color(255, 255, 51)); // Couleur lors du clic
            return true;
        }
        getSprite().setColor(sf::Color(255, 255, 255)); // Couleur par défaut
        return false;
    }

    bool Button::isHovered(const sf::Vector2f &mousePos) {
        if (getSprite().getGlobalBounds().contains(mousePos)) {
            getSprite().setColor(sf::Color(128, 128, 128)); // Couleur au survol
            return true;
        } else {
            getSprite().setColor(sf::Color(255, 255, 255)); // Couleur par défaut
            return false;
        }
    }
}
