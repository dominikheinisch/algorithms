#include <gtest/gtest.h>

#include <memory>

#include "rottingOranges/rottingOranges.hpp"

struct RottingOrangesTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<Solution>();
    }
    std::unique_ptr<Solution> sut;
};

TEST_F(RottingOrangesTest, test) {
    std::vector<std::vector<int>> grid(3, std::vector<int>(3));
    grid[0] = {2, 1, 1};
    grid[1] = {1, 1, 0};
    grid[2] = {0, 1, 1};
    ASSERT_EQ(sut->orangesRotting(grid), 4);
}