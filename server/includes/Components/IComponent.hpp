/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include "TypeEnum.hpp"

namespace Ecs {
    class IComponent {
        public:
           virtual ~IComponent() = default;
           virtual TypeEnum::Components getComponentType() = 0;
           virtual void setComponentType(TypeEnum::Components compo) = 0;
        protected:
            TypeEnum::Components _compo;
        private:
    };
}

#endif /* !ICOMPONENT_HPP_ */
