class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        if(st.count(endWord) == 0) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        int maxi = 0;
        while(!q.empty()){
            auto it = q.front();
            string word = it.first;
            int numWord = it.second;
            
            if(word == endWord) return numWord;
            q.pop();
            int len = word.size();
            for(int i = 0; i < len; i++){
                char originalWord = word[i];
                for(char a = 'a'; a <= 'z'; a++){
                    word[i] = a;
                    if(st.count(word)){
                        q.push({word, numWord + 1});
                        st.erase(word);
                    }
                }
                word[i] = originalWord;
            }
        }

        return maxi;
    }
};