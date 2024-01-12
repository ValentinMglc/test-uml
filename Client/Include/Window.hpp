/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include <string>
    #include <SFML/Graphics.hpp>
    #include <SFML/Network.hpp>
    #include <SFML/Audio.hpp>
    #include "Image.hpp"
    #include "Button.hpp"
    #include "Text_Field.hpp"
    #include "Music.hpp"
    #include "Constants/Constants.hpp"

    // Utilisation des constantes définies pour la taille et les chemins
    #define MENU_DEFAULT_WIDTH 1920
    #define MENU_DEFAULT_HEIGHT 1080
    #define MENU_TITLE "R-Type"
    #define FONT_PATH "Client/Assets/dodger3_1.ttf"
    #define MENU_DEFAULT_BG "Client/Assets/background.jpg"
    #define MENU_BG_WIDTH 1920
    #define MENU_BG_HEIGHT 1080

    // Positionnement et chemins des éléments de l'interface
    #define NEWGAME_IMG "Client/Assets/newgame.png"
    #define NEWGAME_PX 200
    #define NEWGAME_PY 700
    #define JOINGAME_IMG "Client/Assets/joingame.png"
    #define JOINGAME_PX 500
    #define JOINGAME_PY 700
    #define IP_IMG_PATH "Client/Assets/ip.png"
    #define PORT_IMG_PATH "Client/Assets/port.png"

    namespace Menu {

        class Window {
            public:
                Window(sf::VideoMode mode, const sf::String &title);
                void loop();

            private:
                void display();
                void handleEvents();
                bool connectToServer(const std::string &ip, const std::string &port);
                std::string formatTcpData(Constants::ACTIONS action, std::string &payload);
                bool processServerResponse(std::size_t bytesReceived, char *response);

                sf::RenderWindow window;
                Image background;
                Button joinGameButton;
                bool inGame;
                bool isIpFieldSelected;
                Text_Field ipTextField;
                Text_Field portTextField;
                std::string _ipAddress;
                Music backgroundMusic;
                sf::Font gameFont;
        };

    }

#endif /* !WINDOW_HPP_ */
