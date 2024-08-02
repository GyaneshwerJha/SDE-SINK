#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cntOne = accumulate(nums.begin(), nums.end(), 0);

        int tempOne = 0;
        for (int i = 0; i < cntOne; i++) {
            if (nums[i] == 1) {
                tempOne++;
            }
        }

        int mini = cntOne - tempOne;

        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        
        for(int i = cntOne; i < (n + cntOne); i++){
            mini = min(mini, cntOne - tempOne);
            tempOne += nums[i];
            tempOne -= nums[i - cntOne];
        }

        return mini;
    }
};
