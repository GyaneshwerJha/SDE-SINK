class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == key){
                mp[nums[i + 1]]++;
            }
        }

        int maxi = -1;
        int ele = -1;


         for (const auto& it : mp) {
            if (it.second > maxi) {
                maxi = it.second;
                ele = it.first;
            }
        }
        return ele;
    }
};