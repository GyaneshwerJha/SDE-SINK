class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            pq.push({heights[i], i});
        }

        vector<string> ans;
        for(int i = 0; i < n; i++){
            auto it = pq.top();
            ans.push_back(names[it.second]);
            pq.pop();
        }

        return ans; 
    }
};