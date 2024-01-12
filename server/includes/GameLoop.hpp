/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** GameLoop
*/

#ifndef GAMELOOP_HPP_
#define GAMELOOP_HPP_
#include "WeaponSystem.hpp"
#include "server.hpp"
//faire la hitboxsystem.hpp
#include "AISystem.hpp"
#include "Sending.hpp"
#include "PlayerSystem.hpp"
#include <list>

class GameLoop {
    public:
        GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list, boost::asio::io_service &iso);
        void update();
    protected:
    private:
        //Ecs::HitboxSystem _hitboxSystem;
        Ecs::AISystem _AISystem;
        std::shared_ptr<std::list<ClientData>> _actionList; // a voir si on veut un std::shared_ptr
        Server *_server;
        //Ecs::FrameSendingSystem _frameSendingSystem;
        Ecs::PlayerSystem _playerSystem;
        Ecs::WeaponSystem _weaponSystem;
        Ecs::Sending _sending;
};

#endif /* !GAMELOOP_HPP_ */
