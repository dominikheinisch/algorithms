#include <experimental/random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto result = valuesToIndex.insert({val, values.size()});
        if (result.second) {
            values.push_back(val);
        }
        return result.second;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = valuesToIndex.find(val);
        if (it == valuesToIndex.end()) {
            return false;
        }
        std::size_t index = it->second;
        valuesToIndex.erase(it);
        if (index != values.size() - 1) {
            values[index] = values.back();
            it = valuesToIndex.find(values[index]);
            it->second = index;
        }
        values.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (values.empty()) {
            return -1;
        }
        int temp = std::experimental::randint(0, (int)values.size() - 1);
        return values[temp];
    }

private:
    std::unordered_map<int, int> valuesToIndex;
    std::vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */