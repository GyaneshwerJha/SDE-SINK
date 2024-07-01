class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int oddCnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] % 2 != 0){
                oddCnt++;
                if(oddCnt == 3){
                    return true;
                }
            }
            else{
                oddCnt = 0;
            }
        }

        return false;
    }
};