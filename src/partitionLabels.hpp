#include <string>
#include <unordered_map>
#include <vector>

class PartitionLabelsSolution {
public:
    std::vector<int> partitionLabels(std::string S) {
        std::unordered_map<char, int> charToIndex;
        for (int i=S.size()-1; i>=0; --i) {
            charToIndex.insert({S[i], i});
        }
        std::vector<int> res;
        int currEnd = 0;
        int lenCounter = 0;
        for (int i=0; i<S.size(); ++i) {
            ++lenCounter;
            int index = charToIndex.find(S[i])->second;
            if (index > currEnd) {
                currEnd = index;
            } else if (i == currEnd) {
                res.push_back(lenCounter);
                ++currEnd;
                lenCounter = 0;
            }
        }
        return res;
    }
};