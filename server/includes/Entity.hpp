/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_
#include "Components/AComponent.hpp"
#include <type_traits>
#include <list>
#include <memory>
#include <algorithm>

namespace Ecs {
    class Entity {
        public:
            Entity(unsigned int = 0);
            ~Entity();
            unsigned int getId() noexcept;
            template <class T>
            bool hasComp() noexcept
            {
                T compo;
                for (auto &comp : _components) {
                    if (comp.get()->getComponentType() == compo.getComponentType())
                        return true;
                }
                return false;
            }

            template <class T>
            bool removeComp() noexcept
            {
                T compo;
                for (auto it = _components.begin(); it != _components.end(); it++) {
                    if ((*it).get()->getComponentType() == compo.getComponentType()) {
                        _components.erase(it);
                        return true;
                    }
                }
            }

            template <class T>
            bool addComp(std::shared_ptr<T> &comp) noexcept
            {
                if (hasComp<T>())
                    return false;
                try {
                    _components.push_back(comp);
                    return true;
                } catch (std::exception &e) {
                    (void) e;
                    return false;
                }
                return true;
            }

            template <class T>
            std::shared_ptr<T> getComp() noexcept
            {
                T compo;
                if (!hasComp<T>())
                    return nullptr;
                for (auto it = _components.begin(); it != _components.end(); it++) {
                    if ((*it).get()->getComponentType() == compo.getComponentType()) {
                        return std::static_pointer_cast<T>(*it);
                    }
                }
                return nullptr;
            }

            template <class T1, class T2, class... Args>
            bool hasComps()
            {
                T1 _Comps;
                if (hasComp<T1>()) {
                    return (true && hasComps<T2, Args...>());
                }
                return false;
            }

        protected:
        private:
            std::list<std::shared_ptr<AComponent>> _components;
            unsigned int _id;
            template <class T1>
            bool hasComps()
            {
                T1 _Comps;
                return hasComp<T1>();
            }
    };
}

#endif /* !ENTITY_HPP_ */
