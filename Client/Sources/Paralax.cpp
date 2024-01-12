/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Paralax
*/

#include <iostream>
#include "../Include/Paralax.hpp"

Paralax::Paralax() {

}

Paralax::~Paralax() {

}

void Paralax::addBackground(const std::string &path) {
    try {
        backgrounds.emplace_back(path);
    } catch (const std::exception &e) {
        std::cerr << "Unable to create background from: " << path << " - " << e.what() << std::endl;
    }
}

void Paralax::moveBackgrounds(sf::RenderWindow &window) {
    if (backgrounds.empty()) {
        return;
    }

    int offset = 1;
    for (auto &background : backgrounds) {
        background.update(offset);
        background.render(window);
        offset++;
    }
}
