class Solution {
public:
    // int memo[1001][1001];
    unordered_map<string, int> mp;

    int solve(int ind, int currHeight, int n, vector<vector<int>> &books, int shelfWidth, int remainingWidth) {
        if (ind == n) return currHeight;

        string key = to_string(ind) + "_" + to_string(currHeight) + "_" + to_string(remainingWidth);
        if(mp.find(key) != mp.end()) return mp[key];
        // Take
        int take = INT_MAX;
        if (books[ind][0] <= remainingWidth) {
            take = solve(ind + 1, max(currHeight, books[ind][1]), n, books, shelfWidth, remainingWidth - books[ind][0]);
        }

        // not Take
        int notTake = currHeight + solve(ind + 1, books[ind][1], n, books, shelfWidth, shelfWidth - books[ind][0]);

        return mp[key] = min(take, notTake);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        return solve(0, 0, n, books, shelfWidth, shelfWidth);
    }
};