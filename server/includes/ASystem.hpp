/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** ASystem
*/

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_
#include "ISystem.hpp"
#include "Entity.hpp"
#include <memory>
#include <list>

namespace Ecs {
    class ASystem : public ISystem {
        public:
            ASystem(std::list<std::shared_ptr<Entity>> &entities) : _entities(entities) {};
        protected:
            std::list<std::shared_ptr<Entity>> &_entities;
        private:
    };
}

#endif /* !ASYSTEM_HPP_ */
