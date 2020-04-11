#include <gtest/gtest.h>

#include "topKFrequentKeywords/topKFrequent.hpp"

struct TopKFrequentTest : public ::testing::Test {
    void SetUp() {}
    void TearDown() {}
};

TEST_F(TopKFrequentTest, testFew)
{
    Solution sol;
    auto solved = sol.topKFrequent({"d", "aa", "a", "aa", "e", "a", "c", "d", "b"}, 4);
    std::vector<std::string> result = {"a", "aa", "d", "b"};
    ASSERT_EQ(result, solved);
}

TEST_F(TopKFrequentTest, testZeroK)
{
    Solution sol;
    auto solved = sol.topKFrequent({"d", "b"}, 0);
    std::vector<std::string> result = {};
    ASSERT_EQ(result, solved);
}

TEST_F(TopKFrequentTest, testAssertK)
{
    Solution sol;
    ASSERT_DEATH(sol.topKFrequent({"d", "b"}, 3),
        "Assertion `k <= occurencies.size.* failed");
}
