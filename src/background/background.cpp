#include "background.h"

Background::Background()
{
    texture = *SpriteManager<MapState>::getSprite(SpriteEntity::Map, MapState::Idle);
};

void Background::draw()
{
    DrawTexturePro(texture.sprite, texture.rect, {25, 100, (float)GetScreenWidth() - 50, (float)GetScreenHeight() - 200}, {0, 0}, 0, WHITE);
};
void Background::render() {};
void Background::move() {};
