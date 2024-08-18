class Solution {
public:
    int div(int mid, vector<int> &nums){
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++){
            // cout<<nums[i]<<" "<<nums[mid]<< " " << nums[i] / nums[mid]<<endl;
            sum += (nums[i] + mid - 1) / mid;
        }
        cout<<endl<<endl;
        return sum;
    }



    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // 1 11 22 33 44

        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            // cout<<mid<<endl;
            if(div(mid, nums) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};