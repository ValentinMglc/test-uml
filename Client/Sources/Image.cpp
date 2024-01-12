/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Image
*/

#include <iostream>
#include "../Include/Image.hpp"

Image::Image(const std::string &path, float posX, float posY)
    : path(path) {
    if (!texture.loadFromFile(this->path)) {
        throw std::runtime_error("Failed to load image from: " + this->path);
    }
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

void Image::toggleFocus(bool focus) {
    if (focus) {
        sprite.setColor(sf::Color(204, 153, 55)); // Couleur pour l'état 'focus'
    } else {
        sprite.setColor(sf::Color(255, 255, 255)); // Couleur par défaut
    }
}

void Image::setPosition(float posX, float posY) {
    sprite.setPosition(posX, posY);
}

void Image::setPath(const std::string &newPath) {
    path = newPath;
    if (!texture.loadFromFile(path)) {
        throw std::runtime_error("Failed to load image from: " + path);
    }
    sprite.setTexture(texture);
}
