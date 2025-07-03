#pragma once

enum class PlayerState
{
    Idle,
    Walking,
};
enum class MobState
{
    Idle,
    Walking,
    Fighting,
};
enum class UIState
{
    Slot,
};

enum class TowerState
{
    Idle,
};
enum class MapState
{
    Idle,
};

enum class Entities
{
    Player,
    Mob,
    Ui,
    Background,
};

enum class SpriteEntity
{
    Team1_Player,
    Team1_Warrior,
    Team2_Player,
    Team2_Warrior,
    Tower,
    Tower2,

    UI,
    Map,
};

enum class Playernum
{
    PLAYER1,
    PLAYER2,
};