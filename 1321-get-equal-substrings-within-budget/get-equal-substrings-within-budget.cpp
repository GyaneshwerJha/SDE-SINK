class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length();
        
        vector<int> cost;
        for(int i = 0; i < len; i++){
            cost.push_back((int)(abs(s[i] - t[i])));
        }

        for(int i = 0; i < len; i++){
            cout<<cost[i]<< " ";
        }
        int gLen = 0;
        int i = 0, j = 0;

        int tempCost = 0;
        while(j < len){
            tempCost += cost[j];
            while(tempCost > maxCost){
                tempCost -= cost[i];
                i++;
            }
            
            if(tempCost <= maxCost){
                gLen = max(gLen, j - i + 1);
            }
            j++;
        }

        return gLen;
    }
};