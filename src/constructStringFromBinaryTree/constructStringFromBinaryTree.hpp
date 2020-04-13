#include <iostream>
#include <string>
#include <sstream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionTree2str {
public:
    std::string basicRecursiveTree2str(TreeNode* t) {
        if (!t) {
            return "";
        } else if (t->right){
            return std::to_string(t->val)
                + "(" + basicRecursiveTree2str(t->left) + ")"
                + "(" + basicRecursiveTree2str(t->right) + ")";
        } else if (t->left) {
            return std::to_string(t->val) + "(" + basicRecursiveTree2str(t->left) + ")";
        } else {
             return std::to_string(t->val);
        }
    }

    std::string stringStreamTree2str(TreeNode* t) {
        std::stringstream acc("");
        innerTree2str(t, acc);
        return acc.str();
    }

private:
    void innerTree2str(TreeNode* t, std::stringstream& acc) {
        if (!t) {
            return;
        }
        acc << (t->val);
        if (t->right){
            acc << "(";
            innerTree2str(t->left, acc) ;
            acc << ")(";
            innerTree2str(t->right, acc);
            acc << ")";
        } else if (t->left) {
            acc << "(";
            innerTree2str(t->left, acc);
            acc << ")";
        }
    }
};