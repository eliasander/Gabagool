
#include <stdio.h>
#include "raylib\src\raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    int screenWidth = 1024;
    int screenHeight = 600;

    Color primaryColor = (Color){ 255, 161, 0, 255 };
    Color secondaryColor = (Color){200,200,200,255};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLANK);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        Rectangle start = {
            (float)screenWidth / 2.0f - 200.0f / 2.0f,
            (float)screenHeight - 225.0f,
            200,
            100
        };
        DrawRectangleRounded(start, 0.2f, 2, secondaryColor);
        DrawRectangleRoundedLinesEx(start, 0.2f, 2, 6.0f, primaryColor);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
