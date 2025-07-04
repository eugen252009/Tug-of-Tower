#include "Drawable.h"
#include "raylib.h"
#include "vector"

template <typename T>
bool BaseEntity<T>::readyForNextFrame(float interval)
{
    float currentTime = GetTime();

    float &lastTime = timers[interval];
    if ((currentTime - lastTime) >= interval)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
}

template <typename T>
void BaseEntity<T>::move()
{
    this->position.x += this->speed.x;
    this->position.y += this->speed.y;

    this->speed.x *= 0.9f;
    this->speed.y *= 0.9f;
    if (this->position.x > GetScreenWidth() - this->position.width)
    {
        this->position.x = GetScreenWidth() - this->position.width;
    };
    if (this->position.x < 0)
    {
        this->position.x = 0;
    };
    if (this->position.y > GetScreenHeight() - this->position.height)
    {
        this->position.y = GetScreenHeight() - this->position.height;
    };
    if (this->position.y < 0)
    {
        this->position.y = 0;
    };
    if (this->speed.x < 0.1f && this->speed.x > -0.1f)
        this->speed.x = 0;
    if (this->speed.y < 0.1 && this->speed.y > -0.1f)
        this->speed.y = 0;
}
template <typename T>
Rectangle BaseEntity<T>::getPos()
{
    return this->position;
};

template <typename T>
bool BaseEntity<T>::Dmg(float dmg)
{
    if (this->readyForNextFrame(0.6f))
    {
        this->health -= dmg;
        if (this->health < 1)
        {
            this->isDead = true;
        }
    }
    return this->isDead;
};

template <typename T>
void BaseEntity<T>::draw()
{
    DrawText("Entity has no Draw Implementation!", GetScreenWidth() / 2, GetScreenHeight() / 2, 24, RED);
};

template <typename T>
void BaseEntity<T>::render()
{
    if (this->readyForNextFrame(0.1))
    {
        this->animate();
    }
};

template <typename T>
void BaseEntity<T>::setState(T state)
{
    this->state = state;
    this->texture = *SpriteManager<T>::getSprite(this->entityType, this->state);
};

template <typename T>
void BaseEntity<T>::animate() {};

template void BaseEntity<PlayerState>::move();
template void BaseEntity<MapState>::move();
template void BaseEntity<MobState>::move();
template void BaseEntity<TowerState>::move();
template void BaseEntity<UIState>::move();

template void BaseEntity<PlayerState>::draw();
template void BaseEntity<MapState>::draw();
template void BaseEntity<MobState>::draw();
template void BaseEntity<TowerState>::draw();
template void BaseEntity<UIState>::draw();

template void BaseEntity<PlayerState>::render();
template void BaseEntity<MapState>::render();
template void BaseEntity<MobState>::render();
template void BaseEntity<TowerState>::render();
template void BaseEntity<UIState>::render();

template Rectangle BaseEntity<PlayerState>::getPos();
template Rectangle BaseEntity<MapState>::getPos();
template Rectangle BaseEntity<MobState>::getPos();
template Rectangle BaseEntity<TowerState>::getPos();
template Rectangle BaseEntity<UIState>::getPos();

template bool BaseEntity<PlayerState>::Dmg(float);
template bool BaseEntity<MapState>::Dmg(float);
template bool BaseEntity<MobState>::Dmg(float);
template bool BaseEntity<TowerState>::Dmg(float);
template bool BaseEntity<UIState>::Dmg(float);

template void BaseEntity<PlayerState>::setState(PlayerState);
template void BaseEntity<MapState>::setState(MapState);
template void BaseEntity<MobState>::setState(MobState);
template void BaseEntity<TowerState>::setState(TowerState);
template void BaseEntity<UIState>::setState(UIState);