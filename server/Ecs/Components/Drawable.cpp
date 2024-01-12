/*
** EPITECH PROJECT, 2024
** B-CPP-500-NCY-5-2-rtype-anthony.dacremont-rodriguez
** File description:
** Drawable
*/

#include "Components/Drawable.hpp"

Ecs::Drawable::Drawable(int SpriteSI, std::pair<int, int> SpritePos, std::pair<int, int> SpriteSize)
    : _SpriteSI(SpriteSI), _SpritePos(SpritePos), _SpriteSize(SpriteSize)
{
    _compo = TypeEnum::DRAWABLE;
}

Ecs::Drawable::~Drawable()
{
}

void Ecs::Drawable::setSpriteSize(std::pair<int, int> SpriteSize)
{
    _SpriteSize.first = SpriteSize.first;
    _SpriteSize.second = SpriteSize.second;
}

void Ecs::Drawable::setSpritePos(std::pair<int, int> SpritePos)
{
    _SpritePos.first = SpritePos.first;
    _SpritePos.second = SpritePos.second;
}

int Ecs::Drawable::getSpriteSI() const
{
    return _SpriteSI;
}

std::pair<int, int> &Ecs::Drawable::getSpritePos()
{
    return _SpritePos;
}

std::pair<int, int> &Ecs::Drawable::getSpriteSize()
{
    return _SpriteSize;
}