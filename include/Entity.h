#pragma once
#include "raylib.h"
#include "Drawable.h"

class Entity
{
public:
    float attackPoints;
    float defensePoints;
    float HP;
    float Armor;

    Entity();
    ~Entity() = default;

    float getAttackPoints();
    void hit(float dmg);
};