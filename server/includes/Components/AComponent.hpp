/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"

namespace Ecs {
    class AComponent : public IComponent {
        public:
            virtual ~AComponent() = default;
            inline void setComponentType(TypeEnum::Components compo) { _compo = compo; };
            inline TypeEnum::Components getComponentType() { return _compo; };
        protected:
            TypeEnum::Components _compo;
        private:
    };
}

#endif /* !ACOMPONENT_HPP_ */
