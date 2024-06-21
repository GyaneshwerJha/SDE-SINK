class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int i = 0, j = 0;
        int maxUnsatisfied = 0;
        int currUnsatisfied = 0;
        while(j < n){
            if(grumpy[j] == 1){
                currUnsatisfied += customers[j];
            }
            if(j - i + 1 == minutes){
                maxUnsatisfied = max(maxUnsatisfied, currUnsatisfied);
                if(grumpy[i] == 1){
                    currUnsatisfied -= customers[i];
                }
                i++;
            }
            j++;
        }
        cout<<maxUnsatisfied<<" ";

        int satisfied = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                satisfied += customers[i];
            }
        }
        return satisfied + maxUnsatisfied;
    }
};