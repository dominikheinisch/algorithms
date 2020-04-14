//static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();
class ConvertBstToGreaterTreeSolution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        if (!root) return 0;
        inner(root, acc);
        return root;
    }

    void inner(TreeNode* node, int& acc) {
        if (node->right)
            inner(node->right, acc);
        acc += node->val;
        node->val = acc;
        if (node->left)
            inner(node->left, acc);
    }
};