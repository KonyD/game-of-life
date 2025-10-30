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
