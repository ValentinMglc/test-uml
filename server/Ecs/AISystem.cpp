/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** AISystem
*/

#include "AISystem.hpp"
#include "EntityManager.hpp"
#include "Components/HitBox.hpp"
#include "Components/Damages.hpp"
#include "Components/Health.hpp"
#include "Components/AI.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"
#include <cmath>

Ecs::AISystem::AISystem(std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{}

void Ecs::AISystem::update()
{
	int AInumber = NbrOfAIs();
	while (AInumber < 10) {
		_entities.push_back(EntityManager::createMonster(_entities.size()));
		AInumber++;
	}
	for (auto &entity : _entities) {
		if (entity.get()->hasComps<AI, Position, Acceleration>()) {
			moveAI(entity);
		}
	}
}

int Ecs::AISystem::NbrOfAIs()
{
	int count = 0;
	for (auto &entity : _entities) {
		if (entity.get()->hasComp<AI>())
			count++;
	}
	return count++;
}

void Ecs::AISystem::moveAI(std::shared_ptr<Entity> entity)
{
	if (entity.get()->getComp<AI>()->getPattern() == 1)
		firstPattern(entity);
	else
		secondPattern(entity);
}

void Ecs::AISystem::firstPattern(std::shared_ptr<Entity> entity)
{
	std::pair<int, int> pos = entity.get()->getComp<Position>()->getPos();
	entity.get()->getComp<Position>()->setX(pos.first - entity.get()->getComp<Acceleration>()->getAcceleration());
}

void Ecs::AISystem::secondPattern(std::shared_ptr<Entity> entity)
{
	std::pair<int, int> pos = entity.get()->getComp<Position>()->getPos();
	entity.get()->getComp<Position>()->setX(pos.first - entity.get()->getComp<Acceleration>()->getAcceleration());
	entity.get()->getComp<Position>()->setY(300 + (std::sin(pos.first / 30) * 50));
}
