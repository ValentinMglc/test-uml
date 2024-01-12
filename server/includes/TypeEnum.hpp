/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** TypeEnum
*/

#ifndef TYPEENUM_HPP_
#define TYPEENUM_HPP_

#include <utility>

namespace TypeEnum
{
    enum Components {
        AI,
        WEAPON,
        DRAWABLE,
        HITBOX,
        POSITION,
        DAMAGES,
        HEALTH,
        ACCELERATION,
    };

    enum Actions {
        OK = 0,
        KO = 84,
        CREATE = 100,
        JOIN = 101,
        READY = 102,
    };

    enum Events {
        QUIT = 200,
        SHOOT = 201,
        MOVE = 202,
    };

    enum Directions {
        UP = 300,
        DOWN = 301,
        LEFT = 302,
        RIGHT = 303,
    };

    enum TYPE {
        UNKNOW,
        PLAYER_1,
        PLAYER_2,
        PLAYER_3,
        PLAYER_4,
        ENEMY_1,
        ENEMY_2,
        ENEMY_3,
        ENEMY_4,
        BULLET
    };

    const std::size_t MaxPayloadSize = 1024;
    const int WindowHeight = 1080;
    const int WindowWidth = 1920;
}

#endif /* !TYPEENUM_HPP_ */
