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

template <typename Tag>
struct StateTraits;

template <>
struct StateTraits<PlayerState>
{
    using Type = PlayerState;
    using Specific = PlayerState;
};

template <>
struct StateTraits<UIState>
{
    using Type = UIState;
    using Base = UIState;
};

template <>
struct StateTraits<MobState>
{
    using Type = MobState;
    using Specific = MobState;
};

enum class Entities
{
    Player,
    Mob,
    Ui,
    Background,
};

// enum class State
// {
// Idle,
// Walking,
// Attacking,
// Defending,

// SLOT,
// };

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

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};