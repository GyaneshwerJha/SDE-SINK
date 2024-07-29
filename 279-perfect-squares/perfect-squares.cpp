class Solution {
public:

    int solve(int current, int target, vector<vector<int>> &memo){
        if(target == 0) return 0;
        if(current <= 0) return INT_MAX;

        if(memo[current][target] != -1) return memo[current][target];

        int take = INT_MAX;
        if(current * current <= target){
            int result = solve(current, target - current * current, memo);
            if(result != INT_MAX){
                take = 1 + result;
            }
        }

        int notTake = solve(current - 1, target, memo);
        return memo[current][target] = min(take, notTake);
    }

    int numSquares(int n) {
        int tSqrt = sqrt(n);
        vector<vector<int>> memo(tSqrt + 1, vector<int> (n + 1, -1));

        int result = solve(tSqrt, n, memo);
        return result == INT_MAX ? -1 : result;
    }
};