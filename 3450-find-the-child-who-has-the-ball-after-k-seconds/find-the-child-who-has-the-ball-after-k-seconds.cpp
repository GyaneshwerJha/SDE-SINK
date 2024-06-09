class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int numRound = k / n;
        int rem = k % n;

        // after round if it is left side means even
        // if round is even means it is on the left side
        if(numRound % 2 == 0){
            return rem;
        }
        else{
            return n - rem;
        }
        
    }
};