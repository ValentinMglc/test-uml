/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Weapon
*/

#ifndef WEAPON_HPP_
#define WEAPON_HPP_
#include "AComponent.hpp"

namespace Ecs {
    class Weapon : public AComponent{
        public:
            Weapon()
            {
                _compo = TypeEnum::WEAPON;
            };
            ~Weapon() {};
            inline bool isWeapon() {return true;};
        protected:
        private:
            const bool _isWeapon = true;
    };
}

#endif /* !WEAPON_HPP_ */
