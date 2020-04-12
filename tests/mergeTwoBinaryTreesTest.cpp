#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "mergeTwoBinaryTrees/mergeTwoBinaryTrees.hpp"

struct MergeTwoBinaryTreesTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<Solution>();
        createTrees();
    }

    void createTrees() {
        std::vector<int> nums = {1,3,2,5,2,1,3,4,7};
        for (auto i : nums) {
            treeNodes.push_back(i);
        }
        root1 = &treeNodes[0];
        root1->left = &treeNodes[1];
        root1->right = &treeNodes[2];
        root1->left->left = &treeNodes[3];
        root2 = &treeNodes[4];
        root2->left = &treeNodes[5];
        root2->right = &treeNodes[6];
        root2->left->right = &treeNodes[7];
        root2->right->right = &treeNodes[8];
    }

    void assertEq(TreeNode* newRoot) {
        ASSERT_EQ(newRoot->val, 3);
        ASSERT_EQ(newRoot->left->val, 4);
        ASSERT_EQ(newRoot->left->left->val, 5);
        ASSERT_EQ(newRoot->left->right->val, 4);
        ASSERT_EQ(newRoot->right->val, 5);
        ASSERT_EQ(newRoot->right->right->val, 7);
    }

    std::unique_ptr<Solution> sut;
    TreeNode* root1;
    TreeNode* root2;
    std::vector<TreeNode> treeNodes;
};

TEST_F(MergeTwoBinaryTreesTest, testNullRecursion)
{
    TreeNode* newRoot = sut->recursiveMergeTrees(NULL, NULL);
    ASSERT_TRUE(newRoot == NULL);
}

TEST_F(MergeTwoBinaryTreesTest, testRecursion)
{
    TreeNode* newRoot = sut->recursiveMergeTrees(root1, root2);
    assertEq(newRoot);
}

TEST_F(MergeTwoBinaryTreesTest, testNullStack)
{
    TreeNode* newRoot = sut->mergeTrees(NULL, NULL);
    ASSERT_TRUE(newRoot == NULL);
}

TEST_F(MergeTwoBinaryTreesTest, testStack)
{
    TreeNode* newRoot = sut->mergeTrees(root1, root2);
    assertEq(newRoot);
}

TEST_F(MergeTwoBinaryTreesTest, testStackNullLeft)
{
    TreeNode* newRoot = sut->mergeTrees(NULL, root2);
    ASSERT_EQ(newRoot, root2);
}