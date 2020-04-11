#include <gtest/gtest.h>

#include "setMismatch/setMismatch.hpp"

struct SetMismatchTest : public ::testing::Test {
    void SetUp() {}
    void TearDown() {}
};

TEST_F(SetMismatchTest, testFew)
{
    Solution sol;
    auto solved = sol.findErrorNums({1, 2, 2, 4});
    std::vector<int> result = {2, 3};
    ASSERT_EQ(result, solved);
}


TEST_F(SetMismatchTest, testNotSorted)
{
    Solution sol;
    auto solved = sol.findErrorNums({5, 3, 1, 2, 4, 5});
    std::vector<int> result = {5, 6};
    ASSERT_EQ(result, solved);
}