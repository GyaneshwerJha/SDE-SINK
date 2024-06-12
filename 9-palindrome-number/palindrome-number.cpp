class Solution {
public:

    bool isPalindrome(int x) {
        if(x < 0) return false;
        int a = x;
        long long int rev = 0;
        while(x > 0){
            rev = rev * 10 + (x % 10);
            x = x / 10;
        }   

        cout<<rev;
        if(rev == a) return true;
        return false;
    }
};