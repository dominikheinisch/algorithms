#include <experimental/random>
#include <unordered_map>
#include <vector>

class RandomizedCollection {
public:
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = false;
        if (valuesToIndex.find(val) == valuesToIndex.end()) {
            result = true;
        }
        valuesToIndex.insert({val, values.size()});
        values.push_back(val);
        return result;
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
            auto iters = valuesToIndex.equal_range(values[index]);
            it = iters.first;
            bool changed = false;
            while(!changed) {
                if (it->second == (int)values.size() - 1) {
                    it->second = index;
                    changed = true;
                }
                ++it;
            }
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
    std::unordered_multimap<int, int> valuesToIndex;
    std::vector<int> values;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */