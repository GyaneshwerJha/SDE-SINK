class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                for(int j = 0; j < k; j++){
                    if(mp.find(nums[i] + j) == mp.end()){
                        return false;
                    }
                    else{
                        mp[nums[i] + j]--;
                        if(mp[nums[i] + j] == 0){
                            mp.erase(nums[i] + j);
                        }
                    }
                }
            }
        }

        return true;
    }
};