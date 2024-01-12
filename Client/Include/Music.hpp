/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Music
*/

#ifndef MUSIC_HPP_
    #define MUSIC_HPP_

    #include <SFML/Audio.hpp>

    class Music {
        public:
            // Constructeur qui charge un fichier de musique
            explicit Music(const std::string &path);

            // Destructeur pour gérer la destruction proprement
            ~Music();

            // Méthodes pour contrôler la lecture de la musique
            void play();
            void replay();
            void stop();

            // Méthodes pour configurer la musique
            void setRepeatable(bool repeat);
            void setVolume(float volume);

        private:
            sf::Music music;

            // Méthode privée pour charger la musique
            bool loadMusic(const std::string &path);
    };

#endif /* !MUSIC_HPP_ */
