/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Position
*/

#ifndef POSITION_HPP_
#define POSITION_HPP_
#include "AComponent.hpp"
#include <utility>

namespace Ecs {
    class Position : public AComponent {
        public:
            Position(int x = 0, int y = 0);
            ~Position();
            inline void setX(int x) noexcept { _x = x; };
            inline void setY(int y) noexcept { _y = y; };
            std::pair<int, int> getPos() noexcept { return std::make_pair(_x, _y); };
        protected:
        private:
            int _x;
            int _y;
    };
}

#endif /* !POSITION_HPP_ */
