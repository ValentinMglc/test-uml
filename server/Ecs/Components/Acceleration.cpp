/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Acceleration
*/

#include "Components/Acceleration.hpp"

Ecs::Acceleration::Acceleration(int acceleration)
    : _acceleration(acceleration)
{
    _compo = TypeEnum::ACCELERATION;
}

Ecs::Acceleration::~Acceleration()
{
}

