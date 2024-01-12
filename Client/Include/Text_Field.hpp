/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Text_Field
*/

#ifndef TEXT_FIELD_HPP_
    #define TEXT_FIELD_HPP_

    #include <string>
    #include <SFML/Graphics.hpp>
    #include "Image.hpp"

    namespace Menu {
        class Text_Field {
            public:
                // Constructeur avec chemin d'image de fond et position optionnelle
                Text_Field(const std::string &backPath, int posX = 0, int posY = 0);

                // Destructeur pour gérer la destruction proprement
                ~Text_Field();

                // Accesseurs et mutateurs
                const sf::String &getData() const { return data; }
                sf::Text getSfText() const { return item; }
                void clearText() { data.clear(); }
                void setFont(const sf::Font &font);
                void setPosition(float posX, float posY);
                void setMaxCharacters(unsigned int maxChar);

                // Méthodes pour la gestion du champ de texte
                void draw(sf::RenderWindow &window);
                void setText(sf::Uint32 entry);
                bool isSelected(const sf::Vector2f &mousePos);

            private:
                sf::Font font;
                sf::Text item;
                sf::String data;
                Image background;
                unsigned int maxEntry;

                // Méthode privée pour obtenir les limites du champ de texte
                sf::FloatRect getBounds() const;
        };
    }

#endif /* !TEXT_FIELD_HPP_ */
