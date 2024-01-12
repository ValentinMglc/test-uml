/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Main
*/

#include "includes/server.hpp"
#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Components/Position.hpp"
#include "GameLoop.hpp"

bool isOnlyDigits(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main(int ac, char **av) {

    boost::asio::io_service io_service;
    Ecs::EntityManager entityManager;

    if (ac != 2) {
        std::cerr << "Usage: ./r-type_server <port>" << std::endl;
        return 84;
    }
    if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
        std::cout << "Usage: ./r-type_server <port>" << std::endl;
        return 0;
    }
    if (!isOnlyDigits(av[1])) {
        std::cerr << "Port must be a number" << std::endl;
        return 84;
    }
    if (std::atoi(av[1]) < 0 || std::atoi(av[1]) > 65535) {
        std::cerr << "Port must be between 0 and 65535" << std::endl;
        return 84;
    }
    try {
        entityManager.createPlayer();
        std::list<std::shared_ptr<Ecs::Entity>> entityList =
		entityManager.getEntsByComp<Ecs::Position>();
        GameLoop game(entityList, io_service);
        game.update();
        io_service.run();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    io_service.stop();
    return 0;
}
