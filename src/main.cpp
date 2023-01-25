#include "raylib.h"
#include <stdio.h>
#include "limb.h"
#include "joint.h"
#include "tests.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Limb l1 = {100 , 100 , 150,25, 0, RED};
    Joint j1(l1,1,{150,25});
    


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        if (IsKeyDown(KEY_RIGHT)) l1.x += 1;
        if (IsKeyDown(KEY_LEFT)) l1.x -= 1;
        if (IsKeyDown(KEY_SPACE)) j1.tension += -.05;
        Distance_joint_point(j1,{500,300});

        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        j1.Draw();
        DrawRectangle(500,300,10,10,GREEN);
        
        DrawFPS(0,0);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    CloseWindow(); 

    return 0;
}