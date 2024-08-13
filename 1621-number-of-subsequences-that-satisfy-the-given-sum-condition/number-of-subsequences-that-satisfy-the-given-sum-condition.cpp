#include <vector>
#include <algorithm>

class Solution {
public:
    const long long mod = 1e9 + 7;
    
    // Modular exponentiation function
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If exp is odd, multiply base with result
                result = (result * base) % mod;
            }
            base = (base * base) % mod;  // Square the base
            exp /= 2;  // Divide exp by 2
        }
        return result;
    }
    
    int numSubseq(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        long long cnt = 0;
        
        while (i <= j) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--;
            } else {
                long long p = modExp(2, j - i, mod);
                cnt = (cnt + p) % mod;
                i++;
            }
        }
        return cnt % mod;
    }
};
