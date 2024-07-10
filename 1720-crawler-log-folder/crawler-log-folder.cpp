class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int size = logs[i].size();
            if(logs[i] == "../"){
                if(i == 0){
                    continue;
                }

                cnt--;
                if(cnt < 0){
                    cnt = 0;
                }
            }
            else if(logs[i] == "./"){
                continue;
            }
            else{
                cnt++;
            }
        }

        return cnt < 0 ? 0 : cnt;
    }
};