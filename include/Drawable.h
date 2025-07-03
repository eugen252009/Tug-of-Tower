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
    float health = 100;
    float attackPoints = 10;
    T state;
    SpriteEntity entityType;

    std::unordered_map<float, float> timers;
    Rectangle position = {0, 0, 0, 0};
    Vector2 speed = {0, 0};

    Sprites texture;
    Playernum side = Playernum::PLAYER1;
    float frame;
    bool isDead = false;

    virtual void move();
    virtual void draw();
    virtual void render();
    bool readyForNextFrame(float);
    void animate();

    bool Dmg(float);

    void setState(T);
    Rectangle getPos();

    virtual ~BaseEntity() = default;
};
