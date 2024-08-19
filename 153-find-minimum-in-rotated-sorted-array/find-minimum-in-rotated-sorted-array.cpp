class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // left half sorted
            if(nums[low] <= nums[mid]){
                cout<<nums[low]<<" "<<nums[mid]<<endl;
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                cout<<nums[mid]<<" "<<nums[high]<<endl;
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};