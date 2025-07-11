#include "raylib.h"
#include "Mob.h"
#include "Player.h"
#include <stdio.h>

Mob::Mob(Playernum num)
{
    // init for Player1
    this->entityType = SpriteEntity::Team1_Warrior;
    this->side = num;
    this->health = 110;
    this->speed.x = 1;
    this->position = {
        .x = 20,
        .y = (float)GetScreenHeight() / 2,
        .width = 128,
        .height = 128,
    };
    if (side == Playernum::PLAYER2)
    {
        // changes for Player2
        this->health = 100;
        this->entityType = SpriteEntity::Team2_Warrior;
        this->speed.x = -1;
        this->position = {
            .x = (float)GetScreenWidth() - 200,
            .y = (float)GetScreenHeight() / 2,
            .width = 128,
            .height = 128,
        };
    }

    this->texture = *SpriteManager<MobState>::getSprite(this->entityType, MobState::Idle);
    setState(MobState::Walking);
};

void Mob::draw()
{
    // this desides which side to render, default left and if player2 right
    Rectangle src = {192.0f * frame + 60, 46.0f, 94, 92};
    if (side == Playernum::PLAYER2)
        src = {192.0f * (frame + 1) + 60, 46.0f, -94, 92};
    DrawTexturePro(texture.sprite, src, position, {0, 0}, 0, WHITE);

    // this is the Healthbar
    DrawRectangle(position.x + position.width / 2 - 50, position.y - 30, health, 20, GREEN);
};
void Mob::render()
{
    if (readyForNextFrame(0.1f))
        animate();
    move();
};

Rectangle Mob::getRec()
{
    return position;
}

void Mob::move()
{
    if (state != MobState::Walking)
        return;

    this->position.x += this->speed.x;
    this->position.y += this->speed.y;

    if (position.x > GetScreenWidth() - position.width)
    {
        this->isDead = true;
        this->position.x = GetScreenWidth() - this->position.width;
    };
    if (position.x < 0)
    {
        this->isDead = true;
        this->position.x = 0;
    };
    if (position.y > GetScreenHeight() - position.height)
    {
        this->isDead = true;
        this->position.y = GetScreenHeight() - position.height;
    };
    if (position.y < 0)
    {
        this->isDead = true;
        this->position.y = 0;
    };
};

void Mob::move(float dx, float dy)
{
    this->speed.x = dx;
    this->speed.y = dy;
    this->setState(MobState::Walking);
    this->move();
};
void Mob::animate()
{
    this->frame++;
    this->frame = (int)this->frame % (int)this->texture.animwidth;
};

void Mob::print(const char *msg)
{
    printf("------------ %s ------------\n", msg);
    printf("x: %.0f\n", this->position.x);
    printf("y: %.0f\n", this->position.y);
    printf("width: %.0f\n", this->position.width);
    printf("height: %.0f\n", this->position.height);
    printf("sprite id: %d\n", this->texture.sprite.id);
    printf("------------ /%s ------------\n\n", msg);
};