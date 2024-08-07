class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        if(len <= 8){
            return len;
        }

        int mini = 0;
        if(len > 8 && len <= 16){
            mini += 8 + (2 *  (len - 8));
        }
        else if(len > 16 && len <= 24){
            mini += 24 + (3 * (len - 16));
        }
        else{
            mini += 48 + (4 * (len - 24));
        }

        return mini;
    }
};