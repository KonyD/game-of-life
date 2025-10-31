#pragma once
#include "grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize), running(false)
    {
        grid.FillRandom();
    }
    void Draw();
    void SetCellValue(int row, int col, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();
    bool IsRunning() {return running;}
    void Start() {running = true;}
    void Stop() {running = false;}
private:
    Grid grid;
    Grid tempGrid;
    bool running;
};