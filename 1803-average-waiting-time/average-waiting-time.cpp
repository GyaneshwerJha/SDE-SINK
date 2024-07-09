class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int size = customers.size();
        
        double tWait = 0;
        int currTime = customers[0][0];

        for(int i = 0; i < size; i++){
            int arrival = customers[i][0];
            int cooking = customers[i][1];
            
                if(customers[i][0] <= currTime){
                    tWait += (currTime + cooking - arrival);
                    cout<<currTime + cooking - arrival<<" ";
                    currTime += cooking;
                }
                else{
                    tWait += customers[i][1];
                    cout<<customers[i][1];
                    currTime = customers[i][0] + customers[i][1];
                }
            
        }
        
        return tWait / size;
        
        
    }
};