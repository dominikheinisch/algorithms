#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;
        for (int i=0; i<(int)nums.size(); i++) {
            auto it = numToIndex.find(nums[i]);
            if (it != numToIndex.end()) {
                if (nums[i] + nums[i] == target) {
                    return {it->second, i};
                }
            } else {
                numToIndex.insert({nums[i], i});
            }
        }
        for (int i=0; i<(int)nums.size(); i++) {
            auto it = numToIndex.find(target - nums[i]);
            if (it != numToIndex.end() && i != it->second) {
                return {i, it->second};
            }
        }
        return {-1, -1};
    }
};