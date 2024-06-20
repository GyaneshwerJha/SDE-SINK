class Solution {
public:
    bool isFine(vector<int> &nums, int k, int n, int pages){
        int reqStudent = 1;
        int currPages = 0;

        for(int i = 0; i < n; i++){
            currPages += nums[i];
            if(currPages > pages){
                currPages = nums[i];
                reqStudent += 1;
                if(reqStudent > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = INT_MIN;
        int high = 0;

        for(int i = 0; i < n; i++){
            low = max(low, nums[i]);
            high += nums[i];
        }

        int mini = INT_MAX;

        while(low <= high){
            int mid = (low + high) / 2;
            if(isFine(nums, k, n, mid)){
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