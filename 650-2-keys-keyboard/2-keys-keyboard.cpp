class Solution {
public:
    int solve(int curr, int n, int prev_copy){
        if(curr == n) return 0;
        if(curr > n) return INT_MAX;

        // copy
        int copy = INT_MAX;
        if (prev_copy != curr) {  
            int temp = solve(curr, n, curr);
            if (temp != INT_MAX) {
                copy = 1 + temp;
            }
        }

        // paste
        int paste = INT_MAX;
        if(prev_copy > 0 && curr + prev_copy <= n){
            int temp = solve(curr + prev_copy, n, prev_copy);
            if (temp != INT_MAX) {
                paste = 1 + temp;
            }
        }

        return min(copy, paste);
    }

    int minSteps(int n) {
        if(n == 1) return 0;  // No steps needed if n is 1
        return solve(1, n, 0);
    }
};
