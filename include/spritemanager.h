#pragma once
#include <unordered_map>
#include "raylib.h"
#include "State.h"

struct Sprites
{
    Texture2D sprite;
    Rectangle rect;
    float animwidth;
};

template <typename T>
class SpriteManager
{
private:
    inline static std::unordered_map<SpriteEntity, std::unordered_map<T, Sprites *>> spriteMap;

public:
    ~SpriteManager() = default;
    static void init();

    static Sprites *getSprite(SpriteEntity entitiy, T state);
};
