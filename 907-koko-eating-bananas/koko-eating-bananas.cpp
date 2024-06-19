class Solution {
public:
   bool isFine(int mid, vector<int> &piles, int h){
        int n = piles.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int div = piles[i] / mid;
            cnt += div;

            if(piles[i] % mid != 0) cnt++;

            if(cnt > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        if(h < n) return -1;

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mini = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isFine(mid, piles, h)){
                mini = min(mini, mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return mini;
    }
};