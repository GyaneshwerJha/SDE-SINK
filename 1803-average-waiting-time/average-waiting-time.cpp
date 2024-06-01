class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int totalCustomer = customers.size();
        double waitingTime = 0.0;
        int totalTimeTake = 0;
        for(int i = 0; i < totalCustomer; i++){
            if(i == 0){
                waitingTime = customers[0][1];
                totalTimeTake = customers[0][1] + customers[0][0];
                // cout<<waitingTime<<" ";
                cout<<totalTimeTake<<" ";

            }
            else{
                if(totalTimeTake > customers[i][0]){
                    totalTimeTake += customers[i][1];
                    waitingTime += totalTimeTake - customers[i][0];
                }
                else{
                    waitingTime += customers[i][1];
                    totalTimeTake = customers[i][0] + customers[i][1];
                }
            }
        }

        return waitingTime / totalCustomer;
    }
};