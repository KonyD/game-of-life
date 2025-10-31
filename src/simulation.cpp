#include <vector>
#include <utility>
#include "simulation.hpp"

using namespace std;

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    vector<pair<int, int>> neighborOffset = {
        {-1, 0},  // Directly above
        {1, 0},   // Directly below
        {0, -1},  // To the left
        {0, 1},   // To the right
        {-1, -1}, // Diagonal upper left
        {-1, 1},  // Diagonal upper right
        {1, -1},  // Diagonal lower left
        {1, 1}    // Diagonal lower right
    };

    for (const auto &offset : neighborOffset)
    {
        int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

void Simulation::Update()
{
    if (!IsRunning()) return;
    
    for (int row = 0; row < grid.getRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            int liveNeighbors = CountLiveNeighbors(row, column);
            int cellValue = grid.GetValue(row, column);

            if (cellValue == 1) {
                if (liveNeighbors > 3 || liveNeighbors < 2) {
                    tempGrid.SetValue(row, column, 0);
                }
                else {
                    tempGrid.SetValue(row, column, 1);
                }
            }
            else {
                if (liveNeighbors == 3) {
                    tempGrid.SetValue(row, column, 1);
                }
                else {
                    tempGrid.SetValue(row, column, 0);
                }
            }
        }
    }
    grid = tempGrid;
}
