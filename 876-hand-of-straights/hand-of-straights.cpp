class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n == 1 && k == 1) return true;
        if(n % k != 0) return false;
        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[hand[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(mp.find(hand[i]) != mp.end()){
                for(int j = 0; j < k; j++){
                    if(mp.find(hand[i] + j) == mp.end()){
                        return false;
                    }
                    else{
                        mp[hand[i] + j]--;
                        if(mp[hand[i] + j] == 0){
                            mp.erase(hand[i] + j);
                        }
                    } 
                }
            }
        }

        return true;

    }
};