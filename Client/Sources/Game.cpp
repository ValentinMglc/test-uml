/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Game
*/

#include <iostream>
#include <chrono>
#include "Game.hpp"
#include "Timer.hpp"

Game::Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso, const std::string &playername)
    : _window(window),
      _ip(ip),
      _player1(std::make_unique<Image>(PLAYER1_SPRITE)),
      _player2(std::make_unique<Image>(PLAYER2_SPRITE)),
      _player3(std::make_unique<Image>(PLAYER3_SPRITE)),
      _player4(std::make_unique<Image>(PLAYER4_SPRITE)),
      _enemy1(std::make_unique<Image>(ENEMY1_SPRITE)),
      _enemy2(std::make_unique<Image>(ENEMY2_SPRITE)),
      _enemy3(std::make_unique<Image>(ENEMY3_SPRITE)),
      _enemy4(std::make_unique<Image>(ENEMY4_SPRITE)),
      _bullet(std::make_unique<Image>(BULLET_SPRITE)),
      _playerName(playername),
      _queueClass(std::make_shared<Queue<UDP_Server_Stream_BufferData>>()),
      _endpoint(boost::asio::ip::address::from_string(ip), STD_SERV_UDP_PORT),
      _udpClient(std::make_unique<UDP_Client>(iso, STD_CLI_UDP_PORT, _queueClass)),
      _shootSound("../Client/Assets/shoot.ogg")
{
    _shootSound.setVolume(10);
    _parallax.addBackground("../Client/Assets/parallax-background.png");
    _parallax.addBackground("../Client/Assets/parallax-planets.png");
    _parallax.addBackground("../Client/Assets/parallax-stars.png");
}

Game::~Game() {
    // Destructeur
}

bool Game::handleGameEvents() {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
            _shootSound.stop();
            return false;
        }
        if (event.type == sf::Event::KeyPressed)
            processPlayerInput(event);
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            _playerActions.push({_playerName, Constants::EVENT::SHOOT, 0});
    }
    return true;
}

void Game::sendPlayerAction() {
    if (!_playerActions.empty()) {
        if (_playerActions.back().event == Constants::EVENT::SHOOT)
            _shootSound.replay();
        _udpClient->send(_playerActions.back(), _endpoint);
        std::queue<UDP_Client_Stream_BufferData> empty;
        std::swap(_playerActions, empty);
    }
}

void Game::processPlayerInput(sf::Event &event) {
    if (event.key.code == sf::Keyboard::Up)
        _playerActions.push({_playerName, Constants::DIRECTION::UP});
    if (event.key.code == sf::Keyboard::Down)
        _playerActions.push({_playerName, Constants::DIRECTION::DOWN});
    if (event.key.code == sf::Keyboard::Left)
        _playerActions.push({_playerName, Constants::DIRECTION::LEFT});
    if (event.key.code == sf::Keyboard::Right)
        _playerActions.push({_playerName, Constants::DIRECTION::RIGHT});
}

void Game::processGameFrame() {
    while (!_queueClass->empty()) {
        auto item = _queueClass->pop();
        switch (item.index) {
            case Constants::TYPE::PLAYER_1:
                _player1->setPosition(item.x, item.y);
                _window.draw(_player1->getSprite());
                break;
            case Constants::TYPE::PLAYER_2:
                _player2->setPosition(item.x, item.y);
                _window.draw(_player2->getSprite());
                break;
            case Constants::TYPE::PLAYER_3:
                _player3->setPosition(item.x, item.y);
                _window.draw(_player3->getSprite());
                break;
            case Constants::TYPE::PLAYER_4:
                _player4->setPosition(item.x, item.y);
                _window.draw(_player4->getSprite());
                break;
            case Constants::TYPE::ENEMY_1:
                _enemy1->setPosition(item.x, item.y);
                _window.draw(_enemy1->getSprite());
                break;
            case Constants::TYPE::ENEMY_2:
                _enemy2->setPosition(item.x, item.y);
                _window.draw(_enemy2->getSprite());
                break;
            case Constants::TYPE::ENEMY_3:
                _enemy3->setPosition(item.x, item.y);
                _window.draw(_enemy3->getSprite());
                break;
            case Constants::TYPE::ENEMY_4:
                _enemy4->setPosition(item.x, item.y);
                _window.draw(_enemy4->getSprite());
                break;
            case Constants::TYPE::BULLET:
                _bullet->setPosition(item.x, item.y);
                _window.draw(_bullet->getSprite());
                break;
            default:
                break;
        }
    }
}

void Game::displayGame() {
    if (!_queueClass->empty())
        _window.clear();
    _parallax.moveBackgrounds(_window);
    processGameFrame();
    _window.display();
}

void Game::run() {
    Timer gameClock;
    _window.clear();
    while (handleGameEvents()) {
        gameClock.start();
        displayGame();
        sendPlayerAction();
        gameClock.end();
        gameClock.waitFrame();
    }
}
