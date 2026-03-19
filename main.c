
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

    float currentGlowX = (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f;
    float currentGlowY = (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f;

    int currentSelect = 1;

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




        Rectangle play_basic = {
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };
        Vector2 text_size_basic = MeasureTextEx(font,"BASIC", 20, 1);

        Rectangle play_custom = {
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f - 300.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };
        Vector2 text_size_custom = MeasureTextEx(font,"CUSTOM", 20, 1);

        Rectangle leader_board = {
            (float)screenWidth / 2.0f - BOX_WIDTH / 2.0f + 300.0f,
            (float)screenHeight / 2.0f - BOX_HEIGHT / 2.0f,
            BOX_WIDTH,
            BOX_HEIGHT
        };
        Vector2 text_size_leaderboard = MeasureTextEx(font,"LEADERBOARD", 20, 1);

        Rectangle glow = {
            currentGlowX-BOX_WIDTH*0.05f,
            currentGlowY-BOX_HEIGHT*0.05f,
            BOX_WIDTH*1.1f,
            BOX_HEIGHT*1.1f
        };

        DrawRectangleRounded(glow, 0.2f, 2, TERTIARY_COLOR);


        DrawRectangleRounded(play_custom, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(play_custom, 0.2f, 2, 6.0f, PRIMARY_COLOR);

        DrawRectangleRounded(play_basic, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(play_basic, 0.2f, 2, 6.0f, PRIMARY_COLOR);

        DrawRectangleRounded(leader_board, 0.2f, 2, SECONDARY_COLOR);
        DrawRectangleRoundedLinesEx(leader_board, 0.2f, 2, 6.0f, PRIMARY_COLOR);

        Vector2 text_pos_custom = (Vector2){
            play_custom.x+play_custom.width/2-text_size_custom.x/2,
            play_custom.y+play_custom.height/2-text_size_custom.y/2};
        DrawTextEx(font,"CUSTOM", text_pos_custom, 20, 1, RED);

        Vector2 text_pos_basic = (Vector2){
            play_basic.x+play_basic.width/2-text_size_basic.x/2,
            play_basic.y+play_basic.height/2-text_size_basic.y/2};
        DrawTextEx(font,"BASIC", text_pos_basic, 20, 1, RED);

        Vector2 text_pos_leaderboard = (Vector2){
            leader_board.x+leader_board.width/2-text_size_leaderboard.x/2,
            leader_board.y+leader_board.height/2-text_size_leaderboard.y/2};
        DrawTextEx(font,"LEADERBOARD", text_pos_leaderboard, 20, 1, RED);

        Rectangle mouseRec = {
            GetMouseX(),
            GetMouseY(),
            1,
            1
        };

        DrawRectangleRec(mouseRec, SECONDARY_COLOR);

        if (CheckCollisionRecs(play_custom, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision custom\n");
            currentSelect = 0;
        } else if (CheckCollisionRecs(play_basic, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision basic\n");
            currentSelect = 1;
        } else if (CheckCollisionRecs(leader_board, mouseRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            printf("Collision leader\n");
            currentSelect = 2;
        }

        if (IsKeyPressed(KEY_LEFT)) {
            if (currentSelect > 0)
                currentSelect--;
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            if (currentSelect < 2)
                currentSelect++;
        }

        if (currentSelect == 0) {
            currentGlowX = play_custom.x;
            currentGlowY = play_custom.y;
        } else if (currentSelect == 1) {
            currentGlowX = play_basic.x;
            currentGlowY = play_basic.y;
        } else if (currentSelect == 2) {
            currentGlowX = leader_board.x;
            currentGlowY = leader_board.y;
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
