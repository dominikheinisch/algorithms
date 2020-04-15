#include <queue>

//static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();

class WidthOfBinaryTreeSolution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        std::queue<std::pair<TreeNode*, unsigned long int>> qu1;
        std::queue<std::pair<TreeNode*, unsigned long int>> qu2;
        auto currQ = &qu1;
        currQ->push({root, 0});
        auto nextQ = &qu2;
        unsigned long int maxWidth = 1;
        while(!currQ->empty() || !nextQ->empty()) {
            if (currQ->empty()) {
                auto currWidth = nextQ->back().second - nextQ->front().second + 1;
                maxWidth = std::max(maxWidth, currWidth);
                std::swap(currQ, nextQ);
            }
            auto [currNode, currIndex] = currQ->front();
            currQ->pop();
            if (currNode->left) nextQ->push({currNode->left, currIndex * 2});
            if (currNode->right) nextQ->push({currNode->right, currIndex * 2 + 1});
        }
        return maxWidth;
    }
};

