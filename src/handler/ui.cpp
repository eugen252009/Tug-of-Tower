#include "raylib.h"
#include "ui.h"
#include "spritemanager.h"

#define SLOTS 6
#define SLOTHEIGHT 64
#define SLOTWIDTH 64
#define SLOTGAP 2

UI::UI()
{
    texture = *SpriteManager<UIState>::getSprite(SpriteEntity::UI, UIState::Slot);
    SELECTED = Rectangle{448, 128, 32, 32};
    SLOT = Rectangle{320, 128, 32, 32};
    SELECTEDSLOT = 0;
}

void UI::drawSlot(float begin, int n)
{
    if (n == SELECTEDSLOT)
    {
        DrawTexturePro(texture.sprite, SELECTED, {begin + ((SLOTWIDTH + SLOTGAP) * n), (float)GetScreenHeight() - SLOTHEIGHT - 10, SLOTWIDTH, SLOTHEIGHT}, {0, 0}, 0.0f, WHITE);
    }
    else
    {
        DrawTexturePro(texture.sprite, SLOT, {begin + ((SLOTWIDTH + SLOTGAP) * n), (float)GetScreenHeight() - SLOTHEIGHT - 10, SLOTWIDTH, SLOTHEIGHT}, {0, 0}, 0.0f, WHITE);
    }
}

void UI::draw()
{
    int start = (GetScreenWidth() / 2) - ((SLOTWIDTH + SLOTGAP) * (SLOTS / 2));
    for (size_t i = 0; i < SLOTS; i++)
    {
        drawSlot(start, i);
    }
}

void UI::render()
{
    if (GetMouseWheelMove() > 0)
    {
        SELECTEDSLOT += 1;
        SELECTEDSLOT %= SLOTS;
    }
    else if (GetMouseWheelMove() < 0)
    {
        if (SELECTEDSLOT == 0)
        {
            SELECTEDSLOT = SLOTS - 1;
        }
        else
        {
            SELECTEDSLOT -= 1;
            SELECTEDSLOT %= SLOTS;
        }
    }
}

void UI::move() {};