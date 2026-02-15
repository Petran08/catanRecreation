#include <iostream>
#include <raylib.h>
#include "hexagon.h"
#include "moreRaylib.h"

int screenWidth = 1920, screenHeight = 1080;

int main()
{
    bool mat[54][54];

    InitWindow(screenWidth, screenHeight - 95, "catan");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        drawHexagon(Vector2{ 500, 400 }, HEX_SIZE, GREEN);

        EndDrawing();
    }

    std::cout << sizeof(mat);
}

