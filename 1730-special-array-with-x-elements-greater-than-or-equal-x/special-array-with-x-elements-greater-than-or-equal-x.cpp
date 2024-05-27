class Solution {
public:
    int binarySearch(int low, int high, vector<int> &nums, int target){
        low = 0;
        high = nums.size() - 1;
        int result = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        cout<<result<<" ";
        return nums.size() - result; 
    }

    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = n;
        while(low <= high){
            int target = low;
            if(binarySearch(low, high, nums, target) == low){
                return low;
            }
            low++;
        }
        return -1;
    }
};