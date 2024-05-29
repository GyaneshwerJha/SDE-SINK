class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = 1;
        }
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i] - 1) == mp.end()){
                int tempLen = 0;
                int tempEle = nums[i];
                while(mp.find(tempEle) != mp.end()){
                    tempLen += 1;
                    tempEle += 1;
                }
                maxLen = max(maxLen, tempLen);
            }
        }

        return maxLen;
    }
};