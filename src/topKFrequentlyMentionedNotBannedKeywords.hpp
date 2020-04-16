#include <cctype>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void handleWord(const std::unordered_set<std::string>& toExclude, const std::string& word,
    std::unordered_map<std::string, int>& wordToOccurencies, int& maxOccur)
{
    auto excludeIt = toExclude.find(word);
    if (excludeIt != toExclude.end()) {
        return;
    }
    auto it = wordToOccurencies.find(word);
    if (it == wordToOccurencies.end()) {
        wordToOccurencies.insert({word, 1});
        maxOccur = std::max(maxOccur, 1);
    } else {
        it->second += 1;
        maxOccur = std::max(maxOccur, it->second);
    }
}

std::vector<std::string> retrieveMostFrequentlyUsedWords(const std::string& helpText,
    const std::vector<std::string>& wordsToExclude)
{
    std::unordered_set<std::string> toExclude(wordsToExclude.begin(), wordsToExclude.end());
    std::unordered_map<std::string, int> wordToOccurencies;
    std::stringstream sstream;
    int currBeg = 0;
    int maxOccur = -1;
    for (int i = 0; i < helpText.size(); ++i) {
        bool isOkChar = std::isalpha(helpText[i]) != 0;
        if (isOkChar) {
            sstream << static_cast<char>(std::tolower(helpText[i]));
        }
        if (!isOkChar || i == helpText.size() - 1) {
            auto currStr = sstream.str();
            sstream = std::stringstream();
            currBeg = i + 1;
            if (currStr.size()) {
                handleWord(toExclude, currStr, wordToOccurencies, maxOccur);
            }
        }
    }
    std::vector<std::string> res;
    for (const auto& elem : wordToOccurencies) {
        std::cout << "|" << elem.first << "|" << " " << elem.second << "\n";
        if (elem.second == maxOccur) {
            res.push_back(elem.first);
        }
    }
    return res;
}