class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        int empty = 0;

        while(numBottles > 0){
            cnt += numBottles;
            empty += numBottles;

            if(empty < numExchange){
                break;
            }
            numBottles = empty / numExchange;
            empty -= (numBottles * numExchange);
        }
    

        return cnt;
    }
};