
#include <stdio.h>
#include "raylib/src/raylib.h"

int screenWidth;
int screenHeight;

void drawBackground() {
    Rectangle box = {
        10,
        10,
        screenWidth-20,
        screenHeight-20
    };

    Color backgroundColor = {92,168,255,255};
    DrawRectangleRounded(box, 0.05f, 2, backgroundColor);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    screenWidth = 1024;
    screenHeight = 600;

    Color primaryColor = (Color){ 255, 161, 0, 255 };
    Color secondaryColor = (Color){200,200,200,255};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Font font = LoadFontEx("assets/GoogleSans-Regular.ttf", 128, 0, 0);
    printf("File exists: %d\n", FileExists("../assets/GoogleSans.ttf"));

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
        drawBackground();

        Vector2 textSize = MeasureTextEx(font,"Congrats! You created your first window!", 20, 1);



        Rectangle play_basic = {
            (float)screenWidth / 2.0f - 200.0f / 2.0f + 300.0f,
            (float)screenHeight - 450.0f,
            200,
            100
        };

        Rectangle play_custom = {
            (float)screenWidth / 2.0f - 200.0f / 2.0f - 300.0f,
            (float)screenHeight - 450.0f,
            200,
            100
        };

        Rectangle leader_board = {
            (float)screenWidth / 2.0f - 200.0f / 2.0f,
            (float)screenHeight - 450.0f,
            200,
            100
        };

        DrawRectangleRounded(play_basic, 0.2f, 2, secondaryColor);
        DrawRectangleRoundedLinesEx(play_basic, 0.2f, 2, 6.0f, primaryColor);

        DrawRectangleRounded(play_custom, 0.2f, 2, secondaryColor);
        DrawRectangleRoundedLinesEx(play_custom, 0.2f, 2, 6.0f, primaryColor);

        DrawRectangleRounded(leader_board, 0.2f, 2, secondaryColor);
        DrawRectangleRoundedLinesEx(leader_board, 0.2f, 2, 6.0f, primaryColor);



        Vector2 textPos = (Vector2){
            play_custom.x+play_custom.width/2-textSize.x/2,
            play_custom.y+play_custom.height/2-textSize.y/2};

        DrawTextEx(font,"Congrats! You created your first window!", textPos, 20, 1, RED);

        Rectangle mouseRec = {
            GetMouseX(),
            GetMouseY(),
            1,
            1
        };

        DrawRectangleRec(mouseRec, secondaryColor);

        if (CheckCollisionRecs(play_basic, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision basic\n");
        } else if (CheckCollisionRecs(play_custom, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision custom\n");
        } else if (CheckCollisionRecs(leader_board, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision leader\n");
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
