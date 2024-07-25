class Solution {
public:
    void heapify(long long index, int n, vector<int> &nums){
        long long left = 2 * index + 1;
        long long right = 2 * index + 2;
        int largest = index;

        if(left < n && nums[left] > nums[largest]) largest = left;
        if(right < n && nums[right] > nums[largest]) largest = right;
        if(largest != index){
            swap(nums[index], nums[largest]);
            heapify(largest, n, nums);
        }
        return;
    }

    void heapSort(vector<int> &nums){
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(i, n, nums);
        }

        while(n > 0){
            swap(nums[n - 1], nums[0]);
            n--;
            heapify(0, n, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};