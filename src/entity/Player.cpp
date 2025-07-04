#include "Player.h"
#include "vector"
#include "spritemanager.h"
#include "State.h"

Player::Player(Rectangle pos, Vector2 speed, Playernum side)
{
    this->health = 100;
    this->position = pos;
    this->speed = speed;
    this->side = side;
    switch (side)
    {
    case Playernum::PLAYER1:
        this->texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team1_Player, PlayerState::Idle);
        break;
    case Playernum::PLAYER2:
        this->texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team2_Player, PlayerState::Idle);
        break;
    }
}

void Player::draw()
{
    if (this->health >= 1)
        DrawRectangle(this->position.x + this->position.width / 2 - 42, this->position.y - 30, 20, 20, GREEN);
    if (this->health >= 25)
        DrawRectangle(this->position.x + this->position.width / 2 - 21, this->position.y - 30, 20, 20, GREEN);
    if (this->health >= 50)
        DrawRectangle(this->position.x + this->position.width / 2, this->position.y - 30, 20, 20, GREEN);
    if (this->health >= 75)
        DrawRectangle(this->position.x + this->position.width / 2 + 21, this->position.y - 30, 20, 20, GREEN);

    if (this->side == Playernum::PLAYER1)
    {
        DrawTexturePro(this->texture.sprite, {192.0f * this->frame + 58, 192.0f + 48, 70, 90}, this->position, {0, 0}, 0, WHITE);
    }
    else
    {
        DrawTexturePro(this->texture.sprite, {192.0f * (this->frame + 1) + 58, 192.0f + 48, -70, 90}, this->position, {0, 0}, 0, WHITE);
    }
}

void Player::render()
{
    if (this->side == Playernum::PLAYER1)
        this->move();

    if (this->readyForNextFrame(0.1f))
        this->animate();
}

float Player::getAttackPoints()
{
    return 0;
};

void Player::getDmg(float dmg) {
};

void Player::animate()
{
    this->frame++;
    this->frame = (int)this->frame % (int)this->texture.animwidth;
};
void Player::move()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        this->speed.x = 1;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        this->speed.x = -1;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        this->speed.y = 1;
    }
    if (IsKeyDown(KEY_UP))
    {
        this->speed.y = -1;
    }

    BaseEntity::move();
};
