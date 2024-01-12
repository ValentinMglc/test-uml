/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
    #define BACKGROUND_HPP_

    #include <SFML/Graphics.hpp>
    #include "Constants/Constants.hpp"

    class Background {
        public:
            // Constructeur qui charge une image de fond
            explicit Background(const std::string &path);

            // Destructeur pour gérer la destruction proprement
            ~Background();

            // Méthode pour rendre le fond à l'écran
            void render(sf::RenderWindow &window);

            // Méthode pour mettre à jour le fond en fonction du déplacement
            void update(float offset);

        private:
            sf::Texture bgTexture;
            sf::Sprite bgSprite;
            sf::Sprite bgSprite2; // Pour créer un effet de défilement continu
            sf::Vector2f bgSize;  // Taille du fond d'écran
            float bgX;            // Position X actuelle du premier sprite de fond
            float bgX2;           // Position X du second sprite de fond

            // Méthode privée pour initialiser les sprites de fond
            void initializeSprites();
    };

#endif /* !BACKGROUND_HPP_ */
