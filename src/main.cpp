#include "state.h"
#include <raylib.h>

/*
 * 1 - Custom Colors / Cats
 * 2 - Play Functionality 
 * 3 - Sleeping and Waking Functionality (when touched)
 * */


int main() {

    // Initialization 
    const int catOffset = 20;
    // Window FLAGS
    SetConfigFlags(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_MOUSE_PASSTHROUGH |
                 FLAG_WINDOW_TOPMOST | FLAG_WINDOW_UNFOCUSED | FLAG_WINDOW_TRANSPARENT );

    InitWindow(100, 100, "");
    SetTargetFPS(60);

    GameState game {};
    Cat myCat {};

    game.initAnims();

    while (!WindowShouldClose()) {

        // Update
        MousePos mouse = getGlobalMousePos(); // X11 functions
        myCat.updateMouseTracking(mouse);


        if (myCat.isMouseIdle())
        {

            auto newPos = myCat.getNewPos(mouse);
            // Moves to target position
            SetWindowPosition(
                newPos.first + catOffset,
                newPos.second + catOffset
            );
        }

        game.updateAnims();

        // Alt + Q = Stop
        if (IsKeyDown(KEY_LEFT_ALT) && IsKeyPressed(KEY_Q))  break;

        // Drawing
        BeginDrawing();
        ClearBackground(BLANK);


        if (myCat.isMouseIdle() && !myCat.hasCatReachedMouse(mouse))
        {

            Direction direction = myCat.checkCatQuadrant(myCat.getCurrCatPosX(), myCat.getCurrCatPosY());
            myCat.drawTexture(game.walkAnims[direction].getCurrentFrame());

        }

        else if (myCat.isMouseIdle() && myCat.hasCatReachedMouse(mouse))
        {
            Texture2D currentFrame = game.scratchAnim.getCurrentFrame();
            myCat.drawTexture(currentFrame);
        }

        else 
        {
            Texture2D currentFrame = game.washAnim.getCurrentFrame();
            myCat.drawTexture(currentFrame);
        }

        EndDrawing();
    }

    game.cleanAnims();

    CloseWindow();
    return 0;
}
