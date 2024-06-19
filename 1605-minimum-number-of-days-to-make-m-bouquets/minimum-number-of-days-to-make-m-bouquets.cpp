class Solution {
public:
    bool isFine(vector<int> allDay, int m, int k, int days){
        int n = allDay.size();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(allDay[i] <= days){
                cnt++;
            }
            else{
                cnt = 0;
            }

            if(cnt == k){
                m--;
                cnt = 0;
            }
        }


        return m <= 0;

    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // base case
        if(n < (long long)m * (long long)k) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;

            if(isFine(bloomDay, m, k, mid)){
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