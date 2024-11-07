class Solution {
public:
    int largestCombination(vector<int>& c) {
        int n = c.size();
        int max_cnt = INT_MIN;

        for(int i = 0; i < 32; i++){
            int temp_cnt = 0;
            for(int &num : c){
                if(num & (1 << i)){
                    temp_cnt++;
                }
            }
            max_cnt = max(max_cnt, temp_cnt);
        }

        return max_cnt;
    }
};
