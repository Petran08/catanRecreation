#include <iostream>
#include <raylib.h>
#include <random>
#include "hexagon.h"
#include "moreRaylib.h"

using namespace std;

int screenWidth = 1920, screenHeight = 1080;

Vector2 pos;

static std::random_device rd;
static std::mt19937 gen(rd());

short int mat[54][54];
hexagon casute[20];

short int orderBigLayer[] = {1, 2, 3, 7, 12, 16, 19, 18, 17, 13, 8, 4};
short int orderMediumLayer[] = { 5, 6, 11, 15, 14, 9 };
short int rolls[18] = {8, 4, 11, 12, 9, 10, 8, 3, 6, 2, 5, 10, 3, 6, 5, 4, 9, 11}; // clockwise
short int resource[] = {4, 4, 3, 4, 3};//wood, wool, brick, hay, rock

void mapInit()
{
    std::uniform_int_distribution<int> start(0, 11);
    std::uniform_int_distribution<int> desert(1, 19);
    std::uniform_int_distribution<int> resursa(0, 4);
    int dessert = desert(gen);
    int startHex = start(gen);
    int rollId = 0;
    casute[dessert].resource = "none";
    for (int i = 1; i < 20; i++)
    {
        if (casute[i].resource != "none")
        {
            int res = resursa(gen);
            while (resource[res] == 0)
                res = resursa(gen);
            resource[res]--;
            switch (res)
            {
            case 0:
                casute[i].resource = "wood";
                break;
            case 1:
                casute[i].resource = "wool";
                break;
            case 2:
                casute[i].resource = "brick";
                break;
            case 3:
                casute[i].resource = "hay";
                break;
            case 4:
                casute[i].resource = "rock";
                break;
            default:
                cout << "ERROR\n";
                break;
            }
        }
    }
    if (casute[orderBigLayer[startHex]].resource != "none")
    {
        casute[orderBigLayer[startHex]].diceRoll = rolls[rollId++];
    }
    for (int i = startHex + 1; i != startHex; i++)
    {
        if (i > 11)
            i = 0;
        if (casute[orderBigLayer[i]].resource != "none")
        {
            casute[orderBigLayer[i]].diceRoll = rolls[rollId++];
        }
    }
    startHex /= 2;
    if (casute[orderMediumLayer[startHex]].resource != "none")
    {
        casute[orderMediumLayer[startHex]].diceRoll = rolls[rollId++];
    }
    for (int i = startHex + 1; i != startHex; i++)
    {
        if (i > 5)
            i = 0;
        if (casute[orderMediumLayer[i]].resource != "none")
        {
            casute[orderMediumLayer[i]].diceRoll = rolls[rollId++];
        }
    }
    casute[10].diceRoll = 11;

    for (int i = 1; i < 20; i++)
        cout << casute[i].diceRoll << ' ';
}

int main()
{
    mapInit();

    InitWindow(screenWidth, screenHeight - 95, "catan");

    SetTargetFPS(120);

    while(!WindowShouldClose())
    {
        pos.x += (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT));
        pos.y += (IsKeyDown(KEY_DOWN) - IsKeyDown(KEY_UP));

        BeginDrawing();

        ClearBackground(BLACK);

        drawHexagon(pos, HEX_SIZE, GREEN);

        EndDrawing();
    }

    std::cout << sizeof(mat);
}

