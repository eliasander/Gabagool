
#include <stdio.h>
#include "raylib/src/raylib.h"

#define BOX_HEIGHT 200
#define BOX_WIDTH 200

#define PRIMARY_COLOR (Color){118, 118, 118, 255}
#define SECONDARY_COLOR (Color){195, 195, 195, 255}
#define TERTIARY_COLOR (Color){244, 39, 39, 255}




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


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Font font = LoadFontEx("assets/GoogleSans-Regular.ttf", 128, 0, 0);

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
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f + 300.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };

        Rectangle play_custom = {
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f - 300.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };

        Rectangle leader_board = {
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };

        float currentGlowX = (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f;
        float currentGlowY = (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f;
        Rectangle glow = {
            currentGlowX-BOX_WIDTH*0.05f,
            currentGlowY-BOX_HEIGHT*0.05f,
            BOX_WIDTH*1.1f,
            BOX_HEIGHT*1.1f
        };

        DrawRectangleRounded(play_basic, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(play_basic, 0.2f, 2, 6.0f, PRIMARY_COLOR);

        DrawRectangleRounded(play_custom, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(play_custom, 0.2f, 2, 6.0f, PRIMARY_COLOR);

        DrawRectangleRounded(leader_board, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(leader_board, 0.2f, 2, 6.0f, PRIMARY_COLOR);


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

        DrawRectangleRec(mouseRec, SECONDARY_COLOR);

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
