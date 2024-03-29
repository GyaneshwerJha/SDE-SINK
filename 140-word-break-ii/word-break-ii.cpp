#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void wordBreakHelper(int start, string &s, unordered_set<string> &wordDict, string &current, vector<string> &result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            string word = s.substr(start, end - start + 1);
            if (wordDict.find(word) != wordDict.end()) {
                string temp = current.empty() ? word : current + " " + word;
                wordBreakHelper(end + 1, s, wordDict, temp, result);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        string current;
        wordBreakHelper(0, s, wordDictSet, current, result);
        return result;
    }
};
