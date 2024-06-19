class Solution {
public:
    bool isFine(vector<int> &weights, int days, int total){
        int totalDays = 1;
        int capacity = 0;

        for(int i = 0; i < weights.size(); i++){
            capacity += weights[i];

            if(capacity > total){
                totalDays++;
                capacity = weights[i];
            }

            if(totalDays > days) return false;
        }

        return totalDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isFine(weights, days, mid)){
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