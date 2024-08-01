class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string ageS = details[i].substr(11, 2);
            int age = stoi(ageS);
            if(age > 60){
                cnt++;
            }
        }

        return cnt;
    }
};