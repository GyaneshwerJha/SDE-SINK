class Solution {
public:
  bool check(int mid, vector<int> &piles, int h){
        int n = piles.size();
        int currH = 0;
        for(int i = 0; i < n; i++){
            currH += (piles[i] + mid - 1) / mid; // Ceiling division
            if(currH > h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int k = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(check(mid, piles, h)){
                k = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return k;
    }
};