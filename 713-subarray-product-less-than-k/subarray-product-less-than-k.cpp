class Solution {
public:
    int brute(vector<int>& nums, int k){
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            long long int prod = 1;
            for(int j = i; j < n; j++){
                if(prod > k / nums[j]) break;
                prod *= nums[j];
                if(prod < k){
                    count++;
                }
            }
        }

        return count;
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        int product = 1;
        int count = 0;
        while(j < n){
            product *= nums[j];
            while(i <= j && product >= k){
                product = product / nums[i];
                i++;
            }
            count += j - i + 1;
            cout<<count<< " " << j - i + 1 << endl;
            j++;
        }

        return count;
    }
};