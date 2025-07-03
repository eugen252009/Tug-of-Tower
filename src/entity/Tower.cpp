#include "Tower.h"
#include "Player.h"
#include "stdio.h"

Tower::Tower(Playernum num, float x, float y)
{
    this->position.y = y;
    this->position.x = x;
    this->num = num;
    switch (num)
    {
    case Playernum::PLAYER1:
    {

        texture = *SpriteManager<TowerState>::getSprite(SpriteEntity::Tower, TowerState::Idle);
    }
    break;
    case Playernum::PLAYER2:
    {
        texture = *SpriteManager<TowerState>::getSprite(SpriteEntity::Tower2, TowerState::Idle);
    }
    break;
    }
}

void Tower::draw()
{
    DrawTexturePro(texture.sprite, texture.rect, {position.x - 64, position.y - 128, texture.rect.width, texture.rect.height}, {0, 0}, 0, WHITE);
}
void Tower::render() {};
void Tower::move() {};