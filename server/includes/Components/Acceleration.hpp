/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Acceleration
*/

#ifndef ACCELERATION_HPP_
#define ACCELERATION_HPP_

#include "AComponent.hpp"


namespace Ecs {
    class Acceleration : public AComponent{
        public:
            Acceleration(int acceleration = 2);
            ~Acceleration();
            inline void setAcceleration(int acceleration) noexcept { _acceleration = acceleration; };
            inline int getAcceleration() const noexcept { return _acceleration; };
        protected:
        private:
            int _acceleration;
    };
}

#endif /* !ACCELERATION_HPP_ */
