class Solution {
public:
    int findFirstPos(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int firstPos = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                firstPos = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return firstPos;
    }

    int findLastPos(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int lastPos = -1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                lastPos = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return lastPos;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = findFirstPos(nums, target);
        int lastPos = findLastPos(nums, target);
        cout<<lastPos;
        return {firstPos, lastPos};
    }
};