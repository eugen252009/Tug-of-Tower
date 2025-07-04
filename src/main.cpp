#include <stdio.h>
#include "raylib.h"
#include "Player.h"
#include <string>
#include "background.h"
#include "Handler.h"
#include "Tower.h"
#include <stdio.h>

#define WIDTH 1600
#define HEIGHT 900

void sendMessage(const char *msg)
{
    
    DrawText(msg, 30, 30, 24, RED);
}

int main()
{
    InitWindow(WIDTH, HEIGHT, NULL);
    SetTargetFPS(144);
    ToggleBorderlessWindowed();

    SpriteManager<MapState>::init();
    SpriteManager<PlayerState>::init();
    SpriteManager<TowerState>::init();
    SpriteManager<UIState>::init();
    SpriteManager<MobState>::init();

    Background *bg = new Background();

    Player *player1 = new Player{{30, (float)GetScreenHeight() / 2 + 100, 100, 120}, {0, 0}, Playernum::PLAYER1};
    // Player *player2 = new Player{{(float)GetScreenWidth() - 200, (float)GetScreenHeight() / 2 + 100, 70, 90}, {0, 0}, Playernum::PLAYER2};
    Tower *tower1 = new Tower(Playernum::PLAYER1, 74, GetScreenHeight() / 2);
    Tower *tower2 = new Tower(Playernum::PLAYER2, GetScreenWidth() - 256, GetScreenHeight() / 2);
    UI *ui = new UI();

    Handler handler = {};
    handler.setBackground(bg);
    handler.addUI(ui);
    handler.addPlayer(player1);
    handler.addEntity(tower1);
    handler.addEntity(tower2);
    // handler.addEntity(player2);

    while (!WindowShouldClose())
    {
        handler.render();

        BeginDrawing();
        ClearBackground(SKYBLUE);

        sendMessage(std::to_string(GetFPS()).c_str());
        handler.draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}