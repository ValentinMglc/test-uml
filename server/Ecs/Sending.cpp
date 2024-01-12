/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Sending
*/

#include "Sending.hpp"
#include "Components/Drawable.hpp"
#include "Components/Position.hpp"

Ecs::Sending::Sending(std::list<std::shared_ptr<Entity>> &entities, Server &server) : ASystem(entities), _server(server)
{
}

void Ecs::Sending::update()
{
    std::shared_ptr<Entity> toRemove;
    bool isRemoved = false;

    for (auto &entity : _entities) {
        if (entity->hasComps<Drawable, Position>()) {
            std::pair<int, int> pos = entity->getComp<Position>()->getPos();
            std::pair<int, int> size = entity->getComp<Drawable>()->getSpriteSize();
            if (pos.first < size.first * -1 || pos.first > 2000) {
                toRemove = entity;
                isRemoved = true;
            } else {
                sendToClient(entity);
            }
        }
    }
}

void Ecs::Sending::sendToClient(std::shared_ptr<Entity> &entity)
{
    std::shared_ptr<Drawable> toDrawComp = entity.get()->getComp<Drawable>();
    std::shared_ptr<Position> toPosComp = entity.get()->getComp<Position>();

    _server.send({toDrawComp.get()->getSpriteSI(),
                    toDrawComp.get()->getSpritePos().first,
                    toDrawComp.get()->getSpritePos().second,
                    toDrawComp.get()->getSpriteSize().first,
                    toDrawComp.get()->getSpriteSize().second,
                    toPosComp.get()->getPos().first,
                    toPosComp.get()->getPos().second});
}
