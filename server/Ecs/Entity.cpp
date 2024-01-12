/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Entity
*/

#include "Entity.hpp"

Ecs::Entity::Entity(unsigned int id)
    : _id(id)
{
}

Ecs::Entity::~Entity()
{
}

unsigned int Ecs::Entity::getId() noexcept
{
    return _id;
}
