/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** AISystem
*/

#ifndef AISYSTEM_HPP_
#define AISYSTEM_HPP_
#include "ASystem.hpp"

namespace Ecs {
    class AISystem : public ASystem {
        public:
            AISystem(std::list<std::shared_ptr<Entity>> &entities);
            void update() override;
        protected:
        private:
            int NbrOfAIs();
            void moveAI(std::shared_ptr<Entity> entity);
            void firstPattern(std::shared_ptr<Entity> entity);
            void secondPattern(std::shared_ptr<Entity> entity);
    };
}

#endif /* !AISYSTEM_HPP_ */
