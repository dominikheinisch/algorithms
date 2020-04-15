#include <unordered_map>
#include <vector>
#include <queue>

//static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();

class MostFrequentSubtreeSumSolutionBetter {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) return {};
        std::unordered_map<int, int> sizeToOccurencies;
        int maxOccur = -1;
        sumSubTree(root, sizeToOccurencies, &maxOccur);
        std::vector<int> results;
        for (auto& elem : sizeToOccurencies) {
            if (elem.second == maxOccur) {
                results.push_back(elem.first);
            }
        }
        return results;
    }

    int sumSubTree(TreeNode* node, std::unordered_map<int, int>& sizeToOccurencies, int* maxOccur) {
        if (!node) return 0;
        int res = sumSubTree(node->left, sizeToOccurencies, maxOccur)
            + sumSubTree(node->right, sizeToOccurencies, maxOccur) + node->val;
        insert(sizeToOccurencies, res, maxOccur);
        return res;
    }

    void insert(std::unordered_map<int, int>& sizeToOccurencies, int sum, int* maxOccur) {
        auto it = sizeToOccurencies.find(sum);
        if (it == sizeToOccurencies.end()) {
            sizeToOccurencies.insert({sum, 1});
            *maxOccur = std::max(*maxOccur, 1);
        } else {
            it->second += 1;
            *maxOccur = std::max(*maxOccur, it->second);
        }
    }
};

class MostFrequentSubtreeSumSolutionPoor {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    std::vector<int> findFrequentTreeSum(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::unordered_map<int, int> sizeToOccurencies;
        std::queue<TreeNode*> que;
        que.push(root);
        int maxOccur = 1;
        while (!que.empty()) {
            if (que.front()->left) {
                que.push(que.front()->left);
            }
            if (que.front()->right) {
                que.push(que.front()->right);
            }
            int subSum = sumSubTree(que.front());
            auto it = sizeToOccurencies.find(subSum);
            if (it == sizeToOccurencies.end()) {
                sizeToOccurencies.insert({subSum, 1});
            } else {
                it->second += 1;
                maxOccur = std::max(maxOccur, it->second);
            }
            que.pop();
        }
        std::vector<int> results;
        for (auto& elem : sizeToOccurencies) {
            if (elem.second == maxOccur) {
                results.push_back(elem.first);
            }
        }
        return results;
    }

    int sumSubTree(TreeNode* node) {
        if (!node) return 0;
        return node->val + sumSubTree(node->left) + sumSubTree(node->right);
    }
};