#include "spritemanager.h"
#include "Drawable.h"
#include <stdio.h>

void LoadUI(std::unordered_map<SpriteEntity, std::unordered_map<UIState, Sprites *>> *self)
{
    (*self)[SpriteEntity::UI][UIState::Slot] = new Sprites{
        .sprite = LoadTexture("assets\\images\\ui\\Basic Pixel Health bar and Scroll bar.png"),
        .rect = Rectangle{320, 128, 32, 32},
        .animwidth = 0,
    };
}

void LoadTower(std::unordered_map<SpriteEntity, std::unordered_map<TowerState, Sprites *>> *self)
{
    (*self)[SpriteEntity::Tower][TowerState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Buildings\\Blue Buildings\\Castle.png"),
        .rect = Rectangle{0, 0, 320, 256},
        .animwidth = 0,
    };
    (*self)[SpriteEntity::Tower2][TowerState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Buildings\\Red Buildings\\Castle.png"),
        .rect = Rectangle{0, 0, 320, 256},
        .animwidth = 0,
    };
}

void LoadMap(std::unordered_map<SpriteEntity, std::unordered_map<MapState, Sprites *>> *self)
{
    (*self)[SpriteEntity::Map][MapState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Terrain\\Tilemap_color1.png"),
        .rect = Rectangle{64, 64, 192, 210},
        .animwidth = 0,
    };
}

void LoadPlayer(std::unordered_map<SpriteEntity, std::unordered_map<PlayerState, Sprites *>> *self)
{
    (*self)[SpriteEntity::Team1_Player][PlayerState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Blue Units\\Archer\\Archer_Idle.png"),
        .rect = Rectangle{58, 48, 192, 192},
        .animwidth = 5,
    };

    (*self)[SpriteEntity::Team1_Player][PlayerState::Walking] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Blue Units\\Archer\\Archer_Run.png"),
        .rect = Rectangle{0, 0, 192, 192},
        .animwidth = 5,
    };

    (*self)[SpriteEntity::Team2_Player][PlayerState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Red Units\\Archer\\Archer_Idle.png"),
        .rect = Rectangle{58, 48, 192, 192},
        .animwidth = 5,
    };

    (*self)[SpriteEntity::Team2_Player][PlayerState::Walking] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Red Units\\Archer\\Archer_Run.png"),
        .rect = Rectangle{0, 0, 192, 192},
        .animwidth = 5,
    };
};
void LoadMob(std::unordered_map<SpriteEntity, std::unordered_map<MobState, Sprites *>> *self)
{
    (*self)[SpriteEntity::Team1_Warrior][MobState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Blue Units\\Warrior\\Warrior_Idle.png"),
        .rect = Rectangle{58, 48, 192, 192},
        .animwidth = 5,
    };
    (*self)[SpriteEntity::Team1_Warrior][MobState::Walking] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Blue Units\\Warrior\\Warrior_Run.png"),
        .rect = Rectangle{58, 48, 192, 192},
        .animwidth = 5,
    };
    (*self)[SpriteEntity::Team1_Warrior][MobState::Fighting] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Blue Units\\Warrior\\Warrior_Attack1.png"),
        .rect = Rectangle{58, 48, 192, 192},
        .animwidth = 5,
    };
    (*self)[SpriteEntity::Team2_Warrior][MobState::Idle] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Red Units\\Warrior\\Warrior_Idle.png"),
        .rect = Rectangle{0, 0, 192, 192},
        .animwidth = 5,
    };
    (*self)[SpriteEntity::Team2_Warrior][MobState::Walking] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Red Units\\Warrior\\Warrior_Run.png"),
        .rect = Rectangle{0, 0, 192, 192},
        .animwidth = 5,
    };
    (*self)[SpriteEntity::Team2_Warrior][MobState::Fighting] = new Sprites{
        .sprite = LoadTexture("assets\\images\\Tiny Swords (Free Pack)\\Units\\Red Units\\Warrior\\Warrior_Attack1.png"),
        .rect = Rectangle{0, 0, 192, 192},
        .animwidth = 5,
    };
}

template <typename T>
void SpriteManager<T>::init()
{
    if constexpr (std::is_same_v<T, MobState>)
    {
        LoadMob(&spriteMap);
    }
    else if constexpr (std::is_same_v<T, PlayerState>)
    {
        LoadPlayer(&spriteMap);
    }
    else if constexpr (std::is_same_v<T, UIState>)
    {
        LoadUI(&spriteMap);
    }
    else if constexpr (std::is_same_v<T, TowerState>)
    {
        LoadTower(&spriteMap);
    }
    else if constexpr (std::is_same_v<T, MapState>)
    {
        LoadMap(&spriteMap);
    }
    else
    {
        printf("Fehler!\n");
    }
};

template <typename T>
Sprites *SpriteManager<T>::getSprite(SpriteEntity entitiy, T state)
{
    return spriteMap[entitiy][state];
};

template class SpriteManager<PlayerState>;
template class SpriteManager<MobState>;
template class SpriteManager<UIState>;
template class SpriteManager<MapState>;
template class SpriteManager<TowerState>;