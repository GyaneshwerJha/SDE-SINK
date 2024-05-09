class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        long long maxHappy = 0;
        int high = n - 1;
        int var = 0;
        sort(happiness.begin(), happiness.end());
        while(k > 0 && high >= 0){
            if(happiness[high] - var <= 0){
                k--;
                high--;
                continue;
            }
            else{
                maxHappy += happiness[high] - var;
                var++;
            }
            k--;
            high--;
        }
        return maxHappy;
    }
};