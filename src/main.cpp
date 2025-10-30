#include "raylib.h"
#include <iostream>
#include "simulation.hpp"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define FPS 12
#define CELL_SIZE 25

int main(void)
{
    Color GREY = {29, 29, 29, 255};

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    simulation.SetCellValue(3, 4, 1);
    simulation.SetCellValue(3, 5, 1);
    simulation.SetCellValue(4, 5, 1);
    simulation.SetCellValue(2, 5, 1);

    std::cout << simulation.CountLiveNeighbors(3, 4) << std::endl;

    while (!WindowShouldClose())
    {
        simulation.Update();

        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
