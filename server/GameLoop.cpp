/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** GameLoop
*/

#include "includes/GameLoop.hpp"
#include "includes/Timer.hpp"
GameLoop::GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list, boost::asio::io_service &iso)
    : _AISystem(list),
        _actionList(new std::list<ClientData>),
        _server(new Server(iso, _actionList)),
        _sending(list, *_server),
        _playerSystem(list, _actionList),
        _weaponSystem(list)
{
}

void GameLoop::update()
{
    Timer timer;
    while (true) {
        timer.start();
        if (!_actionList->empty()) {
            _playerSystem.update();
        }
        _AISystem.update();
        //_hitboxSystem.run();
        _sending.update();
        _weaponSystem.update();
        timer.end();
        timer.waitFrame();
    }
}
