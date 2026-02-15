#include "moreRaylib.h"
#include <iostream>

void drawHexagon(Vector2 p, float l, Color c)
{
    float halfl = l / 2;
    float sqrt3 = 1.73205080757f;

    // Center rectangle
    DrawRectangle(p.x - (halfl * sqrt3), p.y - halfl, l * sqrt3, l, c);

    // Top triangle
    Vector2 t1 = { p.x - (halfl * sqrt3), p.y - halfl };
    Vector2 t2 = { p.x, p.y - l };
    Vector2 t3 = { p.x + (halfl * sqrt3), p.y - halfl };
    DrawTriangle(t1, t3, t2, c);

    // Bottom triangle
    Vector2 b1 = { p.x - (halfl * sqrt3), p.y + halfl };
    Vector2 b2 = { p.x, p.y + l };
    Vector2 b3 = { p.x + (halfl * sqrt3), p.y + halfl };
    DrawTriangle(b1, b2, b3, c);
}

