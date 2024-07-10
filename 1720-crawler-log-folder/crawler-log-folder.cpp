class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int size = logs[i].size();
            if(size >= 3 && logs[i][size - 1] == '/' && logs[i][size - 2] == '.' && logs[i][size - 3] == '.'){
                if(i == 0){
                    continue;
                }

                cnt--;
                if(cnt < 0){
                    cnt = 0;
                }
            }
            else if(size >= 2 && logs[i][size - 1] == '/' && logs[i][size - 2] == '.'){
                continue;
            }
            else{
                if(cnt >= 0){
                    cnt++;
                }
            }
        }

        return cnt < 0 ? 0 : cnt;
    }
};