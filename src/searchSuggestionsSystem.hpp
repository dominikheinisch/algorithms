#include <vector>
#include <set>
#include <string>

//static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();
class suggestedProductsSolution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(
        std::vector<std::string>& products, std::string searchWord)
    {
        std::vector<std::string> partialWords;
        for (int i=0; i < searchWord.size(); ++i) {
            partialWords.push_back(searchWord.substr(0, i+1));
        }
        std::set<std::string> sortedProducts;
        for (int i=0; i < products.size(); ++i) {
            if(products[i][0] == searchWord[0]) sortedProducts.insert(products[i]);
        }
        std::vector<std::vector<std::string>> result(searchWord.size(), std::vector<std::string>());
        for (int i=0; i < partialWords.size(); ++i) {
            for (auto it = sortedProducts.begin(); it != sortedProducts.end();) {
                if (it->size() < partialWords[i].size() ||
                   !std::equal(partialWords[i].begin(), partialWords[i].end(), it->begin()))
                {
                    auto temp = it++;
                    sortedProducts.erase(temp);
                } else {
                    result[i].push_back(*it);
                    ++it;
                    if(result[i].size() == 3) {
                        it = sortedProducts.end();
                    }
                }
            }
        }
        return result;
    }
};