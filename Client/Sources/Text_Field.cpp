/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Text_Field
*/

#include "../Include/Text_Field.hpp"

namespace Menu {
    Text_Field::Text_Field(const std::string &backPath, int posX, int posY)
        : background(backPath, posX, posY) {
        item.setPosition(posX + 10, posY + 35);
        item.setFillColor(sf::Color::White);
        item.setCharacterSize(20);
        item.setOutlineThickness(0.3);
        item.setOutlineColor(sf::Color::Black);
        maxEntry = 32;
    }

    Text_Field::~Text_Field() {
        // Destructeur
    }

    void Text_Field::setFont(const sf::Font &font) {
        item.setFont(font);
    }

    void Text_Field::setPosition(float posX, float posY) {
        background.setPosition(posX, posY);
        item.setPosition(posX + 10, posY + 35);
    }

    void Text_Field::setMaxCharacters(unsigned int maxChar) {
        maxEntry = maxChar;
    }

    sf::FloatRect Text_Field::getBounds() const {
        return item.getGlobalBounds();
    }

    bool Text_Field::isSelected(const sf::Vector2f &mousePos) {
        if (getBounds().contains(mousePos)) {
            background.toggleFocus(true);
            return true;
        }
        background.toggleFocus(false);
        return false;
    }

    void Text_Field::setText(sf::Uint32 entry) {
        if (entry == '\b') {
            if (data.getSize() > 0) {
                data.erase(data.getSize() - 1);
                item.setString(data);
            }
            return;
        }
        if (data.getSize() <= maxEntry) {
            data += entry;
        }
        item.setString(data);
    }

    void Text_Field::draw(sf::RenderWindow &window) {
        window.draw(background.getSprite());
        window.draw(item);
    }
}
