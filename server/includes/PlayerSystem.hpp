/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** PlayerSystem
*/

#ifndef PLAYERSYSTEM_HPP_
#define PLAYERSYSTEM_HPP_
#include "ASystem.hpp"
#include "TypeEnum.hpp"
#include "EntityManager.hpp"
#include "Components/Position.hpp"
#include "server.hpp"

namespace Ecs {
    class PlayerSystem : public ASystem {
        public:
            //le constructeur doit prendre en parametre la queue  + struct composé du namePlayer un std::string d'un int event et d'une direction en int
            //PlayerSystem(std::list<std::shared_ptr<Entity>> &entities, std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> queue);
            PlayerSystem(std::list<std::shared_ptr<Entity>> &entities, std::shared_ptr<std::list<ClientData>> actionList);
            void update() override;
        protected:
        private:
            bool isPlayer(const std::shared_ptr<Entity>& entity) const;
            void action(std::shared_ptr<Entity> entity);
            void move(std::shared_ptr<Entity> entity, int dir);
            void shoot(std::shared_ptr<Ecs::Position> pos);
            std::shared_ptr<std::list<ClientData>> _actionList;
    };
}

#endif /* !PLAYERSYSTEM_HPP_ */
