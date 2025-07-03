#include <stdio.h>
#include <algorithm>
#include "Handler.h"
#include "background.h"
#include "Mob.h"
#include "Tower.h"

Handler::~Handler()
{
    for (BaseEntity<MobState> *d : entities)
    {
        delete d;
    }
    delete player;
    delete background;
    delete ui;
}

void Handler::addPlayer(Player *p)
{
    player = p;
}

void Handler::draw()
{
    background->draw();
    for (BaseEntity<MobState> *e : entities)
    {
        e->draw();
    }
    player->draw();
    ui->draw();
    char buf[30];
    snprintf(buf, sizeof(buf), "%lld", entities.size());
    DrawText(buf, 30, 60, 24, RED);
};

void Handler::render()
{
    for (BaseEntity<MobState> *p : Handler::entities)
    {
        p->render();
    }
    player->render();
    for (BaseEntity<MobState> *f : entities)
    {
        if (!dynamic_cast<Mob *>(f))
        {
            continue;
        }
        for (BaseEntity<MobState> *e : entities)
        {
            if (!dynamic_cast<Mob *>(e))
            {
                continue;
            }
            if (e == f)
            {
                continue;
            }

            Mob *m = dynamic_cast<Mob *>(e);
            Mob *m2 = dynamic_cast<Mob *>(f);
            if (m->side == m2->side)
            {
                continue;
            }
            if (CheckCollisionRecs(e->getPos(), f->getPos()))
            {

                // e->stopMoving();
                // f->stopMoving();
                e->setState(MobState::Fighting);
                f->setState(MobState::Fighting);

                if (e->Dmg(f->attackPoints))
                {
                    f->setState(MobState::Walking);
                };
                if (f->Dmg(e->attackPoints))
                {
                    e->setState(MobState::Walking);
                };
            };
        }
    }

    for (BaseEntity<MobState> *e : entities)
    {
        e->render();
    }
    ui->render();
    if (IsKeyPressed(KEY_SPACE))
    {
        addMob();
    }
    entities.erase(std::remove_if(entities.begin(), entities.end(), [](BaseEntity<MobState> *e)
                                  {
    if (e->isDead) {
        delete e;
        return true;
    }
    return false; }),
                   entities.end());
};

void Handler::addEntity(BaseEntity<MobState> *entity)
{
    entities.push_back(entity);
}

void Handler::setBackground(Background *bg)
{
    background = bg;
};

void Handler::addUI(UI *ui)
{
    this->ui = ui;
}
void Handler::addMob()
{
    Mob *mob = new Mob(Playernum::PLAYER1);
    Mob *mob2 = new Mob(Playernum::PLAYER2);
    this->addEntity(mob);
    this->addEntity(mob2);
};
