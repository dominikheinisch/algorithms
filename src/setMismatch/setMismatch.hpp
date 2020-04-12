#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> findErrorNums(const std::vector<int>& nums) {
        std::vector<int> indexes(nums.size());
        std::fill(indexes.begin(), indexes.end(), 0);
        for (const auto elem : nums) {
            indexes[elem - 1]++;
        }
        auto zeroIt = std::find(indexes.begin(), indexes.end(), 0) + 1;
        auto twiceIt = std::find(indexes.begin(), indexes.end(), 2) + 1;
        auto notAppeared = static_cast<int>(zeroIt - indexes.begin());
        auto twiceAppeared = static_cast<int>(twiceIt - indexes.begin());
        return {twiceAppeared, notAppeared};
    }
};