class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        
        reverse(digits.begin(), digits.end());
        digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};