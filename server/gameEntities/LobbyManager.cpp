/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** LobbyManager
*/

#include "../includes/LobbyManager.hpp"

LobbyManager::LobbyManager() : _lobbyId(1)
{
}

std::shared_ptr<Lobby> LobbyManager::createLobby(boost::asio::ip::udp::endpoint endpoint)
{
    auto lobby = std::make_shared<Lobby>(this->_lobbyId++);

    lobby->addPlayer(endpoint);
    this->_lobbies.push_back(lobby);
    return lobby;
}

void LobbyManager::removeLobby(std::shared_ptr<Lobby> lobby) {
    _lobbies.erase(std::remove(_lobbies.begin(), _lobbies.end(), lobby), _lobbies.end());
}

std::shared_ptr<Lobby> LobbyManager::getLobbyById(int id) {
    for (auto& lobby : _lobbies) {
        if (lobby->getId() == id) {
            return lobby;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Lobby>> LobbyManager::getLobbies() const {
    return _lobbies;
}

bool LobbyManager::addPlayerToLobby(boost::asio::ip::udp::endpoint endpoint, int lobbyId) {
    auto lobby = getLobbyById(lobbyId);
    
    if (lobby && lobby->getPlayers().size() < 4) {
        lobby->addPlayer(endpoint);
        return true;
    }
    return false;
}

std::shared_ptr<Lobby> LobbyManager::findLobbyByPlayerEndpoint(boost::asio::ip::udp::endpoint endpoint) {
    for (auto& lobby : _lobbies) {
        for (auto& player : lobby->getPlayers()) {
            if (player->getEndpoint() == endpoint) {
                return lobby;
            }
        }
    }
    return nullptr;
}

