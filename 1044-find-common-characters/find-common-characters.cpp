class Solution {
public:
vector<string> constructVectorFromFrequencies(const vector<int>& freq) {
    vector<string> result;

    for (int i = 0; i < freq.size(); ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            result.push_back(string(1, 'a' + i));
        }
    }

    return result;
}

    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        int m = words[0].length();

        vector<int> arr(26, 0);
        string s = words[0];
        for(int i = 0; i < m; i++){
            arr[s[i] - 'a']++;
        }


        for(int i = 0; i < n; i++){
            string st = words[i];
            vector<int> temp(26, 0);
            for(int i = 0; i < st.length(); i++){
                temp[st[i] - 'a']++;
            }

            for(int i = 0; i < 26; i++){
                arr[i] = min(arr[i], temp[i]);
            }
        }

        vector<string> ans = constructVectorFromFrequencies(arr);
        return ans;

    }
};