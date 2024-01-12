/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Image
*/

#ifndef IMAGE_HPP_
    #define IMAGE_HPP_

    #include <string>
    #include <SFML/Graphics.hpp>

    class Image {
        public:
            // Constructeur avec chemin par défaut et position optionnelle
            Image(const std::string &path, float posX = 0.0f, float posY = 0.0f);

            // Accesseurs et mutateurs pour le chemin de l'image
            const std::string &getPath() const { return path; }
            void setPath(const std::string &newPath);

            // Accesseur pour le sprite
            sf::Sprite &getSprite() { return sprite; }

            // Méthode pour définir la position du sprite
            void setPosition(float posX, float posY);

            // Méthode pour activer ou désactiver le focus (si nécessaire)
            void toggleFocus(bool focus);

        private:
            std::string path;
            sf::Texture texture;
            sf::Sprite sprite;
    };

#endif /* !IMAGE_HPP_ */
