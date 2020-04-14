#include <string>
#include <sstream>
#include <vector>

class OptimalDivisionSolution {
public:
    std::string optimalDivision(std::vector<int>& nums) {
        std::stringstream sstream;
        if (nums.size() == 1) {
            sstream << nums[0];
        } else if (nums.size() == 2) {
            sstream << nums[0] << "/" << nums[1];
        } else {
            sstream << nums[0] << "/(";
            for (int i=1; i<nums.size() - 1; ++i) {
                sstream << nums[i] << "/";
            }
            sstream << nums[nums.size() - 1] << ")";
        }
        return sstream.str();
    }
};