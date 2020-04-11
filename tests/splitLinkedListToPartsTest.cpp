#include <gtest/gtest.h>

#include "splitLinkedListToParts/splitLinkedListToParts.hpp"

struct SplitLinkedListToPartsTest : public ::testing::Test {
    void SetUp() {}
    void TearDown() {}
};

TEST_F(SplitLinkedListToPartsTest, testNull)
{
    Solution sol;
    auto solved = sol.splitListToParts(NULL, 3);
    std::vector<ListNode*> result = {NULL, NULL, NULL};
    ASSERT_EQ(result, solved);
}

TEST_F(SplitLinkedListToPartsTest, testPartialNull)
{
    Solution sol;
    ListNode l1(1);
    ListNode l2(2);
    l1.next = &l2;
    auto solved = sol.splitListToParts(&l1, 3);
    std::vector<ListNode*> result = {&l1, &l2, NULL};
    ASSERT_EQ(result, solved);
    ASSERT_TRUE(l1.next == NULL);
    ASSERT_TRUE(l2.next == NULL);
}

TEST_F(SplitLinkedListToPartsTest, testFew)
{
    Solution sol;
    std::vector<ListNode> temp;
    std::vector<int> values = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    temp.reserve(values.size()+1);
    temp.push_back(ListNode(1));
    auto iter = &(temp.front());
    for (const auto& elem : values) {
        temp.push_back(ListNode(elem));
        iter->next = &temp.back();
        iter = iter->next;
    }
    auto solved = sol.splitListToParts(&(temp.front()), 3);
    std::vector<ListNode*> result = {&temp[0], &temp[4], &temp[7]};
    ASSERT_EQ(result, solved);
    ASSERT_TRUE(temp[0].next->next->next->next == NULL);
    ASSERT_TRUE(temp[4].next->next->next == NULL);
    ASSERT_TRUE(temp[7].next->next->next == NULL);
}