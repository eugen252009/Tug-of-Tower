#pragma once
#include "raylib.h"
#include "Drawable.h"

struct Background : public BaseEntity<MapState>
{
    Background();
    ~Background() = default;
    void move();
    void draw();
    void render();
};