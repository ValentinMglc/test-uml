/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Health
*/

#include "Components/Health.hpp"

Ecs::Health::Health(int health)
    : _health(health)
{
    _compo = TypeEnum::HEALTH;
}

Ecs::Health::~Health()
{
}
