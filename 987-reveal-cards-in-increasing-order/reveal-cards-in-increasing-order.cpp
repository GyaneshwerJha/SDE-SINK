class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        bool skip = false;
        vector<int> ans(n, 0);

        int i = 0;
        int j = 0;

        while(i < n){
            if(ans[j] == 0){
                if(skip == false){
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }

            j = (j + 1) % n;
        }
        return ans;
    }
};