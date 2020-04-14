// static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    bool isSubtree(TreeNode* s, TreeNode* pattern) {
        PATTERN = pattern;
        return isSubtreeInner(s);
    }

private:
    bool isSubtreeInner(const TreeNode* s) {
        return  equal(s, PATTERN) || (s && (isSubtreeInner(s->left) || isSubtreeInner(s->right)));
    }

    bool equal(const TreeNode* s, const TreeNode* pattern) {
        if (!s && !pattern) {
            return true;
        }
        if (!s || !pattern) {
            return false;
        }
        if (s->val != pattern->val) {
            return false;
        }
        return equal(s->left, pattern->left) && equal(s->right, pattern->right);
    }
    const TreeNode* PATTERN;
};