#include <gtest/gtest.h>

#include <memory>

#include "insertDeleteGetRandomO1/insertDeleteGetRandomO1.hpp"

struct InsertDeleteGetRandomO1Test : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<RandomizedSet>();
    }
    std::unique_ptr<RandomizedSet> sut;
};

TEST_F(InsertDeleteGetRandomO1Test, test) {
    ASSERT_TRUE(sut->insert(3));
    ASSERT_FALSE(sut->insert(3));
    ASSERT_EQ(sut->getRandom(), 3);
    ASSERT_EQ(sut->getRandom(), 3);
    ASSERT_TRUE(sut->insert(1));
    ASSERT_FALSE(sut->insert(3));
    auto random = sut->getRandom();
    ASSERT_TRUE(random == 1 || random == 3);
    random = sut->getRandom();
    ASSERT_TRUE(random == 1 || random == 3);
    ASSERT_TRUE(sut->insert(0));
    ASSERT_TRUE(sut->remove(0));
}