/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Position
*/

#include "Components/Position.hpp"

Ecs::Position::Position(int x, int y)
    : _x(x), _y(y)
{
    _compo = TypeEnum::POSITION;
}

Ecs::Position::~Position()
{
}
