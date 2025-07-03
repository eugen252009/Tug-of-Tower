#pragma once
#include "Player.h"
#include "Entity.h"
#include "Drawable.h"
#include "vector"
#include "background.h"
#include "ui.h"

struct Handler
{
private:
    Player *player;
    Player *player2;
    Background *background;
    UI *ui;
    std::vector<BaseEntity<MobState> *> entities;

public:
    // Drawable *background;
    // Handler(Player *player) : player(player) {};

    void draw();
    void render();

    void addPlayer(Player *);
    void addEntity(BaseEntity<MobState> *);
    void setBackground(Background *);
    void addUI(UI *);
    void addMob();

    ~Handler();
};