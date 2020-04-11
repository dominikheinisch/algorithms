#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> topKFrequent(const std::vector<std::string>& words, const uint32_t k) {
        std::unordered_map<std::string, uint32_t> occurencies;
        for (const auto& elem : words) {
            auto it = occurencies.find(elem);
            if (it == occurencies.end()) {
                occurencies.emplace(elem, 1);
            }  else {
                ++(it->second);
            }
        }
        assert(k <= occurencies.size());

        std::vector<std::pair<std::string, uint32_t>> to_sort;
        to_sort.reserve(occurencies.size());
        std::copy(occurencies.begin(), occurencies.end(), std::back_inserter(to_sort));
        std::partial_sort(to_sort.begin(), to_sort.begin() + k, to_sort.end(),
            [](const auto& lhs, const auto& rhs) {
                if (lhs.second == rhs.second) {
                    return lhs.first.compare(rhs.first) < 0;
                } else {
                    return lhs.second > rhs.second;
                }
            }
        );

        std::vector<std::string> result;
        result.reserve(k);
        std::transform(to_sort.begin(), to_sort.begin() + k, std::back_inserter(result),
            [](const auto& elem) {
                return elem.first;
            }
        );

        for (const auto& elem : to_sort) {
            std::cout << elem.first << " " << elem.second << "\n";
        }
         std::cout << "result\n";
        for (const auto& elem : result) {
            std::cout << elem << "\n";
        }
        return result;
    }
};