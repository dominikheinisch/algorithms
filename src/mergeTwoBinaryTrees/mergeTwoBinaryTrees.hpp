/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* recursiveMergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t2 == NULL) {
            return t1;
        } else if (t1 == NULL) {
            return t2;
        } else {
            t1->val += t2->val;
            t1->left = recursiveMergeTrees(t1->left, t2->left);
            t1->right = recursiveMergeTrees(t1->right, t2->right);
        }
        return t1;
    }
};