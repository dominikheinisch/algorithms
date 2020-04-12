/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();
class Solution {
public:
    TreeNode* recursiveMergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t2) return t1;
        if (!t1) return t2;
        t1->val += t2->val;
        if (t2->left) t1->left = recursiveMergeTrees(t1->left, t2->left);
        if (t2->right) t1->right = recursiveMergeTrees(t1->right, t2->right);
        return t1;
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) {
            return t2;
        } else if (t2 == NULL) {
            return t1;
        }
        std::stack<std::pair<TreeNode*, TreeNode*>> nodes;
        nodes.push({t1, t2});
        while (!nodes.empty()) {
            auto [tree1, tree2] = nodes.top();
            nodes.pop();
            tree1->val += tree2->val;
            if (tree1->left == NULL) {
                tree1->left = tree2->left;
            } else if(tree2->left != NULL) {
                nodes.push({tree1->left, tree2->left});
            }
            if (tree1->right == NULL) {
                tree1->right = tree2->right;
            } else if (tree2->right != NULL) {
                nodes.push({tree1->right, tree2->right});
            }
        }
        return t1;
    }
};