/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** ISystem
*/

#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

namespace Ecs {
    class ISystem {
        public:
            virtual ~ISystem() = default;
            virtual void update() = 0;
        protected:
        private:
    };
}

#endif /* !ISYSTEM_HPP_ */
