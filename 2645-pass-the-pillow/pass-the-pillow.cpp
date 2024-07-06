class Solution {
public:
    int passThePillow(int n, int time) {
        int direction = 0;
        int pillowPos = 1;
        while(time > 0){
            if(direction == 0){
                time--;
                pillowPos++;
                if(pillowPos == n){
                    direction = 1;
                }
            }
            else{
                time--;
                pillowPos--;
                if(pillowPos == 1){
                    direction = 0;
                }
            }
        }

        return pillowPos;
    }
};