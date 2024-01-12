/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** WeaponSystem
*/

#ifndef WEAPONSYSTEM_HPP_
#define WEAPONSYSTEM_HPP_
#include "ASystem.hpp"

namespace Ecs {
    class WeaponSystem : public ASystem {
        public:
            WeaponSystem(std::list<std::shared_ptr<Entity>> &entities);
            void update() override;
        protected:
        private:
            void moveWeapon(std::shared_ptr<Entity> entity);

    };
}

#endif /* !WEAPONSYSTEM_HPP_ */
