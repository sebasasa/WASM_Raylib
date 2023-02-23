#include "raylib.h"

int main()
{
    // Initialize window and rectangle position
    InitWindow(800, 450, "Raylib Basic Project");
    Vector2 rectPosition = { 0 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update rectangle position to cursor position
        rectPosition = GetMousePosition();

        // Draw rectangle at cursor position
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(rectPosition.x, rectPosition.y, 50, 50, BLUE);

        EndDrawing();
    }

    // Close window and exit
    CloseWindow();
    return 0;
}
