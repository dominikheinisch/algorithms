#include <gtest/gtest.h>

#include "topKFrequentlyMentionedNotBannedKeywords.hpp"

struct TopKFrequentlyMentionedNotBannedKeywordsTest : public ::testing::Test {
    void SetUp() {}
    void TearDown() {}

    void assertSolution(const std::string& helpText, const std::vector<std::string>& wordsToExclude,
        const std::set<std::string>& solution)
    {
        auto result = retrieveMostFrequentlyUsedWords(helpText, wordsToExclude);
        std::set<std::string> orderedResult(result.begin(), result.end());
        ASSERT_TRUE(std::equal(orderedResult.begin(), orderedResult.end(), solution.begin()));
    }
};

TEST_F(TopKFrequentlyMentionedNotBannedKeywordsTest, testAllBanned) {
    std::string helpText = "foo bar";
    std::vector<std::string> wordsToExclude = {"foo", "bar"};
    std::set<std::string> solution = {};
    assertSolution(helpText, wordsToExclude, solution);
}

TEST_F(TopKFrequentlyMentionedNotBannedKeywordsTest, testBanMostFrequent) {
    std::string helpText = "foo foo bar";
    std::vector<std::string> wordsToExclude = {"foo"};
    std::set<std::string> solution = {"bar"};
    assertSolution(helpText, wordsToExclude, solution);
}

TEST_F(TopKFrequentlyMentionedNotBannedKeywordsTest, testOmmitNotLettersString) {
    std::string helpText = "A. . b";
    std::vector<std::string> wordsToExclude = {};
    std::set<std::string> solution = {"a", "b"};
    assertSolution(helpText, wordsToExclude, solution);
}

TEST_F(TopKFrequentlyMentionedNotBannedKeywordsTest, testFew) {
    std::string helpText = "Hey, my name is John. This is John's cat! There is a Cat's food.";
    std::vector<std::string> wordsToExclude = {"is", "a"};
    std::set<std::string> solution({"john", "cat", "s"});
    assertSolution(helpText, wordsToExclude, solution);
}
