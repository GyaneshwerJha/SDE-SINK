class Solution {
public:
    int memo[1001][1001];
    int solve(int ind, int currHeight, int n, vector<vector<int>> &books, int shelfWidth, int remainingWidth) {
        if (ind == n) return currHeight;

        if(memo[ind][remainingWidth] != -1) return memo[ind][remainingWidth];
        // Take
        int take = INT_MAX;
        if (books[ind][0] <= remainingWidth) {
            take = solve(ind + 1, max(currHeight, books[ind][1]), n, books, shelfWidth, remainingWidth - books[ind][0]);
        }

        // not Take
        int notTake = currHeight + solve(ind + 1, books[ind][1], n, books, shelfWidth, shelfWidth - books[ind][0]);

        return memo[ind][remainingWidth] = min(take, notTake);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, n, books, shelfWidth, shelfWidth);
    }
};