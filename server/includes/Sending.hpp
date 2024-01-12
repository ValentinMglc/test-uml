/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Sending
*/

#ifndef SENDING_HPP_
#define SENDING_HPP_
#include <boost/asio.hpp>
#include "ASystem.hpp"
#include "server.hpp"


// A faire

namespace Ecs {
    class Sending : public ASystem {
        public:
            Sending(std::list<std::shared_ptr<Entity>> &entities, Server &server);
            void update() override;
        protected:
        private:
            void sendToClient(std::shared_ptr<Entity> &entity);
            Server &_server;
    };
}

#endif /* !SENDING_HPP_ */
