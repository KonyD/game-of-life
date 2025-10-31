#include "raylib.h"
#include <iostream>
#include "simulation.hpp"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define CELL_SIZE 25

int main(void)
{
    Color GREY = {29, 29, 29, 255};
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    while (!WindowShouldClose())
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / CELL_SIZE;
            int column = mousePosition.x / CELL_SIZE;
            simulation.ToggleCell(row, column);
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            if (simulation.IsRunning())
            {
                simulation.Stop();
                SetWindowTitle("Game of Life is stopped.");
            }
            else
            {
                simulation.Start();
                SetWindowTitle("Game of Life is running...");
            }
        }
        else if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (IsKeyPressed(KEY_K)) {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
