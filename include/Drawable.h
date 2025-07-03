#pragma once
#include <unordered_map>
#include <cmath>
#include "vector"
#include "raylib.h"
#include "spritemanager.h"
#include "State.h"

template <typename T>
struct BaseEntity
{
    // typename StateTraits<T>::Type state;
    float health = 100;
    float attackPoints = 10;

    std::unordered_map<float, float> timers;
    Rectangle position = {0, 0, 0, 0};
    Vector2 speed = {0, 0};

    Sprites texture;
    float frame;
    bool isDead = false;

    virtual void move();
    virtual void draw();
    virtual void render();
    bool readyForNextFrame(float);
    virtual ~BaseEntity() = default;
    void animate();

    void Dmg(float);
    Rectangle getPos();
};
