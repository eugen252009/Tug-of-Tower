#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "Player.h"

struct Mob : BaseEntity<MobState>
{
    Mob(Playernum);
    virtual ~Mob() = default;

    void draw();
    void render();
    void move();
    void move(float dx, float dy);
    void animate();

    Rectangle getRec();
    void print(const char *msg);
};