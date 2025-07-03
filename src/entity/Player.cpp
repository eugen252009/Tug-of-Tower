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
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team1_Player, PlayerState::Idle);
        break;
    case Playernum::PLAYER2:
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team2_Player, PlayerState::Idle);
        break;
    }
}

void Player::draw()
{
    if (health >= 1)
        DrawRectangle(position.x + position.width / 2 - 42, position.y - 30, 20, 20, GREEN);
    if (health >= 25)
        DrawRectangle(position.x + position.width / 2 - 21, position.y - 30, 20, 20, GREEN);
    if (health >= 50)
        DrawRectangle(position.x + position.width / 2, position.y - 30, 20, 20, GREEN);
    if (health >= 75)
        DrawRectangle(position.x + position.width / 2 + 21, position.y - 30, 20, 20, GREEN);

    if (side == Playernum::PLAYER1)
    {
        DrawTexturePro(texture.sprite, {192.0f * frame + 58, 192.0f + 48, 70, 90}, position, {0, 0}, 0, WHITE);
    }
    else
    {
        DrawTexturePro(texture.sprite, {192.0f * (frame + 1) + 58, 192.0f + 48, -70, 90}, position, {0, 0}, 0, WHITE);
    }
}

void Player::render()
{
    if (side == Playernum::PLAYER1)
        move();

    if (readyForNextFrame(0.1f))
        animate();
}

void Player::setIdle()
{
    switch (side)
    {
    case Playernum::PLAYER1:
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team1_Player, PlayerState::Idle);
        break;
    case Playernum::PLAYER2:
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team2_Player, PlayerState::Idle);
        break;
    }
};
float Player::getAttackPoints()
{
    return 0;
};

void Player::getDmg(float dmg) {
    // BaseEntity::Dmg(dmg);
};

void Player::setWalking()
{
    switch (side)
    {
    case Playernum::PLAYER1:
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team1_Player, PlayerState::Idle);
        break;
    case Playernum::PLAYER2:
        texture = *SpriteManager<PlayerState>::getSprite(SpriteEntity::Team2_Player, PlayerState::Idle);
        break;
    }
};

void Player::animate()
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
void Player::move()
{
    if (IsKeyDown(KEY_RIGHT))
    {
        speed.x = 1;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        speed.x = -1;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        speed.y = 1;
    }
    if (IsKeyDown(KEY_UP))
    {
        speed.y = -1;
    }

    BaseEntity::move();
};
