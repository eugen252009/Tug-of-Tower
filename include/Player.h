#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "Entity.h"
#include "spritemanager.h"

struct Player : public BaseEntity<PlayerState>
{
    Playernum side;
    Player(Rectangle, Vector2, Playernum);
    ~Player() = default;

    void move();
    void move(float, float);

    void draw();
    void render();
    void animate();

    void setIdle();
    void setWalking();

    float getAttackPoints();
    void getDmg(float);
};
