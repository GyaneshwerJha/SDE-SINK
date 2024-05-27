class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majEle = -1;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                majEle = nums[i];
            }
            else if(nums[i] == majEle){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return majEle;
    }
};