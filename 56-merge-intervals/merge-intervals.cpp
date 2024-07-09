class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(int i = 0; i < size; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(i + 1 < size && e >= intervals[i + 1][0]){
                while(i + 1 < size && e >= intervals[i + 1][0]){
                    e = max(e, intervals[i + 1][1]);
                    i++;
                }
            }
            ans.push_back({s, e});
        }

        return ans;
    }
};