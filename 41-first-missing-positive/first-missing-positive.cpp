class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int minEle = 1;
        int maxEle = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        bool flag = false;
        int missingNumber;
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                flag = true;
                cout<<flag<<endl;
                missingNumber = i;
                break;
            }
        }

        cout<<flag<<endl;
        if(flag == false){
            maxEle = max(0, maxEle);
            missingNumber = maxEle + 1;
        }

        return missingNumber;  
    }
};