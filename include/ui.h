#pragma once
#include "raylib.h"
#include "Drawable.h"
#include "Player.h"

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
    void render(Player *);
    void move();
    void drawSlot(float, int);
};