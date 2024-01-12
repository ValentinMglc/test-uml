/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Window
*/

#include "../Include/Window.hpp"
#include "../Include/Game.hpp"
#include "../Include/Io_Service_Work.hpp"
#include <iostream>

namespace Menu {
    Window::Window(sf::VideoMode mode, const sf::String &title)
        : window(mode, title),
          background(MENU_DEFAULT_BG),
          joinGameButton(JOINGAME_IMG, JOINGAME_PX, JOINGAME_PY),
          inGame(false),
          isIpFieldSelected(false),
          ipTextField(IP_IMG_PATH),
          portTextField(PORT_IMG_PATH),
          _ipAddress(""),
          backgroundMusic("../Client/Assets/music.ogg") {

        if (!gameFont.loadFromFile(FONT_PATH)) {
            std::cerr << "Failed to load font" << std::endl;
        } else {
            ipTextField.setFont(gameFont);
            ipTextField.setPosition(150, 670);
            ipTextField.setMaxCharacters(15);
            portTextField.setFont(gameFont);
            portTextField.setPosition(800, 670);
            portTextField.setMaxCharacters(5);
        }
        backgroundMusic.setRepeatable(true);
        backgroundMusic.play();
        background.getSprite().scale(sf::Vector2f(static_cast<float>(mode.width) / static_cast<float>(MENU_BG_WIDTH), static_cast<float>(mode.height) / static_cast<float>(MENU_BG_HEIGHT)));
    }

    void Window::handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (joinGameButton.isPressed(mousePos)) {
                    if (connectToServer(ipTextField.getData(), portTextField.getData())) {
                        inGame = true;
                    }
                }
                if (ipTextField.isSelected(mousePos)) {
                    isIpFieldSelected = true;
                } else {
                    isIpFieldSelected = false;
                }
            }
        }
    }

    bool Window::connectToServer(const std::string &ip, const std::string &port) {
        try {
            boost::asio::io_service ioService;
            boost::asio::ip::tcp::socket socket(ioService);
            boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip), std::stoi(port));
            socket.connect(endpoint);
            _ipAddress = ip;
            return true;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }

    std::string Window::formatTcpData(Constants::ACTIONS action, std::string &payload) {
        std::string packet;
        packet += static_cast<char>(action);
        packet += payload;
        packet += static_cast<char>(payload.size());
        return packet;
    }

    void Window::display() {
        window.clear();
        window.draw(background.getSprite());
        window.draw(joinGameButton.getSprite());
        ipTextField.draw(window);
        portTextField.draw(window);
        window.display();
    }

    void Window::loop() {
        Io_Service_Work ioServiceWork;

        while (window.isOpen()) {
            handleEvents();
            display();

            if (!inGame) {
                continue;
            } else {
                Game game(window, _ipAddress, ioServiceWork.getIoService(), "PlayerName");
                game.run();
            }
        }
        backgroundMusic.stop();
    }
}
