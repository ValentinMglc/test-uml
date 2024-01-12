/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_
#include "AComponent.hpp"

namespace Ecs {
    class AI : public AComponent {
        public:
            AI(int pattern = 0) : _pattern(pattern) { _compo = TypeEnum::AI; };
            ~AI() = default;
            inline int getPattern() {return _pattern;};
        protected:
        private:
            int _pattern;
            const bool _isAI = true;
    };
}

#endif /* !AI_HPP_ */
