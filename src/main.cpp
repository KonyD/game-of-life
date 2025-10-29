#include "raylib.h"
#include "grid.hpp"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define FPS 12
#define CELL_SIZE 25

int main(void) {
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Grid grid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    grid.SetValue(0, 5, 1);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
