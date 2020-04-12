#include <cmath>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int result = -1;
        for (unsigned int i=0; i<nums.size(); ++i) {
            nums[i] = -nums[i];
        }

        for (const auto elem : nums) {
            std::cout << "[\n";
            for (const auto debug : nums) {
                std::cout << debug << ", ";
            }
            std::cout << "]\n";
            int index = std::abs(elem) - 1;
            if (nums[index] > 0) {
                result = index + 1;
            } else {
                nums[index] = -nums[index];
            }
        }
        for (unsigned int i=0; i<nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
            }
        }
        return result;
    }
};