class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 0;
        while(i < n){
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int maxi = intervals[i][1];
            while(i < n - 1 && maxi >= intervals[i + 1][0]){
                maxi = max(maxi, max(intervals[i][1], intervals[i + 1][1]));
                i++;
            }
            if(maxi != INT_MIN) temp.push_back(maxi);
            else temp.push_back(intervals[i][1]);
            ans.push_back(temp);
            i++;
        }

        return ans;

    }
};