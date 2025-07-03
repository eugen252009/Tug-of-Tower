#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "Player.h"

struct Tower : public BaseEntity<MobState>
{
private:
    Playernum num;

public:
    Tower(Playernum num, float x, float y);
    ~Tower() = default;
    void draw();
    void render();
    // void move(float, float);
    void move();
};