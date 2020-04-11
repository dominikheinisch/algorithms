/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int acc = 0;
        auto iter = root;
        while (iter != NULL) {
            ++acc;
            iter = iter->next;
        }
        int partLen = acc / k;
        int mod = acc % k;

        std::vector<ListNode*> result;
        result.reserve(k);
        auto curr = root;
        auto prev = root;
        if (partLen == 0) {
            for (int i=0; i<mod; ++i) {
                result.push_back(curr);
                curr = curr->next;
                prev->next = NULL;
                prev = curr;
            }
            for (int i=0; i<k-mod; ++i) {
                result.push_back(NULL);
            }
            return result;
        } else {
            for (int i=0; i<k; ++i) {
                int currLen = partLen + (1 ? mod > 0 : 0);
                --mod;
                result.push_back(curr);
                for (int j=0; j<=currLen-1; ++j) {
                    if (j == currLen-1) {
                        prev = curr;
                    }
                    curr = curr->next;
                }
                prev->next = NULL;
            }
        return result;
        }
    }
};