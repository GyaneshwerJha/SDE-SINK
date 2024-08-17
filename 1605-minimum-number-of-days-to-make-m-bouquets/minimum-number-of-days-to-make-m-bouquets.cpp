class Solution {
public:
    bool check(int mid, int k, int m, vector<int> &bloomDay){
        int cnt = 0;
        int n = bloomDay.size();
        int size = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                size += 1;
            }
            else{
                size = 0;
            }

            if(size == k){
                size = 0;
                cnt++;
                if(cnt == m) return true;
            }
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n / k < m) return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0; i < n; i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(mid, k, m, bloomDay)){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
        
    }
};