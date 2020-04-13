#include <algorithm>
#include <deque>
#include <utility>
#include <vector>

struct Node {
    Node(int y, int x, int dist) : y(y), x(x), dist(dist) {}
    int y, x, dist;
};

class CutOffTreeSolution {
public:
    int cutOffTree(std::vector<std::vector<int>>& grid) {
        std::deque<std::pair<int, int>> toCut;
        for (unsigned int i = 0; i < grid.size(); ++i) {
            for (unsigned int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 1)
                {
                    toCut.push_back({i, j});
                }
            }
        }
        if (toCut.empty()) {
            return 0;
        }
        std::sort(toCut.begin(), toCut.end(), [&grid](auto& lhs, auto& rhs) {
            return grid[lhs.first][lhs.second] < grid[rhs.first][rhs.second];
        });
        int counter = 0;
        std::pair<int, int> currLocation = {0, 0};
        while (!toCut.empty()) {
            auto currSteps = calcDistance(grid, currLocation, toCut.front());
            if (currSteps == -1) {
                return -1;
            }
            counter += currSteps;
            currLocation = toCut.front();
            toCut.pop_front();
        }
        return counter;
    }
private:
    const std::vector<std::pair<int, int>> MOVES = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int calcDistance(const std::vector<std::vector<int>>& grid, const std::pair<int, int>& location,
        const std::pair<int, int>& destination)
    {
        std::deque<Node> possibleMoves;
        possibleMoves.push_back(Node(location.first, location.second, 0));
        std::vector<std::vector<int>> alreadySeen(grid.size(), std::vector<int>(grid[0].size(), 0));
        alreadySeen[location.first][location.second] = 1;;
        while(!possibleMoves.empty()) {
            const auto& node = possibleMoves.front();
            if (node.y == destination.first && node.x == destination.second) {
                return node.dist;
            } else {
                for (const auto& move : MOVES) {
                    int y = node.y + move.first;
                    int x = node.x + move.second;
                    if (0 <= y  && 0 <= x && y < grid.size() && x < grid[0].size() && grid[y][x]
                        && alreadySeen[y][x] == 0)
                    {
                        possibleMoves.push_back(Node(y, x, node.dist + 1));
                        alreadySeen[y][x] = 1;
                    }
                }
            }
            possibleMoves.pop_front();
        }
        return -1;
    }
};

