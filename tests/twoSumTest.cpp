#include <gtest/gtest.h>

#include "twoSum/twoSum.hpp"

struct TwoSumTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<Solution>();
    }

    std::unique_ptr<Solution> sut;
};

TEST_F(TwoSumTest, testSorted) {
    std::vector<int> input = {2, 7, 11, 15};
    auto solved = sut->twoSum(input, 9);
    std::vector<int> result = {0, 1};
    ASSERT_EQ(result, solved);
}

TEST_F(TwoSumTest, testUnordered) {
    std::vector<int> input = {7, 11, 15, 2};
    auto solved = sut->twoSum(input, 9);
    std::vector<int> result = {0, 3};
    ASSERT_EQ(result, solved);
}

TEST_F(TwoSumTest, testWrongInput) {
    std::vector<int> input = {2, 7, 11, 15};
    auto solved = sut->twoSum(input, 14);
    std::vector<int> result = {-1, -1};
    ASSERT_EQ(result, solved);
}

TEST_F(TwoSumTest, testTwiceSameElem) {
    std::vector<int> input = {2, 7, 11, 7};
    auto solved = sut->twoSum(input, 14);
    std::vector<int> result = {1, 3};
    ASSERT_EQ(result, solved);
}
