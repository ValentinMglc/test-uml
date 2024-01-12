/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include <SFML/Graphics.hpp>
    #include "Image.hpp"

    namespace Menu {

        class Button : public Image {
            public:
                // Constructeur du bouton avec position optionnelle
                Button(const std::string &path, int posX = 0, int posY = 0);

                // Méthode pour vérifier si le bouton est pressé
                bool isPressed(const sf::Vector2f &mousePos);

                // Méthode pour vérifier si le bouton est survolé
                bool isHovered(const sf::Vector2f &mousePos);
        };

    }

#endif /* !BUTTON_HPP_ */
