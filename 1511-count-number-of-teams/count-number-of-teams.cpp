class Solution {
public:
    // const int k = 3;
    int dp[1001][1001][4];
    int solve(int ind, int prev , int cnt, int n, vector<int> &rating){
        // base case
        if(cnt == 3){
            return 1;
        }
        if(ind >= n){
            return 0;
        }

        if(dp[ind][prev + 1][cnt] != -1) return dp[ind][prev + 1][cnt];

        int take = 0;
        if(prev == -1 || rating[prev] < rating[ind]){
            take = solve(ind + 1, ind, cnt + 1, n, rating);
        }

        int notTake = solve(ind + 1, prev, cnt, n, rating);
        return dp[ind][prev + 1][cnt] = take + notTake;

    }

    int numTeams(vector<int>& rating) {
        memset(dp, -1, sizeof(dp));
        int n = rating.size();
        int ind = 0;
        int prev = -1;
        int cnt = 0;
        int incre = solve(ind, prev, cnt, n, rating);
        reverse(rating.begin(), rating.end());
        memset(dp, -1, sizeof(dp));
        int decre = solve(ind, prev, cnt, n, rating);

        return incre + decre;
    }
};