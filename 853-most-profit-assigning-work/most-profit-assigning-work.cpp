class Solution {
public:
    int binarySearch(int target, vector<pair<int, int>> &v){
        int n = v.size();

        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(v[i].first <=  target){
                maxi = max(maxi, v[i].second);
            }
        }
        return maxi;
    }


// 35 47 52 68 86
// 17 81 1 67 3
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int maxProfit = 0;

        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({difficulty[i], profit[i]});
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < worker.size(); i++){
            int findIndex = binarySearch(worker[i], v);
            if(findIndex != INT_MIN){
                maxProfit += findIndex;
            }
        }

        return maxProfit;

    }
};