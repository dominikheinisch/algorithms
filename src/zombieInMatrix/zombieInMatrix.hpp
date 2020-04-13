#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    int zombiesAttacking(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q1;
        std::queue<std::pair<int, int>> q2;
        auto currQueue = &q1;
        auto nextQueue = &q2;
        for (unsigned int i = 0; i < grid.size(); ++i) {
            for (unsigned int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1)
                {
                    currQueue->push({i, j});
                }
            }
        }

        const std::vector<std::pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int counter = 0;
        while(!currQueue->empty() || !nextQueue->empty()) {
            if((*currQueue).empty()) {
                ++counter;
                std::swap(currQueue, nextQueue);
            }
            for (auto& move : moves) {
                int y = currQueue->front().first + move.first;
                int x = currQueue->front().second + move.second;
                if (0 <= y && y < (int)grid.size() && 0 <= x && x < (int)grid[0].size() && grid[y][x] == 0) {
                    nextQueue->push({y, x});
                    grid[y][x] = 1;
                }
            }
            currQueue->pop();
        }
        std::cout << "[\n";
        for (const auto row : grid) {
            for (const auto elem : row) {
                std::cout << elem << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "]\n";

        return counter;
    }
};