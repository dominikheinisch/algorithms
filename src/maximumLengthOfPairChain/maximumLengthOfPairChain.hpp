#include <algorithm>
#include <vector>

class SolutionFindLongestChain {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](const auto& pair1, const auto& pair2) {
            return pair1[0] < pair2[0];
        });
        int currEnd = pairs[0][0] - 1;
        int counter = 0;
        for (const auto& pair : pairs) {
            if (pair[0] > currEnd) {
                currEnd = pair[1];
                ++counter;
            } else if (pair[1] < currEnd) {
                currEnd = pair[1];
            }
        }
        return counter;
    }
};