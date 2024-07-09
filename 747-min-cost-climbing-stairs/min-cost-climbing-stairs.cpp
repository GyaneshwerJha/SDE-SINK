class Solution {
public:
    int solve(int ind, int n, vector<int> &cost, vector<int> &memo){
        // base case
        if(ind >= n) return 0;
        
        if(memo[ind] != -1) return memo[ind];
        int step1 = cost[ind] + solve(ind + 1, n, cost, memo);
        int step2 = ind + 1 < n ? cost[ind + 1] + solve(ind + 2, n, cost, memo) : 0;

        return memo[ind] = min(step1, step2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ind = 0;
        vector<int> memo(n, -1);
        int minCost = solve(ind, n, cost, memo);
        return minCost;
    }
};