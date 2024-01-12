/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** HitBox
*/

#include "Components/HitBox.hpp"

Ecs::HitBox::HitBox(int x, int y)
    : _x(x), _y(y)
{
    _compo = TypeEnum::HITBOX;
}

Ecs::HitBox::~HitBox()
{
}
