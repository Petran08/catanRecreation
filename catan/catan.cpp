#include <iostream>
#include <raylib.h>
#include "hexagon.h"
#include "moreRaylib.h"

int screenWidth = 1920, screenHeight = 1080;

Vector2 pos;

int main()
{
    bool mat[54][54];

    InitWindow(screenWidth, screenHeight - 95, "catan");

    SetTargetFPS(120);

    while(!WindowShouldClose())
    {
        pos.x += (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT));
        pos.y += (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP));

        BeginDrawing();

        ClearBackground(WHITE);

        drawHexagon(pos, HEX_SIZE, GREEN);

        EndDrawing();
    }

    std::cout << sizeof(mat);
}

