class Solution {
public:

    int solve(int ind, int n, vector<int> &days, vector<int> &costs, vector<int> &memo){
        if(ind >= n) return 0;

        if(memo[ind] != -1) return memo[ind];

        // one day
        int from1 = costs[0] + solve(ind + 1, n, days, costs, memo);
        
        // 7days
        int i;
        for(i = ind; i < n && days[i] < days[ind] + 7; i++);
        int from7 = costs[1] + solve(i, n, days, costs, memo);

        // 30 days
        for(i = ind; i < n && days[i] < days[ind] + 30; i++);
        int from30 = costs[2] + solve(i, n, days, costs, memo);

        return memo[ind] = min(from1, min(from7, from30));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> memo(n + 1, -1);
        return solve(0, n, days, costs, memo);
    }
};