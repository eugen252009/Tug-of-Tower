#pragma once
#include "raylib.h"
#include "Drawable.h"

struct UI : public BaseEntity<UIState>
{
private:
    Rectangle SLOT;
    Rectangle SELECTED;
    int SELECTEDSLOT = 0;

public:
    UI();
    ~UI() = default;
    void draw();
    void render();
    void move();
    void drawSlot(float, int);
};