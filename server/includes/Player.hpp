/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

    #include <boost/asio.hpp>

    class Player {
        public:
            Player(boost::asio::ip::udp::endpoint endpoint, int id);
            ~Player();

            boost::asio::ip::udp::endpoint getEndpoint() const;
            void setEndpoint(boost::asio::ip::udp::endpoint endpoint);
            int getId() const;

        protected:
        private:
            boost::asio::ip::udp::endpoint _endpoint;
            int _id;

    };

#endif /* !PLAYER_HPP_ */
