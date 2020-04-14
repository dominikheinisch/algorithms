#include <queue>
#include <utility>
#include <vector>

//static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();

class NumberOfIslandsSolution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int counter = 0;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++counter;
                    bfs(grid, i, j);
                }
            }
        }
        return counter;
    }

    void bfs (std::vector<std::vector<char>>& grid, int i, int j) {
        std::queue<std::pair<int, int>> movesToDo;
        movesToDo.push({i, j});
        grid[i][j] = '2';
        while (!movesToDo.empty()) {
            auto [y_, x_] = movesToDo.front();
            for (auto& move : MOVES) {
                int y = y_ + move.first;
                int x = x_ + move.second;
                if (0 <= y && 0 <= x && y < grid.size() && x < grid[0].size() && grid[y][x] == '1') {
                    movesToDo.push({y, x});
                    grid[y][x] = '2';
                }
            }
            movesToDo.pop();
        }
    }

    const std::vector<std::pair<int, int>> MOVES =
        {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
};