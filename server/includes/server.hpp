/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

    #include <vector>
    #include <cstdlib>
    #include <stdlib.h>
    #include <iostream>
    #include <thread>
    #include <string>
    #include <cstdio>
    #include <ctime>
    #include <memory>
    #include <boost/bind/bind.hpp>
    #include <boost/asio.hpp>
    #include <boost/array.hpp>
    #include <memory>

    #include <boost/archive/text_oarchive.hpp>
    #include <boost/archive/text_iarchive.hpp>
    #include <boost/serialization/serialization.hpp>
    #include <boost/archive/binary_oarchive.hpp>
    #include <boost/archive/binary_iarchive.hpp>
    #include <boost/serialization/vector.hpp>
    #include <string>
    #include <boost/serialization/string.hpp>

    #include "LobbyManager.hpp"
    #include "TypeEnum.hpp"

    struct MenuData {
        int action;
        int payload;
    };

    struct ClientData {
        int playerId;
        int event;
        int direction;

        template<class Archive>
        void serialize(Archive & ar, const unsigned int version) {
            ar & event;
            ar & direction;
        }
    };

    struct ServerData {
        int index;
        int sprite_x;
        int sprite_y;
        int sprite_width;
        int sprite_height;
        int x;
        int y;

        template<class Archive>
        void serialize(Archive & ar, const unsigned int version) {
            ar & index;
            ar & sprite_x;
            ar & sprite_y;
            ar & sprite_width;
            ar & sprite_height;
            ar & x;
            ar & y;
        }
    };

    class Server {
    public:
        Server(boost::asio::io_service& io_service, std::shared_ptr<std::list<ClientData>> clientDataList);
        ~Server();

        void send(ServerData data);

    private:
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _remote_endpoint;
        std::array<char, TypeEnum::MaxPayloadSize> _recv_buffer;
        boost::asio::steady_timer _timer;

        LobbyManager _lobbyManager;
        std::shared_ptr<std::list<ClientData>> _clientActions;

        void start_receive();
        void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);
    };


#endif /* !SERVER_HPP_ */