/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** PlayerSystem
*/

#include "PlayerSystem.hpp"
#include "Components/HitBox.hpp"
#include "Components/Damages.hpp"
#include "Components/Health.hpp"
#include "Components/AI.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"

//contructor a faire

Ecs::PlayerSystem::PlayerSystem(std::list<std::shared_ptr<Entity>> &entities, std::shared_ptr<std::list<ClientData>> actionList)
    : ASystem(entities),
    _actionList(actionList)
{}

void Ecs::PlayerSystem::update() {
    for (auto &entity : _entities) {
        if (isPlayer(entity)) {
            action(entity);
        }
    }
}

bool Ecs::PlayerSystem::isPlayer(const std::shared_ptr<Entity>& entity) const {
    return entity->hasComps<Position, Acceleration>()
        && !entity->hasComp<AI>() && !entity->hasComp<Weapon>();
}

void Ecs::PlayerSystem::action(std::shared_ptr<Entity> entity)
{
    while (!_actionList->empty()) {
        auto action = _actionList->front();
        _actionList->pop_front();

        switch (action.event) {
            case TypeEnum::Events::MOVE :
                move(entity, action.direction);
                break;
            case TypeEnum::Events::SHOOT :
                shoot(entity->getComp<Position>());
                break;
            default :
                break;
        }
    }
}

// peut etre a refaire
void Ecs::PlayerSystem::move(std::shared_ptr<Entity> entity, int dir)
{
    std::pair<int, int> pos = entity.get()->getComp<Position>()->getPos();
    if (dir == TypeEnum::Directions::LEFT)
        entity.get()->getComp<Position>()->setY(pos.second - entity.get()->getComp<Acceleration>()->getAcceleration());
    else if (dir == TypeEnum::Directions::RIGHT)
        entity.get()->getComp<Position>()->setY(pos.second + entity.get()->getComp<Acceleration>()->getAcceleration());
    else if (dir == TypeEnum::Directions::UP)
        entity.get()->getComp<Position>()->setX(pos.first - entity.get()->getComp<Acceleration>()->getAcceleration());
    else if (dir == TypeEnum::Directions::DOWN)
        entity.get()->getComp<Position>()->setX(pos.first + entity.get()->getComp<Acceleration>()->getAcceleration());
}

void Ecs::PlayerSystem::shoot(std::shared_ptr<Ecs::Position> pos)
{
    if (!pos)
        return;
    std::shared_ptr<Entity> missileEntity = EntityManager::createMissile(_entities.size(), pos->getPos());
    _entities.push_back(missileEntity);
}
