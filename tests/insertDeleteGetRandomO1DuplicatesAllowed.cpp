#include <gtest/gtest.h>

#include <memory>

#include "insertDeleteGetRandomO1DuplicatesAllowed/insertDeleteGetRandomO1DuplicatesAllowed.hpp"

struct InsertDeleteGetRandomO1DuplicatesAllowedTest : public ::testing::Test {
    void SetUp() {
        sut = std::make_unique<RandomizedCollection>();
    }
    std::unique_ptr<RandomizedCollection> sut;
};

TEST_F(InsertDeleteGetRandomO1DuplicatesAllowedTest, test) {
// ["RandomizedCollection","insert","insert","insert","insert","insert","insert","remove","remove","remove","remove","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom","getRandom"]
// [[],[10],[10],[20],[20],[30],[30],[10],[10],[30],[30],[],[],[],[],[],[],[],[],[],[]]

    ASSERT_TRUE(sut->insert(10));
    ASSERT_FALSE(sut->insert(10));
    ASSERT_TRUE(sut->insert(20));
    ASSERT_FALSE(sut->insert(20));
    ASSERT_TRUE(sut->insert(30));
    ASSERT_FALSE(sut->insert(30));
    ASSERT_TRUE(sut->remove(10));
    ASSERT_TRUE(sut->remove(10));
    ASSERT_TRUE(sut->remove(30));
    ASSERT_TRUE(sut->remove(30));
    ASSERT_FALSE(sut->remove(10));
    ASSERT_FALSE(sut->remove(30));
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
    ASSERT_EQ(sut->getRandom(), 20);
}