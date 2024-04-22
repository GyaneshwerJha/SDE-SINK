class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string currLock = "0000";
        
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        if(st.find(currLock) != st.end()) return -1;
        if(currLock == target) return 0;

        queue<string> q;
        q.push(currLock);
        visited.insert(currLock);

        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string curr = q.front();
                q.pop();

                if(curr == target) return moves;
                if(st.count(curr)) continue;

                for(int j = 0; j < 4; j++){
                    char ch = curr[j];
                    string up = curr;
                    string down = curr;

                    up[j] = (up[j] == '9') ? '0' : up[j] + 1;
                    down[j] = (down[j] == '0') ? '9' : down[j] - 1;

                    if(!visited.count(up)){
                        visited.insert(up);
                        q.push(up);
                    }
                    if(!visited.count(down)){
                        visited.insert(down);
                        q.push(down);
                    }

                    curr[j] = ch;
                }
            }
            moves++;
        }


        return -1;


    }
};