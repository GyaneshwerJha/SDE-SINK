class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int cLen = c.size();
        set<pair<int, int>> st;
        for (auto& obs : o) {
            st.insert({obs[0], obs[1]});
        }

        int ans = 0;
        unordered_map<char, vector<int>> mp;
        mp['N'] = {0, 1};
        mp['E'] = {1, 0};
        mp['S'] = {0, -1};
        mp['W'] = {-1, 0};

        char dir = 'N';
        int x = 0, y = 0;
        for(int i = 0; i < cLen; i++){
            if(c[i] == -2){
                if(dir == 'N'){
                    dir = 'W';
                }
                else if(dir == 'W'){
                    dir = 'S';
                }
                else if(dir == 'S'){
                    dir = 'E';
                }
                else{
                    dir = 'N';
                }
            }
            else if(c[i] == -1){
                if(dir == 'N'){
                    dir = 'E';
                }
                else if(dir == 'W'){
                    dir = 'N';
                }
                else if(dir == 'S'){
                    dir = 'W';
                }
                else{
                    dir = 'S';
                }
            }
            else{
                int unit = c[i];
                for(int j = 0; j < unit; j++){

                    int newX = x + mp[dir][0];
                    int newY = y + mp[dir][1];

                    if(st.find({newX, newY}) != st.end()){
                        break;
                    }
                    
                    x = newX;
                    y = newY;
                    ans = max(ans, (x * x) + (y * y));
                }
            }
        }
        return ans;
    }
};