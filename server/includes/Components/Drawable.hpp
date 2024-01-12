/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_
#include "AComponent.hpp"

namespace Ecs {
    class Drawable : public AComponent {
        public:
            Drawable(int SpriteSI = 1, std::pair<int, int> SpritePos = {0, 0}, std::pair<int, int> SpriteSize = {0, 0});
            ~Drawable();
            int getSpriteSI() const;
            void setSpritePos(std::pair<int, int> SpritePos);
            void setSpriteSize(std::pair<int, int> SpriteSize);
            std::pair<int, int> &getSpritePos();
            std::pair<int, int> &getSpriteSize();
        protected:
        private:
            int _SpriteSI;
            std::pair<int, int> _SpritePos;
            std::pair<int, int> _SpriteSize;
    };
}

#endif /* !DRAWABLE_HPP_ */
