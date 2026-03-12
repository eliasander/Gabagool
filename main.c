
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

    Font font = LoadFontEx("assets/GoogleSans-Regular.ttf", 128, 0, 0);
    printf("File exists: %d\n", FileExists("assets/GoogleSans.ttf"));

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
        Vector2 textSize = MeasureTextEx(font,"Congrats! You created your first window!", 20, 1);

        Rectangle button = {
            (float)screenWidth / 2.0f - 200.0f / 2.0f,
            (float)screenHeight - 225.0f,
            200,
            100
        };
        DrawRectangleRounded(button, 0.2f, 2, secondaryColor);
        DrawRectangleRoundedLinesEx(button, 0.2f, 2, 6.0f, primaryColor);



        Vector2 textPos = (Vector2){
            button.x+button.width/2-textSize.x/2,
            button.y+button.height/2-textSize.y/2};

        DrawTextEx(font,"Congrats! You created your first window!", textPos, 20, 1, RED);





        Rectangle mouseRec = {
            GetMouseX(),
            GetMouseY(),
            1,
            1
        };
        DrawRectangleRec(mouseRec, secondaryColor);

        if (CheckCollisionRecs(button, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision\n");
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
