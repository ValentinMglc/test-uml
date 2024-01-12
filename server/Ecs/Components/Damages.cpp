/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Damages
*/

#include "Components/Damages.hpp"

Ecs::Damages::Damages(int damages)
    : _damages(damages)
{
    _compo = TypeEnum::DAMAGES;
}

Ecs::Damages::~Damages()
{
}