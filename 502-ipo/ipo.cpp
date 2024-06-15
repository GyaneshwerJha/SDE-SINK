class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end());

        priority_queue<pair<int, int>> q;
        int i = 0;
        while(k--){
            while(i < n && v[i].first <= w){
                q.push({v[i].second, v[i].first});
                i++;
            }

            if(q.empty()) break;

            w += q.top().first;
            q.pop();
        }
        
        return w;

    }
};