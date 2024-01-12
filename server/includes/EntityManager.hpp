/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <list>
#include <memory>
#include <iostream>
#include "Entity.hpp"

namespace Ecs {

    class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        unsigned int createPlayer() noexcept;
        static std::shared_ptr<Entity> createMonster(int entitySize) noexcept;
        static std::shared_ptr<Entity> createMissile(int entitySize, std::pair<int, int> playerPos) noexcept;
        std::shared_ptr<Entity> getEntityById(unsigned int id);
        static int random(const int min, const int max) noexcept;
        template <class T>
        std::list<std::shared_ptr<Entity>> getEntsByComp()
        {
            std::list<std::shared_ptr<Entity>> entities;
            for (auto it : _entityList)
            {
                if (it.get()->hasComp<T>())
                    entities.push_back(it);
            }
            return entities;
        };
        template <class ...Args>
        std::list<std::shared_ptr<Entity>> &getEntsByComps()
        {
            std::list<std::shared_ptr<Entity>> entities;
            for (auto it : _entityList)
            {
                if (it.get()->hasComps<Args ...>())
                    entities.push_back(it);
            }
            return entities;
        };
    protected:
    private:
        std::list<std::shared_ptr<Entity>> _entityList;
    };

}

#endif /* !ENTITYMANAGER_HPP_ */
