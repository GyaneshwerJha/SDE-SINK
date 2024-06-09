class Solution {
public:
    int numberOfChild(int n, int k) {
        int direction = 0;
        int j = 0;

        for(int i = 0; i < k; i++){

            if(direction == 0){
                j++;
            }
            else{
                j--;
            }
            if(j == n - 1){
                direction = 1;
            }
            if(j == 0){
                direction = 0;
            }

            
        }

        return j;
    }
};