/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Lobby
*/

#ifndef LOBBY_HPP_
#define LOBBY_HPP_

    #include "Player.hpp"
    #include <memory>
    #include <vector>
    #include <boost/asio.hpp>

    enum LobbyState {
        WAITING,
        IN_GAME,
        PAUSED,
        FINISHED
    };

    class Lobby {
    public:
        Lobby(int id);
        ~Lobby() = default;

        int getId() const;
        void addPlayer(boost::asio::ip::udp::endpoint endpoint);
        std::vector<std::shared_ptr<Player>> getPlayers() const;
        std::shared_ptr<Player> getPlayerByEndpoint(boost::asio::ip::udp::endpoint endpoint);

        LobbyState getState() const;
        void startGame();
        void pauseGame();
        void resumeGame();
        void gameOver();

    private:
        int _id;
        int _playerId;
        LobbyState _state;
        std::vector<std::shared_ptr<Player>> _players;
    };

#endif /* !LOBBY_HPP_ */
