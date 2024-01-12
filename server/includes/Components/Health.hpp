/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_
#include "AComponent.hpp"

namespace Ecs {
    class Health : public AComponent {
        public:
            Health(int health = 100);
            ~Health();
            inline int getHealth() noexcept {return _health;};
            inline void setHealth(int health) noexcept {_health = health;};
        protected:
        private:
            int _health;
    };
}

#endif /* !HEALTH_HPP_ */
