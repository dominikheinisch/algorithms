#include <gtest/gtest.h>

#include <memory>

#include "zombieInMatrix/zombieInMatrix.hpp"

struct ZombieInMatrixTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<Solution>();
    }
    std::unique_ptr<Solution> sut;
};

TEST_F(ZombieInMatrixTest, test1) {
    std::vector<std::vector<int>> grid(3, std::vector<int>(3));
    grid[0] = {1, 1, 1};
    grid[1] = {1, 1, 0};
    grid[2] = {0, 1, 1};
    ASSERT_EQ(sut->zombiesAttacking(grid), 1);
}

TEST_F(ZombieInMatrixTest, test2) {
    std::vector<std::vector<int>> grid(4, std::vector<int>(5));
    grid[0] = {0, 1, 1, 0, 1};
    grid[1] = {0, 1, 0, 1, 0};
    grid[2] = {0, 0, 0, 0, 1};
    grid[3] = {0, 1, 0, 0, 0};
    ASSERT_EQ(sut->zombiesAttacking(grid), 2);
}

TEST_F(ZombieInMatrixTest, test3) {
    std::vector<std::vector<int>> grid(6, std::vector<int>(1));
    grid[0] = {0};
    grid[1] = {1};
    grid[2] = {0};
    grid[3] = {0};
    grid[4] = {0};
    grid[5] = {0};
    ASSERT_EQ(sut->zombiesAttacking(grid), 4);
}