/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Paralax
*/

#ifndef PARALAX_HPP_
    #define PARALAX_HPP_

    #include <vector>
    #include <SFML/Graphics.hpp>
    #include "Background.hpp"

    class Paralax {
        public:
            // Constructeur et destructeur
            Paralax();
            ~Paralax();

            // Méthode pour ajouter un fond d'écran au parallaxe
            void addBackground(const std::string &path);

            // Méthode pour déplacer et rendre les fonds d'écran
            void moveBackgrounds(sf::RenderWindow &window);

        private:
            std::vector<Background> backgrounds; // Utilisation d'un vector pour une gestion plus efficace
    };

#endif /* !PARALAX_HPP_ */
