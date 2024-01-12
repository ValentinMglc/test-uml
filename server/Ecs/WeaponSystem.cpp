/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** WeaponSystem
*/

#include "Components/Acceleration.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"
#include "WeaponSystem.hpp"

Ecs::WeaponSystem::WeaponSystem(std::list<std::shared_ptr<Entity>> &entities) : ASystem(entities)
{
}

void Ecs::WeaponSystem::update()
{
    for (auto &entity : _entities) {
        if (entity.get()->hasComps<Weapon, Position, Acceleration>()) {
            moveWeapon(entity);
        }
    }
}

void Ecs::WeaponSystem::moveWeapon(std::shared_ptr<Entity> entity)
{
    std::pair<int, int> pos = entity.get()->getComp<Position>()->getPos();
    entity.get()->getComp<Position>()->setX(pos.first + entity.get()->getComp<Acceleration>()->getAcceleration());
}