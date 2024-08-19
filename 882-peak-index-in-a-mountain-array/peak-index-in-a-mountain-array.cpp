class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
         int n = nums.size();

        int low = 0, high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if((mid > 0 && mid + 1 < n) && (nums[mid + 1] < nums[mid] && nums[mid - 1] < nums[mid])){
                return mid;
            }

            if(mid + 1 < n && nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};