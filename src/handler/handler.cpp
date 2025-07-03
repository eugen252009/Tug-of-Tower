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
    delete this->player;
    delete this->background;
    delete this->ui;
}

void Handler::addPlayer(Player *p)
{
    this->player = p;
}

void Handler::draw()
{
    this->background->draw();
    for (BaseEntity<MobState> *e : entities)
    {
        e->draw();
    }
    this->player->draw();
    this->ui->draw();
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
    this->player->render();
    for (BaseEntity<MobState> *f : this->entities)
    {
        if (!dynamic_cast<Mob *>(f))
        {
            continue;
        }
        for (BaseEntity<MobState> *e : this->entities)
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

    for (BaseEntity<MobState> *e : this->entities)
    {
        e->render();
    }
    this->ui->render();
    if (IsKeyPressed(KEY_SPACE))
    {
        addMob();
    }
    this->entities.erase(std::remove_if(entities.begin(), entities.end(), [](BaseEntity<MobState> *e)
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
    this->entities.push_back(entity);
}

void Handler::setBackground(Background *bg)
{
    this->background = bg;
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
