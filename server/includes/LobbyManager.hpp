/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** LobbyManager
*/

#ifndef LOBBYMANAGER_HPP_
#define LOBBYMANAGER_HPP_

    #include "Lobby.hpp"
    #include <vector>
    #include <map>
    #include <list>
    #include <memory>

    class LobbyManager {
    public:
        LobbyManager();
        ~LobbyManager() = default; // Avec les smart pointers, le destructeur par défaut est souvent suffisant

        std::shared_ptr<Lobby> createLobby(boost::asio::ip::udp::endpoint endpoint);
        void removeLobby(std::shared_ptr<Lobby> lobby);

        std::shared_ptr<Lobby> getLobbyById(int id);
        std::vector<std::shared_ptr<Lobby>> getLobbies() const;

        bool addPlayerToLobby(boost::asio::ip::udp::endpoint endpoint, int lobbyId);
        std::shared_ptr<Lobby> findLobbyByPlayerEndpoint(boost::asio::ip::udp::endpoint endpoint);
        void removePlayerFromLobby(boost::asio::ip::udp::endpoint endpoint);

        void startGame(int lobbyId);
        void stopGame(int lobbyId);

    private:
        int _lobbyId;
        std::vector<std::shared_ptr<Lobby>> _lobbies;
    };

#endif /* !LOBBYMANAGER_HPP_ */
