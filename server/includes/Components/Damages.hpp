/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Damages
*/

#ifndef DAMAGES_HPP_
#define DAMAGES_HPP_
#include "AComponent.hpp"

namespace Ecs {
    class Damages : public AComponent {
        public:
            Damages(int damages = 10);
            ~Damages();
            inline int getDamages() noexcept {return _damages;};
            inline void setDamages(int damages) noexcept {_damages = damages;};
        protected:
        private:
            int _damages;
    };
}

#endif /* !DAMAGES_HPP_ */
