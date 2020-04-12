#include <gtest/gtest.h>

#include <memory>

#include "findTheDuplicateNumber/findTheDuplicateNumber.hpp"

struct FindTheDuplicateNumberTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<Solution>();
    }
    std::unique_ptr<Solution> sut;
};

TEST_F(FindTheDuplicateNumberTest, testFew) {
    std::vector<int> nums = {4, 2, 2, 1};
    auto nums_cpy = nums;
    ASSERT_EQ(2, sut->findDuplicate(nums));
    ASSERT_EQ(nums_cpy, nums);
}

TEST_F(FindTheDuplicateNumberTest, testFew2) {
    std::vector<int> nums = {2,1,5,3,6,4,3};
    auto nums_cpy = nums;
    ASSERT_EQ(3, sut->findDuplicate(nums));
    ASSERT_EQ(nums_cpy, nums);
}

TEST_F(FindTheDuplicateNumberTest, testFew3) {
    std::vector<int> nums = {1,3,4,2,2};
    auto nums_cpy = nums;
    ASSERT_EQ(2, sut->findDuplicate(nums));
    ASSERT_EQ(nums_cpy, nums);
}

TEST_F(FindTheDuplicateNumberTest, testFew4) {
    std::vector<int> nums = {2,3,4,2,2};
    auto nums_cpy = nums;
    ASSERT_EQ(2, sut->findDuplicate(nums));
    ASSERT_EQ(nums_cpy, nums);
}