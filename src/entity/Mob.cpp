#include "raylib.h"
#include "Mob.h"
#include "Player.h"
#include <stdio.h>

Mob::Mob(Playernum num)
{
    this->side = num;
    switch (num)
    {
    case Playernum::PLAYER1:
        health = 110;
        position = {
            .x = 20,
            .y = (float)GetScreenHeight() / 2,
            .width = 128,
            .height = 128,
        };
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team1_Warrior, MobState::Idle);
        break;
    case Playernum::PLAYER2:
        position = {
            .x = (float)GetScreenWidth() - 200,
            .y = (float)GetScreenHeight() / 2,
            .width = 128,
            .height = 128,
        };
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team2_Warrior, MobState::Idle);
        break;
    }
};

void Mob::draw()
{
    if (side == Playernum::PLAYER1)
    {
        DrawTexturePro(texture.sprite, {192.0f * frame + 40, 46.0f, 94, 92}, position, {0, 0}, 0, WHITE);
    }
    else
    {
        DrawTexturePro(texture.sprite, {192.0f * (frame + 1) + 40, 46.0f, -94, 92}, position, {0, 0}, 0, WHITE);
    }
    DrawRectangle(position.x + position.width / 2 - 50, position.y - 30, health, 20, GREEN);
};
void Mob::render()
{
    if (readyForNextFrame(0.1f))
        animate();
    if (side == Playernum::PLAYER1)
    {
        move(1, 0);
    }
    else
    {
        move(-1, 0);
    }
};
Rectangle Mob::getRec()
{
    return position;
}
void Mob::move()
{
    position.x += speed.x;
    position.y += speed.y;

    speed.x *= 0.9f;
    speed.y *= 0.9f;
    if (position.x > GetScreenWidth() - position.width)
    {
        isDead = true;
        position.x = GetScreenWidth() - position.width;
    };
    if (position.x < 0)
    {
        isDead = true;
        position.x = 0;
    };
    if (position.y > GetScreenHeight() - position.height)
    {
        isDead = true;
        position.y = GetScreenHeight() - position.height;
    };
    if (position.y < 0)
    {
        isDead = true;
        position.y = 0;
    };
    if (speed.x < 0.1f && speed.x > -0.1f)
        speed.x = 0;
    if (speed.y < 0.1 && speed.y > -0.1f)
        speed.y = 0;
};

void Mob::move(float dx, float dy)
{
    speed.x = dx * 0.9f;
    speed.y = dy * 0.9f;
    move();
};
void Mob::animate()
{
    if (speed.x == 0 && speed.y == 0)
    {
        setIdle();
    }
    else
    {
        setWalking();
    }
    frame++;
    frame = (int)frame % (int)texture.animwidth;
};
void Mob::setIdle()
{
    switch (side)
    {
    case Playernum::PLAYER1:
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team1_Warrior, MobState::Idle);
        break;
    case Playernum::PLAYER2:
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team2_Warrior, MobState::Idle);
        break;
    }
};

void Mob::setWalking()
{
    switch (side)
    {
    case Playernum::PLAYER1:
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team1_Warrior, MobState::Walking);
        break;
    case Playernum::PLAYER2:
        texture = *SpriteManager<MobState>::getSprite(SpriteEntity::Team2_Warrior, MobState::Walking);
        break;
    }
};

void Mob::print(const char *msg)
{
    printf("------------ %s ------------\n", msg);
    printf("x: %.0f\n", position.x);
    printf("y: %.0f\n", position.y);
    printf("width: %.0f\n", position.width);
    printf("height: %.0f\n", position.height);
    printf("sprite id: %d\n", texture.sprite.id);
    printf("------------ /%s ------------\n\n", msg);
};