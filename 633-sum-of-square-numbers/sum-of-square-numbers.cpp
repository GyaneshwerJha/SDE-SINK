class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long> v;
        for(long long i = 0; i * i <= c; i++){
            v.push_back(i * i);
        }

        int n = v.size();
        int i = 0;
        int j = n - 1;
        while(i <= j){
            long long sum = v[i] + v[j];
            if(sum == c) return true;
            else if(sum > c){
                j--;
            }
            else{
                i++;
            }
        }
    
        return false;
    }
};