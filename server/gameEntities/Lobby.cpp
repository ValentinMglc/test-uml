/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Lobby
*/

#include "../includes/Lobby.hpp"
#include <iostream>

Lobby::Lobby(int id) : _id(id), _playerId(1)
{
    _state = WAITING;
}

int Lobby::getId() const
{
    return this->_id;
}

void Lobby::addPlayer(boost::asio::ip::udp::endpoint endpoint) {
    auto player = std::make_shared<Player>(endpoint, _playerId++);
    _players.push_back(player);
}

std::vector<std::shared_ptr<Player>> Lobby::getPlayers() const {
    return _players;
}

LobbyState Lobby::getState() const {
    return _state;
}

void Lobby::startGame()
{
    if (_state == WAITING)
        _state = IN_GAME;
}

void Lobby::pauseGame() {
    _state = PAUSED;
}

void Lobby::resumeGame() {
    _state = IN_GAME;
}

void Lobby::gameOver() {
    _state = FINISHED;
}

std::shared_ptr<Player> Lobby::getPlayerByEndpoint(boost::asio::ip::udp::endpoint endpoint) {
    for (auto player : _players) {
        if (player->getEndpoint() == endpoint)
            return player;
    }
    return nullptr;
}
