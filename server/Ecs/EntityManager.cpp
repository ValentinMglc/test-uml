/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** EntityManager
*/

#include "EntityManager.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Components/Health.hpp"
#include "Components/Position.hpp"
#include "Components/Damages.hpp"
#include "Components/HitBox.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"
#include "Components/AI.hpp"
#include "Components/Drawable.hpp"
#include "TypeEnum.hpp"
#include "EntityManager.hpp"

Ecs::EntityManager::EntityManager()
{
}

Ecs::EntityManager::~EntityManager()
{}

int Ecs::EntityManager::random(int min, int max) noexcept
{
    std::mt19937 generator;
    generator.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

    return (static_cast<int>(dist(generator)));
}

unsigned int Ecs::EntityManager::createPlayer() noexcept
{
    unsigned int id = _entityList.size() + 1;
    std::shared_ptr<Entity> playerEntity(new Entity(id));

    // Create all the components for the player
    std::shared_ptr<Drawable> drawComponent(
        new Drawable(1, std::make_pair(0,0), std::make_pair(64,24)));
    std::shared_ptr<Acceleration> accComponent(
        new Acceleration(10));
    std::shared_ptr<Health> healthComponent(
        new Health(200));
    std::shared_ptr<Damages> damagesComponent(
        new Damages(20));
    std::shared_ptr<Position> posComponent(
        new Position(100,100));
    std::shared_ptr<HitBox> hitboxComponent(
        new HitBox(64,64));

    // Add components to the entity
    playerEntity->addComp<Acceleration>(accComponent);
    playerEntity->addComp<Health>(healthComponent);
    playerEntity->addComp<Damages>(damagesComponent);
    playerEntity->addComp<Position>(posComponent);
    playerEntity->addComp<HitBox>(hitboxComponent);
    playerEntity->addComp<Drawable>(drawComponent);
    _entityList.push_back(playerEntity);
    return id;
}

std::shared_ptr<Ecs::Entity> Ecs::EntityManager::createMonster(
    int entitySize) noexcept
{
    int randomAI = random(1, 2);
    int randomY = random(1, 800);

    unsigned int id = entitySize + 1;
    std::shared_ptr<Entity> monsterEntity(new Entity(id));

    // Create all the components for the monster
    std::shared_ptr<Drawable> drawComponent(
        new Drawable(randomAI + 1, std::make_pair(0,0), std::make_pair(64,56)));
    std::shared_ptr<Acceleration> accComponent(
        new Acceleration(7));
    std::shared_ptr<Health> healthComponent(
        new Health(100));
    std::shared_ptr<Damages> damagesComponent(
        new Damages(10));
    std::shared_ptr<Position> posComponent(
        new Position(1300,
        randomY));
    std::shared_ptr<HitBox> hitboxComponent(
        new HitBox(64,64));
    std::shared_ptr<AI> aiComponent(new AI(randomAI));

    // Add components to the entity
    monsterEntity->addComp<Acceleration>(accComponent);
    monsterEntity->addComp<Health>(healthComponent);
    monsterEntity->addComp<Damages>(damagesComponent);
    monsterEntity->addComp<Position>(posComponent);
    monsterEntity->addComp<HitBox>(hitboxComponent);
    monsterEntity->addComp<AI>(aiComponent);
    monsterEntity->addComp<Drawable>(drawComponent);
    return monsterEntity;
}

std::shared_ptr<Ecs::Entity> Ecs::EntityManager::createMissile(int entitySize, std::pair<int, int> playerPos) noexcept
{
    unsigned int id = entitySize + 1;
    std::shared_ptr<Entity> missileEntity(new Entity(id));

    // Create all the components for the missile
    std::shared_ptr<Drawable> drawComponent(
        new Drawable(4, std::make_pair(0,0), std::make_pair(12,48)));
    std::shared_ptr<Acceleration> accComponent(
        new Acceleration(20));
    std::shared_ptr<Health> healthComponent(
        new Health(1));
    std::shared_ptr<Damages> damagesComponent(
        new Damages(100));
    std::shared_ptr<Position> posComponent(
        new Position(playerPos.first + 10 + 64,
        playerPos.second + (24 / 2)));
    std::shared_ptr<HitBox> hitboxComponent(
        new HitBox(12,12));
    std::shared_ptr<Weapon> weaponComponent(new Weapon());

    // Add components to the entity
    missileEntity->addComp<Acceleration>(accComponent);
    missileEntity->addComp<Health>(healthComponent);
    missileEntity->addComp<Damages>(damagesComponent);
    missileEntity->addComp<Position>(posComponent);
    missileEntity->addComp<HitBox>(hitboxComponent);
    missileEntity->addComp<Weapon>(weaponComponent);
    missileEntity->addComp<Drawable>(drawComponent);
    return missileEntity;
}

std::shared_ptr<Ecs::Entity> Ecs::EntityManager::getEntityById(unsigned int id)
{
    for (auto &y : _entityList) {
        if (y->getId() == id)
            return y;
    }
    throw std::runtime_error("EventManager: getEntityById: id not found");
}

