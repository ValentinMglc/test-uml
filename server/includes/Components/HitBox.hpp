/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** HitBox
*/

#ifndef HITBOX_HPP_
#define HITBOX_HPP_
#include "AComponent.hpp"
#include <utility>

namespace Ecs {
    class HitBox : public AComponent {
        public:
            HitBox(int x = 50, int y = 50);
            ~HitBox();
            inline std::pair<int, int> getHitBox() {return std::pair<int, int>(_x, _y);};
            inline void setHitBox(std::pair<int, int> hitBox) noexcept {_x = hitBox.first; _y = hitBox.second;};
        protected:
        private:
            int _x;
            int _y;
    };
}

#endif /* !HITBOX_HPP_ */
